/*
 * Solution.cpp
 *
 *  Created on: Feb 17, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct wd {
	int s;
	multiset<int> ms;
	wd(multiset<int> wms, int ws): s(ws), ms(wms) {}
};

class Solution {
public:
	void printV(vector<int> v);
	void printVV(vector<vector<int>> v);
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

void Solution::printV(vector<int> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ", " << flush;
		}
	cout << "}" << flush;
}

void Solution::printVV(vector<vector<int>> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << ", " << flush;
		}
		cout << "}" << flush;
	}
	cout << "}" << flush;
}

vector<vector<int>> Solution::combinationSum(vector<int>& candidates, int target)
{
	int nc = candidates.size();
	set<vector<int>> rset;
	int wt = target;
	queue<wd*> wq;
	wd* ws;
	int is;

	sort(candidates.begin(), candidates.end());
	for (int i = 0; i < nc && candidates[i] <= target; i++)
			wq.push(new wd(multiset<int> {candidates[i]}, candidates[i]));

	while(!wq.empty()) {
		ws = wq.front();
		wq.pop();

		if (ws->s == target) {
			vector<int> v(ws->ms.begin(),ws->ms.end());
			rset.insert(v);
			continue;
		}

		for (int i = 0; ((i < nc) && ((ws->s + candidates[i]) <= target)); i++) {
			wd* ne = new wd(ws->ms, ws->s);
			ne->ms.insert(candidates[i]);
			ne->s += candidates[i];
			wq.push(ne);
		}
	}

	vector<vector<int>> rv(rset.begin(), rset.end());
	printVV(rv);
	cout << endl;
	return rv;
}

struct ti {
	vector<int> c;
	int t;
};

vector<ti> t = {
		{
				.c = {2,3,6,7},
				.t = 7,
		},
		{
				.c = {2},
				.t = 1,
		},
		{
				.c = {2,3,5},
				.t = 8,
		},

};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++)
		s->combinationSum(t[i].c, t[i].t);
	return 0;
}
