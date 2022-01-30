/*
 * main.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

/*
 * Logic:
 *
 * Since robot can move either down or right, there is only one path to reach
 * the cells in the first row: right->right->...->right.
 *
 * The same is valid for the first column, though the path here is down->down->
 * ...->down.
 *
 * What about the "inner" cells (m, n)? To such cell one could move either from
 * the cell on the left (m, n - 1), or from the cell above (m - 1, n). That means
 * that the total number of paths to move into (m, n) cell is uniquePaths(m - 1, n)
 * + uniquePaths(m, n - 1).
 * i.e uniquePaths(m, n) = uniquePaths(m - 1, n) + uniquePaths(m, n - 1)
 *
 * uniquePaths(0, *) = 1; // First row only 1 unique path
 * uniquePaths(*, 0) = 1; // First column only 1 unique path
 *
 * If (0,0) has an obstacle there are no paths to the destination
 * If there is an obstacle in the first row, all columns after that in the first row
 * is not reachable. So their uniquePaths must be set to 0.
 * Similarly, if there is an obstacle in the first column, then all rows after that in
 * the first column are not reachable and must be set to 0.
 */

#include <ti.h>
#include <DP.h>

vector<ti> t = {
		{
				.og = {{0,0,0},{0,1,0},{0,0,0}},
				.eo = 2,
		},
		{
				.og = {{0,0},{1,1},{0,0}},
				.eo = 0,
		}
};

int main()
{
	Solution *s =  new DP();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->uniquePathsWithObstacles(t[i].og);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
