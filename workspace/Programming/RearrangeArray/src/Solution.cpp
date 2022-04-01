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
	vector<int> rearrangeArray(vector<int>& nums);
};

vector<int> Solution::rearrangeArray(vector<int>& nums)
{
	int ns = nums.size();
	vector<int> r(ns);
	int pi, ni, ri;

	pi = 0;
	ni = 1;
	for (int i = 0; i < ns; i++) {
		if (nums[i] > 0) {
			r[pi] = nums[i];
			pi += 2;
		} else {
			r[ni] = nums[i];
			ni += 2;
		}
	}

	return r;
}

struct ti {
	vector<int> nums;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> n, vector<int> e): nums(n), eo(e) {}
};

vector<ti> t = {
		ti({3,1,-2,-5,2,-4}, {3,-2,1,-5,2,-4}),
		ti({-1,1}, {1,-1}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->rearrangeArray(t[i].nums);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
