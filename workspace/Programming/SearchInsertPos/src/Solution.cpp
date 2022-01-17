/*
 * Solution.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ysiyer
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int pos = 1;
		int start = 0;
		int end = nums.size() - 1;

		if (end < 0)
			return 0;

		if (target <= nums[0])
			return 0;
		if (target > nums[end])
			return end + 1;
		if (target == nums[end])
			return end;

		while ((end - start) >= 0) {
			pos = start + ((end - start + 1) / 2);
			if ((nums[pos - 1] < target) && (nums[pos] > target))
				return pos;
			else if (nums[pos] == target)
				return pos;

			if (nums[pos] < target)
				start = pos + 1;
			else if (nums[pos] > target)
				end = pos - 1;
		}

		return pos + 1;
	}
};

struct TestInputs {
	vector<int> nums;
	int target;
};

int main()
{
	vector<TestInputs> t = {
			{.nums = {1,3,5,6}, .target = 5},
			{.nums = {1,3,5,6}, .target = 1},
			{.nums = {1,3,5,6}, .target = 6},
			{.nums = {1,3,5,6}, .target = 2},
			{.nums = {1,3,5,6}, .target = 7},
			{.nums = {1,3,5,6}, .target = 0},
			{.nums = {1,3,5,6}, .target = 4},
			{.nums = {1}, .target = 2},
			{.nums = {}, .target = 0},
			{.nums = {2,7,8,9,10}, .target = 9},
	};
	Solution s;

	for (int i = 0; i < t.size(); i++)
		cout << s.searchInsert(t[i].nums, t[i].target) << endl;
	return 0;
}

