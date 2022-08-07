/*
 * Solution.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int findNthDigit(int n);
};

int Solution::findNthDigit(int n)
{
	long int num = 0;
	long int lrd = n;
	long int nd = 1;
	long int rd = n;
	long int m = 9;
	long int f = 1;
	long int index;
	long int seq;
	long int b;

	while (rd >= 0) {
		lrd = rd;
		rd = rd - (m * f * nd);
		f *= 10;
#ifdef DEBUG
		cout << "loop --> rd:" << rd << " lrd:" << lrd << " f:" << f << " nd:" << nd << endl;
#endif

		if (rd >= 0)
			nd++;
	}

	rd = lrd;
	b = lrd % nd;
	seq = lrd / nd;

	if (nd > 1) {
		num = pow(10, (nd - 1));
		num += seq;
		if (b == 0 && nd > 1)
			num--;
	} else
		num = seq;

#ifdef DEBUG
	cout << "nd:" << nd << " rd:" << rd << " seq:" << seq << " b:" << b << " num:" << num << endl;
#endif
	string res = to_string(num);
	if (b != 0)
		index = b - 1;
	else
		index = res.length() - 1;

	return res[index] - '0';
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = 3,
				.eo = 3,
		},
		{
				.n = 11,
				.eo = 0,
		},
		{
				.n = 189,
				.eo = 9,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findNthDigit(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
