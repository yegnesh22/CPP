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
	void sortColors(vector<int>& nums) {
		int ns = nums.size();
		int t;

		for (int i = 0; i < ns; i++) {
			for (int j = 0; j < ns-1; j++) {
				if (nums[j] > nums[j+1]) {
					t = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = t;
				}
			}
		}
	}
};

struct ti {
	vector<int> nums;
	vector<int> eo;
	ti(vector<int> nums, vector<int> eo): nums(nums), eo(eo) {}
};

vector<ti> tests = {
		ti({2,0,2,1,1,0}, {0,0,1,1,2,2}),
		ti({2,0,1}, {0,1,2}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		s->sortColors(t.nums);
		assert(t.nums == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
