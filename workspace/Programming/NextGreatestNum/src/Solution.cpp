/*
 * Solution.cpp
 *
 *  Created on: Apr 17, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int ns = nums.size();
		vector<int> result(ns, -1);

		for (int i = 0; i < ns; i++) {
			for (int k = ((i + 1) % ns); k != i; k = ((k+1) % ns)) {
				if (nums[k] > nums[i]) {
					result[i] = nums[k];
					break;
				}
			}
		}

		return result;
	}
};

struct ti {
	vector<int> nums;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> nums, vector<int> eo): nums(nums), eo(eo) {}
};

vector<ti> tests = {
		ti({1,2,1}, {2,-1,2}),
		ti({1,2,3,4,3}, {2,3,4,-1,4}),
};

int main()
{
	Solution* s = new Solution();
	int i = 0;

	for (auto& t: tests) {
		t.ao = s->nextGreaterElements(t.nums);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
