#include <iostream>
#include <thread>

using namespace std;

int main()
{
	int cnt = 0;
	auto f = [&] (int id) mutable {
		do {
			cout << "thread id: " << id << " count:" << cnt++ << endl;
		} while(cnt < 100);
	};
	thread t1(f, 0), t2(f, 1), t3(f, 2);
	t1.join();
	t2.join();
	t3.join();

	return 0;
}

