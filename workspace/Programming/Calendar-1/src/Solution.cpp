/*
 * Solution.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
 * Algorithm:
 * 
 * If 2 events's start time is after the end of other,
 * they dont overlap.
 * Else fail.
 * 
 */

class MyCalendar {
private:
	list<int*> slots;
public:
    MyCalendar();
    bool book(int start, int end);
};

MyCalendar::MyCalendar() {
}

bool MyCalendar::book(int start, int end)
{
	for (auto slot: slots) {
		if (slot[0] < end && start < slot[1])
			return false;
	}

	slots.push_back(new int[2] {start, end});
	return true;
}

int main()
{
	MyCalendar* obj = new MyCalendar();

	cout << ((obj->book(10, 20)) ? "true" : "false") << endl;
	cout << ((obj->book(15, 25)) ? "true" : "false") << endl;
	cout << ((obj->book(20, 30)) ? "true" : "false") << endl;

	return 0;
}
