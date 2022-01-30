/*
 * Solution.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#include <Solutions.h>

/*
 * Matrix properties:
 *
 * 1. Integers in each row are sorted from left to right.
 * 2. The first integer of each row is greater than the
 * last integer of the previous row.
 *
 */
bool BasicSolution::searchMatrix(vector<vector<int>>& matrix, int target)
{
	int nr = matrix.size();
	int nc = matrix[0].size();

	// Binary Search to find the row first
	int re = nr;
	int rs = 0;
	int rmid = (re - rs) / 2 + rs;
	while(rs < re) {
		if (matrix[rmid][0] <= target && target <= matrix[rmid][nc - 1]) {
			break;
		}
		else if (matrix[rmid][0] > target)
			re = rmid - 1;
		else
			rs = rmid + 1;
		rmid = (re - rs) / 2 + rs;

	}

	if (rmid == nr)
		rmid--;

	// Binary Search in the specific row
	int ce = nc;
	int cs = 0;
	int cmid = (ce - cs) / 2 + cs;
	while(cs < ce) {
		if (matrix[rmid][cmid] == target)
			return true;
		else if (matrix[rmid][cmid] < target)
			cs = cmid + 1;
		else
			ce = cmid;
		cmid = (ce - cs) / 2 + cs;
	}

	if (cmid == nc)
		cmid--;

	if (matrix[rmid][cmid] != target)
		return false;

	return true;
}
