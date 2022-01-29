/*
 * Basic.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

vector<vector<int>>BasicSolution::generateMatrix(int n)
{
	vector<vector<int>> r(n, vector<int>(n, 0));
	int count = n * n;
	int re = n - 1;
	int ce = n - 1;
	int val = 1;
	int rs = 0;
	int cs = 0;
	int i = 0;
	int j = 0;
	dir d = R;

	while (count > 0) {
		r[i][j] = val;
		count--;
		val++;
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
