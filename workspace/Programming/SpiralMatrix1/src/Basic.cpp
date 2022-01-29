/*
 * Basic.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

vector<int>BasicSolution::spiralOrder(vector<vector<int>>& matrix)
{
	int count = matrix.size() * matrix[0].size();
	int re = matrix.size() - 1;
	int ce = matrix[0].size() - 1;
	vector<int> r;
	int rs = 0;
	int cs = 0;
	int i = 0;
	int j = 0;
	dir d = R;

	while (count > 0) {
		r.push_back(matrix[i][j]);
		count--;
		if (d == R) {
			if (j == ce) {
				d = D;
				rs++;
			}
			else {
				j++;
			}
		}
		if (d == D) {
			if (i == re) {
				ce--;
				d = L;
			} else {
				i++;
			}
		}
		if (d == L) {
			if (j == cs) {
				re--;
				d = U;
			} else {
				j--;
			}
		}

		if (d == U) {
			if (i == rs) {
				cs++;
				d = R;
				j = cs;
			} else {
				i--;
			}
		}
	}

	return r;
}
