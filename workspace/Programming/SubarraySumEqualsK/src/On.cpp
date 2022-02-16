/*
 * On.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#include <On.h>

int On::subarraySum(vector<int>& nums, int k)
{
	map<int, int>::iterator it;
	size_t ns = nums.size();
	map<int, int> sums;
	int sum = 0;
	int count = 0;

	sums.insert(pair<int, int>(0,1));
	for (size_t i = 0; i < ns; i++) {
		sum += nums[i];
		it = sums.find(sum - k);
		if (it != sums.end())
			count += it->second;
		if (sums.find(sum) == sums.end())
			sums.insert(pair<int, int>(sum, 1));
		else
			sums[sum]++;
	}

	return count;
}
