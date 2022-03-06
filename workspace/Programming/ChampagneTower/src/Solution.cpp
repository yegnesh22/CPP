/*
 * Solution.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: ysiyer
 */

#include <iostream>

using namespace std;

/*
 * Instead of keeping track of how much champagne should end up in a glass,
 * keep track of the total amount of champagne that flows through a glass.
 *
 * For example, if poured = 10 cups are poured at the top, then the total
 * flow-through of the top glass is 10; the total flow-through of each glass
 * in the second row is 4.5, and so on.
 *
 * Algorithm:
 *
 * In general, if a glass has flow-through X, then Q = (X - 1.0) / 2.0 quantity
 * of champagne will equally flow left and right. We can simulate the entire pour
 *  for 100 rows of glasses. A glass at (r, c) will have excess champagne flow
 *  towards (r+1, c) and (r+1, c+1).
 *
 */

class Solution {
public:
	double champagneTower(int poured, int query_row, int query_glass);
};

double Solution::champagneTower(int poured, int query_row, int query_glass)
{
	double glass[102][102] = {0.0};
	double q;

	glass[0][0] = poured;

	for (int r = 0; r <= query_row; r++) {
		for (int c = 0; c <= r; c++) {
			q = (glass[r][c] - 1.0) / 2;
			if (q > 0) {
				glass[r+1][c] += q;
				glass[r+1][c+1] += q;
			}
		}
	}

	if (glass[query_row][query_glass] < 1)
		return glass[query_row][query_glass];
	else
		return 1;
}

int main()
{
	Solution* s = new Solution();

	cout << s->champagneTower(1, 1, 1) << endl;
	cout << s->champagneTower(2, 1, 1) << endl;
	cout << s->champagneTower(100000009, 33, 17) << endl;
	cout << s->champagneTower(25, 6, 1) << endl;
	return 0;
}
