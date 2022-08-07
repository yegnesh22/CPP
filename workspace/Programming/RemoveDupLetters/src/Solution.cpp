/*
 * Solution.cpp
 *
 *  Created on: Mar 9, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	string removeDuplicateLetters(string s);
};

struct compareS {
	bool operator() (const pair<char, int>& a, const pair<char, int>& b) const {
		return a.second < b.second;
	}
};

string Solution::removeDuplicateLetters(string s)
{
	map<char, int> lkp;

	for (int i = 0; i < s.length(); i++)
		lkp[s[i]] = i;

	set<pair<char, int>, compareS> lkp_s;
	string res;

	for (auto it = lkp.begin(); it != lkp.end(); it++) {
		cout << "map e:" << it->first << " i:" << it->second << endl;
		lkp_s.insert({it->first, it->second});
	}

	for (auto it = lkp_s.begin(); it != lkp_s.end(); it++) {
		cout << "set e:" << it->first << " i:" << it->second << endl;
		res.push_back(it->first);
	}

	cout << res << endl;
	return res;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string eo;
	string ao;
};

vector<ti> t = {
		{
				.s = "bcabc",
				.eo = "abc",
		},
		{
				.s = "cbacdcbc",
				.eo = "acdb",
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeDuplicateLetters(t[i].s);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
