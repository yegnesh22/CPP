/*
 * Solution.cpp
 *
 *  Created on: Mar 6, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int setBits(int n);
};

int Solution::setBits(int n)
{
	int count = 0;

	while (n != 0) {
		n = n & (n - 1);
		count++;
	}

	return count;
}

struct ti {
	int n;
	int eo;
	int ao;
};

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

vector<ti> t = {
		{
				.n = 0x52,
				.eo = 3,
		},
		{
				.n = 0x30,
				.eo = 2,
		},
		{
				.n = 0,
				.eo = 0,
		},
		{
				.n = 0x1,
				.eo = 1,
		},
};

int main()
{
	Solution* s  = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->setBits(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}

