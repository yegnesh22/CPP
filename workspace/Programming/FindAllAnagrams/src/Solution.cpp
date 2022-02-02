/*
 * Solution.cpp
 *
 *  Created on: 02-Feb-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string p;
	vector<int> eo;
	vector<int> ao;
};

class Solution {
public:
    virtual vector<int> findAnagrams(string s, string p) = 0;
};

class Basic: public Solution {
public:
	vector<int>  findAnagrams(string s, string p);
};

vector<int> Basic::findAnagrams(string s, string p)
{
	vector<int> plookup(26, 0);
	vector<int> slookup(26, 0);
	vector<int> r;
	int swS = 0;
	int i;

	if (p.size() > s.size())
		return r;

	for (i = 0; i < p.size(); i++) {
		plookup[p[i] - 'a']++;
		slookup[s[i] - 'a']++;
	}

	swS = 0;
	for (; i < s.size(); i++, swS++) {
		if (plookup == slookup) {
			cout << "pushing " << swS << endl;
			r.push_back(swS);
		}

		slookup[s[swS] - 'a']--;
		slookup[s[i] - 'a']++;
	}

	if (plookup == slookup) { // Check the last match
		cout << "pushing " << swS << endl;
		r.push_back(swS);
	}


	return r;
}

vector<ti> t = {
		{
				.s = "cbaebabacd",
				.p = "abc",
				.eo = {0,6},
		},
		{
				.s = "abab",
				.p = "ab",
				.eo = {0,1,2},
		},
		{
				.s = "abab",
				.p = "dc",
				.eo = {},
		},
		{
				.s = "aaaaaaaaaa",
				.p = "aaaaaaaaaaaaa",
				.eo = {},
		},
};

int main()
{
	Solution *s = new Basic();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findAnagrams(t[i].s, t[i].p);
		cout << i << " -- " << check_result(t[i]) << endl;
	}
	return 0;
}
