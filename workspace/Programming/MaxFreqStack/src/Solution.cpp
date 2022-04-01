/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct fsdata {
	int val;
	int freq;
	int seq;
	fsdata(int v, int f, int s): val(v), freq(f), seq(s) {}
};

struct cmp {
	bool operator() (const fsdata& a, const fsdata& b) const {
		if (a.freq == b.freq)
			return a.seq < b.seq;
		return a.freq < b.freq;
	}
};

class FreqStack {
	priority_queue<fsdata, vector<fsdata>, cmp> m_heap;
	map<int, int> lkp;
	int m_seq;
public:
	FreqStack();
	void push(int val);
	int pop();
};

FreqStack::FreqStack()
{
	m_seq = 0;
}

void FreqStack::push(int val)
{
	lkp[val]++;
	m_seq++;
	m_heap.push(fsdata(val, lkp[val], m_seq));
}

int FreqStack::pop()
{
	fsdata top = m_heap.top();
	m_heap.pop();
    lkp[top.val]--;
	//cout << "popped -- v:" << top.val << " f:" << top.freq << " seq:" << top.seq << endl;
	return top.val;
}

int main()
{
	FreqStack* fs = new FreqStack();
#if 0
	fs->push(5);
	fs->push(7);
	fs->push(5);
	fs->push(7);
	fs->push(4);
	fs->push(5);
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	delete fs;

	fs = new FreqStack();
#endif
	fs->push(1);
	fs->push(1);
	fs->push(1);
	fs->push(2);
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	fs->push(2);
	fs->push(2);
	fs->push(1);
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	cout << fs->pop() << endl;
	delete fs;

	return 0;
}
