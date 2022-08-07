/*
 * Solution.cpp
 *
 *  Created on: Mar 14, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string n;
	string eo;
	string ao;
	ti(string i, string e):n(i), eo(e) {}
};

class Solution {
public:
	string nearestPalindromic(string n);
};

string Solution::nearestPalindromic(string n)
{
}

vector<ti> t = {
		ti("123", "121"),
		ti("1", "0"),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->nearestPalindromic(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
