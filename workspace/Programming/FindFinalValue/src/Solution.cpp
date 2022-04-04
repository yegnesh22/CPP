/*
 * Solution.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int findFinalValue(vector<int>& nums, int original);
};

int Solution::findFinalValue(vector<int>& nums, int original)
{
	int ns = nums.size();
	set<int> lkp;

	for (int i = 0; i < ns; i++)
		lkp.insert(nums[i]);

	while (lkp.find(original) != lkp.end()) {
		original *= 2;
	}

	return original;
}

struct ti {
	vector<int> nums;
	int original;
	int eo;
	int ao;
	ti(vector<int> n, int o, int e): nums(n), original(o), eo(e) {}
};

vector<ti> t = {
		ti({5,3,6,1,12}, 3, 24),
		ti({2,7,9}, 4, 4),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findFinalValue(t[i].nums, t[i].original);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
