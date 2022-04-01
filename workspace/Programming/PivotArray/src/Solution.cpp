/*
 * Solution.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot);
};

vector<int> Solution::pivotArray(vector<int>& nums, int pivot)
{
	int ns = nums.size();
	vector<int> l;
	vector<int> e;
	vector<int> g;

	for (int i = 0; i < ns; i++) {
		if (nums[i] < pivot)
			l.push_back(nums[i]);
		else if (nums[i] == pivot)
			e.push_back(nums[i]);
		else
			g.push_back(nums[i]);
	}

	l.insert(l.end(), e.begin(), e.end());
	l.insert(l.end(), g.begin(), g.end());

	return l;
}

struct ti {
	vector<int> nums;
	int pivot;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> n, int p, vector<int> e): nums(n), pivot(p), eo(e) {}
};

vector<ti> t = {
		ti({9,12,5,10,14,3,10}, 10, {9,5,3,10,10,12,14}),
		ti({-3,4,3,2}, 2, {-3,2,4,3}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->pivotArray(t[i].nums, t[i].pivot);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
