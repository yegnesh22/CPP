/*
 * Solution.cpp
 *
 *  Created on: Apr 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int ns = nums.size();
		int es = (ns * (ns + 1)) >> 1;
		int sum = 0;

		for (int i = 0; i < ns; i++)
			sum += nums[i];

		return es - sum;
	}
};

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> nums, int eo): nums(nums), eo(eo) {}
};

vector<ti> tests = {
		ti({3,0,1}, 2),
		ti({0,1}, 2),
		ti({9,6,4,2,3,5,7,0,1}, 8),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.ao = s->missingNumber(t.nums);
		assert(t.eo == t.ao);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
