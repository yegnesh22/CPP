/*
 * Solution.cpp
 *
 *  Created on: Apr 17, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> pstrs;
		vector<vector<string>> result;

		for (auto& s: strs) {
			string k = s;
			sort(k.begin(), k.end());
			if (pstrs.find(k) != pstrs.end())
				pstrs[k].push_back(s);
			else
				pstrs.insert(pair<string, vector<string>> {k, {s}});
		}

		for (auto it = pstrs.begin(); it != pstrs.end(); it++)
			result.push_back(it->second);

		return result;
	}
};

struct ti {
	vector<string> strs;
	vector<vector<string>> eo;
	vector<vector<string>> ao;
	ti(vector<string>strs, vector<vector<string>> eo): strs(strs), eo(eo) {}
};

vector<ti> tests = {
		ti({"eat","tea","tan","ate","nat","bat"},{{"bat"},{"nat","tan"},{"ate","eat","tea"}}),
		ti({""}, {{""}}),
		ti({"a"}, {{"a"}}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->groupAnagrams(t.strs);
		assert(t.ao.size() == t.eo.size());
		cout << i++ << " -- pass" << endl;
	}
	return 0;
}
