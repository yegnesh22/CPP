/*
 * Solution.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	int eo;
	int ao;
};

class Solution {
public:
    int addDigits(int num);
};

int Solution::addDigits(int num)
{
	int val = 0;
	int d;

	while (1) {
		d = num % 10;
		num = num / 10;
		val += d;
		if (num == 0) {
			num = val;
			val = 0;
			if (num < 10)
				return num;
		}
	}

	return val;
}

vector<ti> t = {
		{
				.n = 38,
				.eo = 2,
		},
		{
				.n = 0,
				.eo = 0,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->addDigits(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
