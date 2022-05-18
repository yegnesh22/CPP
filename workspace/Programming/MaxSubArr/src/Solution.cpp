/*
 * Solution.cpp
 *
 *  Created on: Apr 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int nl = nums.size();
		int m = INT_MIN;
		int sum;

		for (int i = 0; i < nl; i++) {
			sum = 0;
			for (int j = i; j < nl; j++) {
				sum += nums[j];
				m = max(m, sum);
			}
		}

		return m;
	}
};

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> nums, int eo): nums(nums), eo(eo) {}
};

vector<ti> tests = {
		ti({-2,1,-3,4,-1,2,1,-5,4}, 6),
		ti({1}, 1),
		ti({5,4,-1,7,8}, 23),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.ao = s->maxSubArray(t.nums);
		assert(t.eo == t.ao);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
