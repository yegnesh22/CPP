/*
 * Solution.cpp
 *
 *  Created on: Apr 24, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> grid;
typedef pair<grid, int> tc;

int getSecondsRequired(int R, int C, vector<vector<char>> G) {
	// Write your code here
	vector<vector<int>> adj = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	vector<vector<int>> cost (R, vector<int> (C, INT_MAX));
	map<char, vector<grid>> tp;
	int minC = INT_MAX;
	queue<tc> twq;

	for (int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			grid g(i, j);
			switch(G[i][j]) {
			case 'S':
				twq.push(tc(g, 0));
				break;
			case 'E':
			case '#':
			case '.':
				break;
			default:
				tp[G[i][j]].push_back(g);
				break;
			}
		}
	}

	while (!twq.empty()) {
		tc loc = twq.front();
		twq.pop();
		grid g = loc.first;
		int cr = g.first;
		int cc = g.second;
		int nextC = ++loc.second;
		for (int i = 0; i < 4; i++) {
			int nr = cr + adj[i][0];
			int nc = cc + adj[i][1];
			grid ng(nr, nc);
			if ((nr >= 0 && nr < R) && (nc >= 0 && nc < C)) {
				if (G[nr][nc] == '#' || G[nr][nc] == 'S') // Wall/Start - Ignore
					continue;
				if (G[nr][nc] == 'E') {
					cost[nr][nc] = min(cost[nr][nc], nextC);
					minC = min(minC, cost[nr][nc]);
				} else if (G[nr][nc] == '.') {
					if (cost[nr][nc] > nextC) {
						twq.push(tc(ng, nextC));
						cost[nr][nc] = nextC;
					}
				} else { // teleport
					char tpc = G[nr][nc];
					for (auto it = tp[tpc].begin(); it != tp[tpc].end(); it++) {
						grid gloc = *it;
						if (nextC < cost[nr][nc] && (gloc.first == nr && gloc.second == nc)) {
							twq.push(tc(ng, nextC));
							cost[nr][nc] = nextC;
						}
						if (((nextC+1) < cost[gloc.first][gloc.second]) && !(gloc.first == nr && gloc.second == nc)) {
							twq.push(tc(gloc, nextC+1));
							cost[gloc.first][gloc.second] = nextC+1;
						}
					}
				}
			}
		}
	}

	if (minC == INT_MAX)
		return -1;
	return minC;
}

struct ti {
	int R;
	int C;
	vector<vector<char>> G;
	int EO;
	int AO;
	ti(int R, int C, vector<vector<char>> G, int EO): R(R), C(C), G(G), EO(EO) {}
};

vector<ti> tests = {
		ti(3,3, {{'.','E','.'}, {'.','#','E'},{'.','S','#'}}, 4),
		ti(3,4, {{'a','S','.','b'}, {'#','#','#','#'},{'E','b','.','a'}},4),
		ti(1,9, {{'x','S','.','.','x','.','.','E','x'}},3),
		ti(3,4, {{'a','.','S','a'}, {'#','#','#','#'},{'E','b','.','b'}},-1),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.AO = getSecondsRequired(t.R, t.C, t.G);
		assert(t.AO == t.EO);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
