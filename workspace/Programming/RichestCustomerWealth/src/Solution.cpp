/*
 * Solution.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti  {
	vector<vector<int>> i;
	int eo;
	int ao;
};

class Solution {
public:
    virtual int maximumWealth(vector<vector<int>>& accounts) = 0;
};

class BasicSolution : public Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts);
};

int BasicSolution::maximumWealth(vector<vector<int>> &accounts)
{
	int mw = 0;
	int ws;

	for (int i = 0; i < accounts.size(); i++) {
		ws = 0;
		for (int j = 0; j < accounts[i].size(); j++)
			ws += accounts[i][j];
		mw = max(mw, ws);
	}

	return mw;
}

vector<ti> t = {
		{
				.i = {{1,2,3},{3,2,1}},
				.eo = 6,
		},
		{
				.i = {{1,5},{7,3},{3,5}},
				.eo = 10,
		},
		{
				.i = {{2,8,7},{7,1,3},{1,9,5}},
				.eo = 17,
		}
};

int main()
{
	Solution *s =  new BasicSolution();

	for (int i  = 0; i < t.size(); i++) {
		t[i].ao = s->maximumWealth(t[i].i);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
