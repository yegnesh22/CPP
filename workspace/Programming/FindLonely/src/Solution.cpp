/*
 * Solution.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> findLonely(vector<int>& nums);
};

vector<int> Solution::findLonely(vector<int>& nums)
{
	int ns = nums.size();
	vector<int> result;
	map<int, int> lkp;

	for (int i = 0; i < ns; i++) {
		if (lkp.find(nums[i]) != lkp.end())
			lkp.insert({nums[i],0});
		lkp[nums[i]]++;
	}

	for (auto it = lkp.begin(); it != lkp.end(); it++) {
		int key = it->first;
		int freq = it->second;
		if (freq > 1)
			continue;
		if (lkp.find(key - 1) != lkp.end() || lkp.find(key + 1) != lkp.end())
			continue;
		result.push_back(key);
	}

	return result;
}

struct ti {
	vector<int> nums;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> n, vector<int> e): nums(n), eo(e) {}
};

vector<ti> t = {
		ti({10,6,5,8}, {10,8}),
		ti({1,3,5,3}, {1,5}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findLonely(t[i].nums);
		assert(t[i].ao.size() == t[i].eo.size());
		cout << i << " -- pass" << endl;
	}

	return 0;
}
