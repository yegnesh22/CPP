/*
 * Solution.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minSwaps(string s);
};

int Solution::minSwaps(string s)
{
	int oC = 0;
	int zC = 0;
	int cbc = 0;
	int sbc = 0;
	bool sb = 1;
	bool cb = 0;
	bool ss;
	bool cs;
	bool b;

	for (int i = 0; i < s.length(); i++) {
		b = s[i] - '0';
		if (b)
			oC++;
		else
			zC++;

		ss = b ^ sb;
		cs = b ^ cb;

		if (ss)
			sbc++;

		if (cs)
			cbc++;

		sb ^= 1;
		cb ^= 1;
	}

	if ((abs(oC - zC) > 1) || ((sbc & 0x1) && (cbc & 0x1)))
		return -1;
	else {
		if (cbc & 0x1)
			return sbc / 2;
		if (sbc & 0x1)
			return cbc / 2;
		return min(sbc, cbc) / 2;
	}

	return -1;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.s = "111000",
				.eo = 1,
		},
		{
				.s = "010",
				.eo = 0,
		},
		{
				.s = "1110",
				.eo = -1,
		},
		{
				.s = "100",
				.eo = 1,
		},
		{
				.s = "01000",
				.eo = -1,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minSwaps(t[i].s);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
