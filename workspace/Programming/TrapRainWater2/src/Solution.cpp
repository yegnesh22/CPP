/*
 * Solution.cpp
 *
 *  Created on: Mar 7, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap);
};

typedef pair<int, int> loc;
typedef pair<int, loc> cell;

int Solution::trapRainWater(vector<vector<int>>& heightMap)
{
	priority_queue<cell, vector<cell>, greater<cell>> pq;
	vector<loc> bounds = {
			loc(0,-1),
			loc(0,1),
			loc(-1,0),
			loc(1,0),
	};
	int nc = heightMap[0].size();
	int nr = heightMap.size();
	int r, c, h, cr, cc, ch;
	bool visited[nr][nc];
	int vol = 0;

	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			if (i == 0 || i == nr-1 || j == 0 || j == nc-1) {
				visited[i][j] = true;
				pq.push(cell(heightMap[i][j],loc(i, j)));
			} else {
				visited[i][j] = false;
			}
		}
	}

	while(!pq.empty()) {
		cell f = pq.top();
		pq.pop();
		h = f.first;
		r = f.second.first;
		c = f.second.second;
		for (int i = 0; i < bounds.size(); i++) {
			cr = r + bounds[i].first;
			cc = c + bounds[i].second;
			if (cr >= 0 && cr < nr && cc >= 0 && cc < nc && !visited[cr][cc]) {
				visited[cr][cc] = true;
				ch = heightMap[cr][cc];
				vol += max(0, h - ch);
				pq.push(cell(max(h, ch),loc(cr, cc)));
			}
		}
	}

	return vol;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> hmap;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.hmap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}},
				.eo = 4,
		},
		{
				.hmap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}},
				.eo = 10,
		}
};

int main()
{
	Solution* s =  new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->trapRainWater(t[i].hmap);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
