/*
 * DP.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <DP.h>

int DP::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	vector<vector<int>> l (m, vector<int> (n, 1));
	bool clear_first_row = false;
	bool clear_first_col = false;

    if (obstacleGrid[0][0] == 1)
        return 0;

	for (int i = 0; i < m; i++) {
		if (obstacleGrid[i][0] == 1)
			clear_first_col = true;
		l[i][0] = clear_first_col ? 0 : 1;
	}

	for (int j = 0; j < n; j++) {
		if (obstacleGrid[0][j] == 1)
			clear_first_row = true;
		l[0][j] = clear_first_row ? 0 : 1;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (obstacleGrid[i][j] != 1) {
				if (i != 0 && j != 0)
					l[i][j] = l[i - 1][j] + l[i][j - 1];
			} else {
				l[i][j] = 0;
			}
		}
	}

	return l[m - 1][n - 1];
}
