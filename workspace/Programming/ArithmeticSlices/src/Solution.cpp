/*
 * Solution.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& nums);
};

int Solution::numberOfArithmeticSlices(vector<int>& nums)
{
	int nl = nums.size();

	if (nl < 3)
		return 0;

	int left = 0;
	int right = left + 2;
	int incr = 1;
	int count = 0;
	int diff;

	while (right < nl) {
		diff = nums[left+1] - nums[left];
		while ((right < nl) && (nums[right] - nums[right-1]) == diff) {
			right++;
			count += incr;
			incr++;
		}
		incr = 1;
		left++;
		right++;
		continue;
	}

	cout << "returned count: " << count << endl;
	return count;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.nums = {1,2,3,4},
				.eo = 3,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->numberOfArithmeticSlices(t[i].nums);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
