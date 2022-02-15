/*
 * Solution.cpp
 *
 *  Created on: Feb 15, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums);
};

int Solution::singleNumber(vector<int>& nums)
{
	int ns = nums.size();

	sort(nums.begin(), nums.end());
	for (int i = 0; i < ns; i+=2) {
		if ((i == ns-1) || (nums[i] != nums[i+1]))
			return nums[i];
	}

	return -1;
}

int Solution::singleNumber(vector<int>& nums)
{
	int ns = nums.size();
    int a = 0;

	for (int i = 0; i < ns; i++)
        a ^= nums[i];

	return a;
}
