/*
 * DP.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <DP.h>

bool DP::canJumpFromPosition(int pos, vector<int>& n)
{
	vector<int> nm;

	if (m_memo[pos] != U) {
		return (m_memo[pos] == G ? true: false);
	}
	if (pos == n.size() - 1) {
		m_memo[pos] = G;
		return true;
	}

	for (int i = pos + 1; i <= (pos + n[pos]); i++) {
		if (canJumpFromPosition(i, n)) {
			m_memo[pos] = G;
			return true;
		}
	}

	m_memo[pos] = B;
	return false;
}

bool DP::canJump(vector<int>& nums)
{
	m_memo.clear();
	m_memo.resize(nums.size());

	for (int i = 0; i < nums.size(); i++)
		m_memo[i] = U;

	return canJumpFromPosition(0, nums);
}



