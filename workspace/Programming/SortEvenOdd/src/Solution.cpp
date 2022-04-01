/*
 * Solution.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> sortEvenOdd(vector<int>& nums);
};

vector<int> Solution::sortEvenOdd(vector<int>& nums)
{
	priority_queue<int, vector<int>, greater<int>> even;
	priority_queue<int> odd;
	int ns = nums.size();
	vector<int> result;

	for (int i = 0; i < ns; i++) {
		if (i & 0x1)
			odd.push(nums[i]);
		else
			even.push(nums[i]);
	}

	for (int i = 0; i < ns; i++) {
		if (i & 0x1) {
			result.push_back(odd.top());
			odd.pop();
		} else {
			result.push_back(even.top());
			even.pop();
		}
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
		ti({4,1,2,3}, {2,3,4,1}),
		ti({2,1}, {2,1}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->sortEvenOdd(t[i].nums);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
