/*
 * Solution.cpp
 *
 *  Created on: Apr 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	int orangesRotting(vector<vector<int>>& grid) {
		int time = 0;
		int r = grid.size();
		int c = grid[0].size();
		vector<vector<int>> next(r,vector<int>(c, {}));
		vector<vector<int>> cur(grid);
		vector<vector<int>> adj = {{-1, 0},	{0, -1}, {0, 1}, {1, 0}};
		int as = adj.size();
		bool modified;
		int fcount;
		int nc = 0;
		int nr = 0;

		while (1) {
			modified = false;
			fcount = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					next[i][j] = cur[i][j];
					if (cur[i][j] == 1) {
						for (int k = 0; k < as; k++) {
							nr = i + adj[k][0];
							nc = j + adj[k][1];
							if ((nr >= 0 && nr < r) && (nc >= 0 && nc < c)) {
								if (cur[nr][nc] == 2) {
									next[i][j] = 2;
									modified = true;
								}
							}
						}
						if (next[i][j] == 1)
							fcount++;
					}
				}
			}
			if (modified) {
				time++;
				cur = next;
			} else
				break;
		}
		return (fcount == 0) ? time : -1;
	}
};

struct ti {
	vector<vector<int>> grid;
	int eo;
	int ao;
	ti(vector<vector<int>> grid, int eo): grid(grid), eo(eo) {}
};

vector<ti> tests = {
		ti({{2,1,1},{1,1,0},{0,1,1}}, 4),
		ti({{2,1,1},{0,1,1},{1,0,1}}, -1),
		ti({{0,2}}, 0),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.ao = s->orangesRotting(t.grid);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
