/*
 * Solution.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct stop {
	int r;
	int c;
	int nsteps;
	stop(): r(0), c(0), nsteps(0) {}
	stop(int x, int y, int ns): r(x), c(y), nsteps(ns) {}
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid);
};

int Solution::shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
	vector<vector<int>> adj = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	size_t rc = grid.size();
	size_t cc = grid[0].size();
	vector<vector<int>> nsteps(rc, vector<int> (cc, -1));
	queue<stop*> wq;
	int nc, nr;

	if (grid[0][0] == 0) {
		wq.push(new stop(0,0, 1));
		nsteps[0][0] = 1;
	}

	while (!wq.empty()) {
		stop* cstop = wq.front();
		wq.pop();
		for (int i = 0; i < 8; i++) {
			nr = cstop->r + adj[i][0];
			nc = cstop->c + adj[i][1];

			if (((nc >= 0) && (nc < cc)) && ((nr >= 0) && (nr < rc))) {
				if (grid[nr][nc] == 1) // Ignore the grids which are not 0
					continue;
				if ((nsteps[nr][nc] == -1) || (nsteps[nr][nc] > (cstop->nsteps + 1))) {
						nsteps[nr][nc] = cstop->nsteps + 1;
						wq.push(new stop(nr, nc, (cstop->nsteps + 1)));
				}
			}
		}
	}

	return nsteps[rc-1][cc-1];
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = {{0,1},{1,0}},
				.eo = 2,
		},
		{
				.n = {{0,0,0},{1,1,0},{1,1,0}},
				.eo = 4,
		},
		{
				.n = {{1,0,0},{1,1,0},{1,1,0}},
				.eo = -1,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->shortestPathBinaryMatrix(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
