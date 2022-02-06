/*
 * Solution.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums);
};


int Solution::findDuplicate(vector<int>& nums)
{
	int n = nums.size();
	vector<bool> l(n, false);

	for (int i = 0; i < n; i++) {
		if (l[nums[i]] == false)
			l[nums[i]] = true;
		else
			return nums[i];
	}
	return -1;
}

