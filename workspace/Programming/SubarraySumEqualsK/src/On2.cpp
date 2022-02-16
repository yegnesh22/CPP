/*
 * Solution.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#include <On2.h>

int On2::subarraySum(vector<int>& nums, int k)
{
	size_t ns = nums.size();
	vector<int> sums(ns, INT_MIN);
	vector<int> freq(ns, 0);
	int count = 0;
	int s = 0;

	sums[0] = nums[0];
	for(size_t i = 1; i < ns; i++)
		sums[i] = sums[i - 1] + nums[i];

	for (size_t i = 0; i < ns; i++) {
		if (sums[i] == k) {
			count++;
		}

		for (size_t j = i+1; j < ns; j++) {
			s = sums[j] - sums[i];
			if (s == k)
				count++;
		}
	}

	return count;
}

