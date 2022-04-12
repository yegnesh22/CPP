/*
 * Solution.cpp
 *
 *  Created on: Mar 24, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <fstream>

extern vector<ti> t;

class Solution {
public:
	void dfs(size_t me, size_t anc, vector<vector<int>> &par, vector<vector<int>> &res);
	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges);
};

void Solution::dfs(size_t me, size_t anc, vector<vector<int>> &par, vector<vector<int>> &res)
{
	if (res[me].empty() || res[me].back() != anc) {
		if (me != anc)
			res[me].push_back(anc);
		for (size_t j = 0; j < par[me].size(); j++)
			dfs(par[me][j], anc, par, res);
	}
}

vector<vector<int>> Solution::getAncestors(int n, vector<vector<int>>& edges)
{
	vector<vector<int>> par(n), res(n);

	for (size_t i = 0; i < edges.size(); i++)
		par[edges[i][0]].push_back(edges[i][1]);

	for (int i = 0; i < n; i++)
		dfs(i, i, par, res);

	return res;
}

int main()
{
	for (size_t i = 0; i < t.size(); i++) {
		Solution* s = new Solution();
		t[i].ao = s->getAncestors(t[i].n, t[i].edges);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
		delete(s);
	}
	return 0;
}
