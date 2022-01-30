/*
 * DP.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <DP.h>

int DP::uniquePaths(int m, int n)
{
	vector<vector<int>> l (m, vector<int> (n, 1));

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++)
			l[i][j] = l[i - 1][j] + l[i][j - 1];
	}

	return l[m - 1][n - 1];
}

