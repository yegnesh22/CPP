#include <bits/stdc++.h>

using namespace std;

#define MAX_QSIZE	64
#define RATE_LIMIT_SIZE	4
#define WRITE_SIZE	4
#define READ_SIZE	2
#define PACKET_SIZE	4

bool wr = false;
bool rd = false;

long long tbytes = 0;

condition_variable cvr;
bool readDone = false;
bool readReady = false;
mutex readLock;

condition_variable cvw;
bool writeDone = false;
bool writeReady = false;
mutex writeLock;

condition_variable cvrl;
bool rateLReady = false;
bool rateLDone = false;
mutex rateLock;

bool complete = false;
bool wcomplete = false;
bool rcomplete = false;


queue<unsigned char> dataQ;

void EventThread() {
	unsigned char event;

	while (!wcomplete || !rcomplete) {
		cout << "Event (r/w):" << flush;
		cin >> event;
		if (event == 'w' && !wcomplete) {
			{
				lock_guard<mutex> lkwg(writeLock);
				writeReady = true;
				cout << __func__ << " signalling producer!!"  << endl;
			}
			cvw.notify_one();
			{
				unique_lock lkw(writeLock);
				cout << __func__ << " waiting for producer to finish!!" << endl;
				cvw.wait(lkw, []{return writeDone;});
				writeDone = false;
			}
			cout << __func__ << " resuming after producer!!" << endl;
		} else if (event == 'r' && !rcomplete) {
			{
				lock_guard<mutex> lkrg(readLock);
				readReady = true;
				cout << __func__ << " signalling consumer!!"  << endl;
			}
			cvr.notify_one(); 
			{
				unique_lock lkr(readLock);
				cout << __func__ << " waiting for consumer to finish!!" << endl;
				cvr.wait(lkr, []{return readDone;});
				readDone = false;
			}
			cout << __func__ << " resuming after consumer!!" << endl;
		}
	}

	cout << "Exiting " << __func__ << endl;
}

void producer(ifstream& ifs) {
	unsigned char b;
	short n;

	cout << "Starting " << __func__ << endl;
	while (!ifs.eof()) {
		{
			unique_lock lk(writeLock);
			cout << __func__ << " waiting for write data ready!!"  << endl;
			cvw.wait(lk, [] {return writeReady;});
			lk.unlock();
		}
		cout << __func__ << " write data ready!!"  << endl;

		do {
			cout << "Number of writes (1-4):" << flush;
			cin >> n;
		} while (n <= 0 || n > WRITE_SIZE);

		if (n + dataQ.size() > MAX_QSIZE) {
			{
				lock_guard<mutex> rlkg(rateLock);
				rateLReady = true;
				cout << __func__ << " limit rate"  << endl;
			}
			cvrl.notify_one(); 
			{
				unique_lock rlk(rateLock);
				cvrl.wait(rlk, []{return rateLDone;});
				cout << __func__ << " resuming after rate limit"  << endl;
				rateLDone = false;
			}
		}

		while (n--) {
			for (size_t i = 0; i < PACKET_SIZE; i++) {
				ifs >> b;
				dataQ.push(b);
			}
		}
		writeDone = true;
		writeReady = false;
		cout << __func__ << " signalling event thread" << endl;
		cvw.notify_one();
	}
	wcomplete = true;
	{
		lock_guard<mutex> rlkg(rateLock);
		rateLReady = true;
		cout << __func__ << " signalling rate limit <END>"  << endl;
	}
	cvrl.notify_one();
	{
		unique_lock rlk(rateLock);
		cvrl.wait(rlk, []{return rateLDone;});
		cout << __func__ << " resume after rate limit exit" << endl;
		rateLReady = false;
	}

	cout << "Exiting " << __func__ << endl;

	return;
}

void ratelimit(ofstream& ofs) {
	short n;
	unsigned char c;

	cout << "Starting " << __func__ << endl;
	while (!wcomplete) {
		{
			unique_lock lk(rateLock);
			cout << __func__ << " waiting for ratelimit signal!!"  << endl;
			cvrl.wait(lk, [] {return rateLReady;});
			lk.unlock();
		}
		cout << __func__ << " starting rate limiting!!"  << endl;
		n = RATE_LIMIT_SIZE;
		while (n-- && !wcomplete) {
			cout << "f:" << __func__ << " l:" << __LINE__ << " pushing packet" << n << endl;
			for (size_t i = 0; i < PACKET_SIZE; i++) {
				c = dataQ.front();
				dataQ.pop();
				ofs << c;
				tbytes--;
			}
		}
		rateLDone = true;
		rateLReady = false;
		cout << __func__ << " rate limiting done!!"  << endl;
		cvrl.notify_one();
	}
	cout << "Exiting " << __func__ << endl;
	return;
}

void consumer(ofstream& ofs) {
	short n;
	unsigned char c;

	cout << "Starting " << __func__ << endl;
	while (tbytes) {
		{
			unique_lock lk(readLock);
			cout << __func__ << " waiting for read data ready!!"  << endl;
			cvr.wait(lk, [] {return readReady;});
			lk.unlock();
		}
		cout << __func__ << " read data ready!!"  << endl;
		n = READ_SIZE;
		while (!dataQ.empty() && n--) {
			for (size_t i = 0; i < PACKET_SIZE && !dataQ.empty() && tbytes; i++) {
				cout << tbytes << " bytes remaining" << endl;
				c = dataQ.front();
				dataQ.pop();
				ofs << c;
				tbytes--;
			}
		}
		readDone = true;
		readReady = false;
		cout << __func__ << " signalling event thread!!"  << endl;
		cvr.notify_one();
	}

	rcomplete = true;
	cout << "Exiting " << __func__ << endl;
	return;
}

int main() 
{
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	ifs.seekg(0, ios_base::end);
	tbytes = ifs.tellg();
	ifs.seekg(0, ios_base::beg);

	thread e([]() {EventThread();});
	thread p([&]() {producer(ifs);});
	thread c([&]() {consumer(ofs);});
	thread r([&]() {ratelimit(ofs);});

	p.join();
	c.join();
	r.join();
	e.join();
	return 0;
}

