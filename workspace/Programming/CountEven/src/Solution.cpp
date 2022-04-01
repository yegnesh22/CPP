/*
 * Solution.cpp
 *
 *  Created on: Mar 28, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	int countEven(int num);
};

int Solution::countEven(int num)
{
	int count = 0;
	int ds, n, d;

	for (int i  = 1; i <= num; i++) {
		ds = 0;
		n = i;

		while (n > 0) {
			d = n % 10;
			ds += d;
			n = n /10;
		}
		if (!(ds & 0x1))
			count++;
	}

	return count;
}

struct ti {
	int num;
	int eo;
	int ao;
	ti(int n, int teo): num(n), eo(teo) {}
};

vector<ti> t = {
		ti(4, 2),
		ti(30, 14),
		ti(10, 4),
		ti(13, 6),
		ti(20, 10),
		ti(63, 31),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countEven(t[i].num);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
