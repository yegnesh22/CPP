/*
 * Solution.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	int h;
	vector<int> ml;
	vector<int> it;
	int eo;
	int ao;
};

class Solution {
public:
	int findrTime(int e, vector<int>& m,
			vector<int>& it, vector<int>& rt);
	int numOfMinutes(int n, int headID,
			vector<int>& manager,
			vector<int>& informTime);
};

int Solution::findrTime(int e, vector<int>& m,
		vector<int>& it, vector<int>& rt)
{
	if (rt[e] == -1)
		rt[e] = findrTime(m[e], m, it, rt) + it[m[e]];

	return rt[e];
}

int Solution::numOfMinutes(int n, int headID,
		vector<int>& manager,
		vector<int>& informTime)
{
	vector<int> rtime(n, -1);
	rtime[headID] = 0;

	for (int i = 0; i < n; i++)
		rtime[i] = findrTime(i, manager, informTime, rtime);

	return *max_element(rtime.begin(), rtime.end());
}

vector<ti> t = {
		{
				.n = 1,
				.h = 0,
				.ml = {-1},
				.it = {0},
				.eo = 0,
		},
		{
				.n = 6,
				.h = 2,
				.ml = {2,2,-1,2,2,2},
				.it = {0,0,1,0,0,0},
				.eo = 1,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->numOfMinutes(t[i].n, t[i].h, t[i].ml, t[i].it);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
