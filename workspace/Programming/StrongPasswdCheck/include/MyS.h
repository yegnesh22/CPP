/*
 * MyS.h
 *
 *  Created on: Mar 12, 2022
 *      Author: ysiyer
 */

#ifndef MYS_H_
#define MYS_H_

#include <set>
#include <map>
#include <queue>
#include <vector>
#include <Basic.h>

typedef enum {
	LOWER_CASE,
	UPPER_CASE,
	NUMBER,
	CTYPES,
} cp;

struct cmp {
	bool operator() (const int& a, const int& b) const {
		int rem_a = a % 3;
		int rem_b = b % 3;
#ifdef DEBUG
		cout << "comparing " << a << " and " << b << " r_a:" << rem_a << " and r_b:" << rem_b << endl;
#endif

		if (rem_a == rem_b)
			return a < b;
		else
			rem_a > rem_b;
	}
};

class MyS: public Solution {
public:
	cp getCType(char c);
	int strongPasswordChecker(string password);
};

#endif /* MYS_H_ */
