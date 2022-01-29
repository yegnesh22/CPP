/*
 * Backtrack.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <Backtrack.h>

bool BacktrackSolution::canJumpFromPosition(int pos, vector<int>& n)
{
	vector<int> nm;
	if (pos == n.size() - 1)
		return true;

	for (int i = pos + 1; i <= (pos + n[pos]); i++) {
		if (canJumpFromPosition(i, n))
			return true;
	}

	return false;
}

bool BacktrackSolution::canJump(vector<int>& nums)
{
	return canJumpFromPosition(0, nums);
}
