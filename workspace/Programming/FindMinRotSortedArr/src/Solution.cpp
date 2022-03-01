/*
 * Solution.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums);
};

int Solution::findMin(vector<int>& nums)
{
	int ns = nums.size() - 1;
	int start = 0;
	int end = ns;
    int index;

	while (nums[start] > nums[end]) {
		start++;
		end--;
	}

    index = end+1;
	if (index > ns)
		index = 0;

	return (nums[index] < nums[start]) ? nums[index] : nums[start];
}
