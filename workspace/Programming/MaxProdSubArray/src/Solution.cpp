/*
 * Solution.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums);
};

int Solution::maxProduct(vector<int>& nums)
{
	int nl = nums.size();

	if (nl == 0)
		return 0;

	int maxP = nums[0];
	int minP = nums[0];
	int result = maxP;
	int imax, imin;
	int cur;

	for (int i = 1; i < nl; i++) {
		cur = nums[i];
		imax = cur * maxP;
		imin = cur * minP;
		maxP = max(cur, max(imax, imin));
		minP = min(cur, min(imax, imin));
		result = max(result, maxP);
	}

	return result;
}

