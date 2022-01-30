/*
 * BasicSolution.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#include <BasicSolution.h>

void BasicSolution::rotate(vector<int>& nums, int k)
{
	int length = nums.size();
	int rc = k % length;
	vector<int> temp(rc);
	int i, j;

	for (i = length - 1, j = 0; j < rc; i--, j++) {
		temp[j] = nums[i];
	}
	//printV(temp);

	for (i = (length - rc - 1); i >= 0; i--) {
		nums[i + rc] = nums[i];
	}
	//printV(nums);

	for (i  = 0; i < rc; i++) {
		nums[rc - i - 1] = temp[i];
	}
	//printV(nums);

	return;
}
