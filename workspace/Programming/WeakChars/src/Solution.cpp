/*
 * Solution.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	void printV(vector<vector<int>> p);
	int numberOfWeakCharacters(vector<vector<int>>& properties);
};

void Solution::printV(vector<vector<int>> p)
{
	cout << "{" << flush;
	for (int i = 0; i < p.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < p[i].size(); j++)
			cout << p[i][j] << "," << flush;
		cout << "}," << flush;
	}
	cout << "}" << endl;
}

bool comp(vector<int>& a, vector<int>& b)
{
	return ((a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]));
}

int Solution::numberOfWeakCharacters(vector<vector<int>>& properties)
{
	int np = properties.size() - 1;
	int nWC = 0;
	int res = -1;

	sort(properties.begin(), properties.end(), comp);
	printV(properties);
	for (int i = np; i >= 0; i--) {
		if (properties[i][1] < res)
			nWC++;
		res = max(res, properties[i][1]);
	}

	return nWC;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> p;
	int eo;
	int ao;
};


vector<ti> t = {
		{
				.p = {{5,5},{6,3},{3,6}},
				.eo = 0,
		},
		{
				.p = {{2,2},{3,3}},
				.eo = 1,
		},
		{
				.p = {{1,5},{10,4},{4,3}},
				.eo = 1,
		},
		{
				.p = {{1,1},{2,1},{2,2},{1,2}},
				.eo = 1,
		},
		{
				.p = {{7,7},{1,2},{9,7},{7,3},{3,10},{9,8},{8,10},{4,3},{1,5},{1,5}},
				.eo = 6,
		}
};

int main()
{
	Solution* s =  new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->numberOfWeakCharacters(t[i].p);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
