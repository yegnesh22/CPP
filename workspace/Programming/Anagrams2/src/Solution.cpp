/*
 * Solution.cpp
 *
 *  Created on: Mar 26, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

class Solution {
public:
	int minSteps(string s, string t);
};

int Solution::minSteps(string s, string t)
{
	int sl = s.length();
	int tl = t.length();
	int ccount = 0;
	int si = 0;
	int ti = 0;

	sort(s.begin(), s.end());
	sort(t.begin(), t.end());

	while (si < sl && ti < tl) {
		//cout << "s: " << s[si] << " t:" << t[ti] << " count:" << ccount << endl;
		if (s[si] == t[ti]) {
			si++;
			ti++;
			continue;
		}
		if (s[si] < t[ti])
			si++;
		else
			ti++;
		ccount++;
	}

	if (si < sl)
		ccount += sl - si;
	if (ti < tl)
		ccount += tl - ti;

	//cout << "returning count: " << ccount << endl;
	return ccount;
}

struct ti {
	string s;
	string t;
	int eo;
	int ao;
	ti(string ts, string tt, int teo): s(ts), t(tt), eo(teo) {}
};

vector<ti> t = {
		ti("leetcode", "coats", 7),
		ti("night", "thing", 0),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minSteps(t[i].s, t[i].t);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
	}

	return 0;
}
