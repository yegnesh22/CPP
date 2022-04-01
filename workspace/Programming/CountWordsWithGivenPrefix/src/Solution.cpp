/*
 * Solution.cpp
 *
 *  Created on: Mar 26, 2022
 *      Author: ysiyer
 */

#include <assert.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int prefixCount(vector<string>& words, string pref);
};

int Solution::prefixCount(vector<string>& words, string pref)
{
	int pl = pref.length();
	int nw = words.size();
	int count = 0;
	string ss;

	for (int i = 0; i < nw; i++) {
		if (words[i].length() < pl)
			continue;
		ss = words[i].substr(0, pl);
		if (ss == pref)
			count++;
	}

	return count;
}

struct ti {
	vector<string> words;
	string pref;
	int eo;
	int ao;
	ti(vector<string> w, string p, int e): words(w), pref(p), eo(e) {}
};

vector<ti> t = {
	ti({"pay","attention","practice","attend"}, "at", 2),
	ti({"leetcode","win","loops","success"}, "code", 0),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->prefixCount(t[i].words, t[i].pref);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
	}

	return 0;
}
