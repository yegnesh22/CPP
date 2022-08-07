/*
 * Solution.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: ysiyer
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

#define sfree true
#define sbooked false

vector<bool> m_slot (INT_MAX, sfree);

class MyCalendar {
public:
    MyCalendar();
    bool book(int start, int end);
};

MyCalendar::MyCalendar() {
}

bool MyCalendar::book(int start, int end)
{
	vector<bool> v (end - start, sbooked);
	bool r = true;

	for (size_t i = start; ((r == sfree) && (i < end)); i++) {
		cout << i << endl;
		r &= m_slot[i];
	}

	if (r == sfree) {
		// Update the calendar as blocked
		vector<bool>::iterator slotit = m_slot.begin();
		bool occ = sbooked;
		cout << "h -- 1" << endl;
		m_slot.erase(slotit + start, slotit + end);
		cout << "h -- 2" << endl;
		m_slot.insert(slotit + start, (end - start), occ);
	}


	return r;
}

int main()
{
	MyCalendar* obj = new MyCalendar();

	cout << ((obj->book(10, 20)) ? "true" : "false") << endl;
	cout << ((obj->book(15, 25)) ? "true" : "false") << endl;
	cout << ((obj->book(20, 30)) ? "true" : "false") << endl;

	return 0;
}

