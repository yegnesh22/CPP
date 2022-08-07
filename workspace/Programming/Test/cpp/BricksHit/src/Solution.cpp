/*
 * Solution.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#include <Solution.h>

void Solution::checkState(vector<vector<int>>& g, int r, int c, int nr, int nc)
{
	if (g[r][c] == 0)
		return;

	if (r == 0)
		return;
	else {
		if (c == 0)
			g[r][c] = g[r-1][c];
		else if (c == (nc - 1))
			g[r][c] = g[r-1][c] | g[r][c-1];
		else
			g[r][c] = g[r-1][c] | g[r][c-1];
	}
}

int Solution::calcBricks(vector<vector<int>>& grid)
{
	int nc = grid[0].size();
	int nr = grid.size();

	int count = 0;

	for(int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			checkState(grid, i, j, nr, nc);
			count += grid[i][j];
		}
	}

	cout << "count: " << count << endl;
	return count;
}

vector<int> Solution::hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits)
{
	int updatedCount;
	vector<int> r;
	int row, col;
	int count;

	count = calcBricks(grid);

	print2DV(grid);
	for (int i = 0; i < hits.size(); i++) {
		row = hits[i][0];
		col = hits[i][1];
		if (grid[row][col] == 1) {
			grid[row][col] = 0;
			count --;
		}
		print2DV(grid);
		updatedCount = calcBricks(grid);
		print2DV(grid);
		r.push_back(count - updatedCount);
		count = updatedCount;
	}

	return r;
}
