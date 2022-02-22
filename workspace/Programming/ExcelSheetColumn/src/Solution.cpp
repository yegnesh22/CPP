/*
 * Solution.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle);
};

int Solution::titleToNumber(string columnTitle)
{
	int cl = columnTitle.length() - 1;
	int value = 0;

	for (int i = 0; i <= cl; i++) {
		value = value * 26;
		value = value + (columnTitle[i] - 'A' + 1);
	}

	return value;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.s = "A",
				.eo = 1,
		},
		{
				.s = "AB",
				.eo = 28,
		},
		{
				.s = "ZY",
				.eo = 701,
		},
};

int main()
{
	Solution* s =  new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->titleToNumber(t[i].s);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
