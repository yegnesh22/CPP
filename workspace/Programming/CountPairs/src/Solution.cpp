/*
 * Solution.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int countPairs(vector<int>& nums, int k);
};

int Solution::countPairs(vector<int>& nums, int k)
{
	map<int, vector<int>> lkp;
	int ns = nums.size();
	int count = 0;

	for (int i = 0; i < ns; i++) {
		if (lkp.find(nums[i]) != lkp.end()) {
			int vs = lkp[nums[i]].size();
			for (int j = 0; j < vs; j++) {
				if (((i * lkp[nums[i]][j]) % k) == 0)
					count++;
			}
			lkp[nums[i]].push_back(i);
		} else
			lkp.insert(pair<int, vector<int>> {nums[i], {i}});
	}

	return count;
}

struct ti {
	vector<int> nums;
	int k;
	int eo;
	int ao;
	ti(vector<int> n, int tk, int teo): nums(n), k(tk), eo(teo) {}
};

vector<ti> t = {
		ti({3,1,2,2,2,1,3}, 2, 4),
		ti({1,2,3,4}, 1, 0),
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->countPairs(t[i].nums, t[i].k);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
