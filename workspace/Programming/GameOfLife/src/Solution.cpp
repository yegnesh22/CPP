/*
 * Solution.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		vector<vector<int>>neighbours = {
				{-1, -1},
				{-1, 0},
				{-1, 1},
				{0, -1},
				{0, 1},
				{1, -1},
				{1, 0},
				{1, 1},
		};
		vector<tuple<int,int,int>> changedI;
		int neighS = neighbours.size();
		int nc = board[0].size();
		int nr = board.size();

		for (int i = 0; i < nr; i++) {
			for (int j = 0; j < nc; j++) {
				int aNC = 0;
				for (int k = 0; k < neighS; k++) {
					int r = i + neighbours[k][0];
					int c = j + neighbours[k][1];

					if ((r >= 0 && r < nr) && (c >= 0 && c < nc))
						aNC += board[r][c];
				}
#ifdef DEBUG
				cout << "[" << i << "," << j << "]=" << aNC << endl;
#endif
				if (board[i][j] == 0) {
					if (aNC == 3)
						changedI.push_back(make_tuple(i, j, 1));
				} else {
					if (aNC < 2 || aNC > 3)
						changedI.push_back(make_tuple(i, j, 0));
				}
			}
		}

		for (int i = 0; i < changedI.size(); i++) {
			int r = get<0>(changedI[i]);
			int c = get<1>(changedI[i]);
#ifdef DEBUG
			cout << "board[" << r << "][" << c << "]=" << board[r][c] << flush;
#endif
			board[r][c] = get<2>(changedI[i]);
#ifdef DEBUG
			cout << " --> " << board[r][c] << endl;
#endif
		}
	}
};

struct ti {
	vector<vector<int>> board;
	vector<vector<int>> eo;
	ti(vector<vector<int>> b, vector<vector<int>> e): board(b), eo(e) {}
};

vector<ti> tests = {
		ti({{0,1,0},{0,0,1},{1,1,1},{0,0,0}}, {{0,0,0},{1,0,1},{0,1,1},{0,1,0}}),
		ti({{1,1},{1,0}},{{1,1},{1,1}}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& test: tests) {
		s->gameOfLife(test.board);
		assert(test.eo == test.board);
		cout << i << " -- pass" << endl;
		i++;
	}
	return 0;
}
