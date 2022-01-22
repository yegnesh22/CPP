/*
 * Solution.cpp
 *
 *  Created on: Jan 21, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	virtual void rotate(vector<vector<int>>& matrix) = 0;
};

struct Coordinates {
	int row;
	int col;
};

// Rotate by 4 cells method
class Default: public Solution {
public:
	void flip(vector<vector<int>>& matrix, int r, int c) {
		if (r >= c) // no need to flip
			return;
		// Flip the inner square
		flip(matrix, r+1, c-1);

		// Flip the current square
		// square is (r,r) -- (r,c)
		//           (c,r) -- (c,c)
		for (int i = 0; i < (c - r); i++) {
			int t1, t2;
			vector<Coordinates> co = {
					{
							.row = r,
							.col = r+i,
					},
					{
							.row = r+i,
							.col = c,
					},
					{
							.row = c,
							.col = c-i,
					},
					{
							.row = c-i,
							.col = r,
					},
			};

			t1 = matrix[co[1].row][co[1].col];
			matrix[co[1].row][co[1].col] = matrix[co[0].row][co[0].col];
			t2 = matrix[co[2].row][co[2].col];
			matrix[co[2].row][co[2].col] = t1;
			t1 = matrix[co[3].row][co[3].col];
			matrix[co[3].row][co[3].col] = t2;
			matrix[co[0].row][co[0].col] = t1;
		}
		return;
	}
	void rotate(vector<vector<int>>& matrix) {
		flip(matrix, 0, matrix.size() - 1);
	}
};

struct TI {
	vector<vector<int>> i;
	vector<vector<int>> eo;
};

int main()
{
	vector<TI> t = {
			{
					.i = {
							{1,2,3},
							{4,5,6},
							{7,8,9}
					},
					.eo = {
							{7,4,1},
							{8,5,2},
							{9,6,3}
					},
			},
			{
					.i = {
							{5,1,9,11},
							{2,4,8,10},
							{13,3,6,7},
							{15,14,12,16}
					},
					.eo = {
							{15,13,2,5},
							{14,3,4,1},
							{12,6,8,9},
							{16,7,10,11}
					},
			},
	};
	Solution* s = new Default();

	for (int i = 0; i < t.size(); i++) {
		s->rotate(t[i].i);
		cout << "t[" << i << "] "
				<< ((t[i].i == t[i].eo) ? "pass" : "false")
				<< endl;
	}
}
