/*
 * Solution.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <list>

using namespace std;

/*
 * Algorithm:
 * Maintain 2 lists.
 * 1. Maintains the single booking.
 * 2. Maintains the double booking. -- Double booking
 * to keep only the overlapping slots.
 *
 * For each new interval check if it overlaps in the
 * double list.
 *
 * If yes, then return false.
 * Else, check in the single booking list.
 * If it existed, then add the overlapping time to the double
 * booking list and add the interval to the single booking
 * list.
 *
 */

class MyCalendarTwo {
private:
	list<int*> s;
	list<int*> d;
public:
	MyCalendarTwo();
	bool book(int start, int end);
};

MyCalendarTwo::MyCalendarTwo()
{
}

bool MyCalendarTwo::book(int start, int end)
{
	for (auto l : d) {
		if ((l[0] < end) && (start < l[1]))
			return false;
	}

	for (auto l : s) {
		if ((l[0] < end) && (start < l[1]))
			d.push_back(new int[2] {max(l[0], start), min(l[1],end)});
	}
	s.push_back(new int[2] {start, end});

	return true;
}

int main()
{
	MyCalendarTwo* obj = new MyCalendarTwo();

	cout << (obj->book(10, 20) ? "true" : "false") << endl;
	cout << (obj->book(50, 60) ? "true" : "false") << endl;
	cout << (obj->book(10, 40) ? "true" : "false") << endl;
	cout << (obj->book(5, 15) ? "true" : "false") << endl;
	cout << (obj->book(5, 10) ? "true" : "false") << endl;
	cout << (obj->book(25, 55) ? "true" : "false") << endl;

	return 0;
}
