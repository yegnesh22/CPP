/*
 * Solution.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include "ring.h"

using namespace std;

int main()
{
	ring<string> textRing(3);

	textRing.add("1");
	textRing.add("2");
	textRing.add("3");

	for (auto it = textRing.begin(); it != textRing.end();it++)
		cout << *it << endl;

	/*textRing.add("4");

	for (auto it: textRing)
		cout << it << endl;

	ring<int> numRing(5);
	numRing.add(1);
	numRing.add(2);
	numRing.add(3);
	numRing.add(4);
	numRing.add(5);

	// Array style access
	for (int i = 0; i < numRing.size(); i++) {
		cout << numRing[i] << endl;
	}
	numRing.add(6);

	// C++11 style access
	for (auto t: numRing) {
		cout << t << endl;
	}*/

	return 0;
}
