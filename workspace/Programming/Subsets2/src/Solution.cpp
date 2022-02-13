/*
 * Solution.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
	void printV(vector<vector<int>> v);
};

void Solution::printV(vector<vector<int>> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << "," << flush;
		cout << "}," << flush;
	}
	cout << "}" << endl;
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
	map<vector<int>, bool> ans;
	stack<vector<int>> psStk;
	vector<vector<int>> r;
	int ns = nums.size();
	vector<int> wc;
	vector<int> t;

    sort(nums.begin(), nums.end());
	psStk.push(nums);
	r.push_back(nums);
	ans.insert(pair<vector<int>,bool> (t, true));
	while(!psStk.empty()) {
		t = psStk.top();
		psStk.pop();
		for (int i = 0; i < t.size(); i++) {
			wc = t;
			wc.erase(wc.begin() + i);
			if (ans.find(wc) == ans.end()) {
				ans.insert(pair<vector<int>, bool> (wc, true));
				psStk.push(wc);
				r.push_back(wc);
			}
		}
	}

	r.push_back(vector<int> {});
	return r;
}


#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
};

vector<ti> test = {
		{
				.n = {1,2,2},
				.eo = {{},{1},{2},{1,2},{2,2},{1,2,2}},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < test.size(); i++) {
		test[i].ao = s->subsetsWithDup(test[i].n);
		s->printV(test[i].ao);
		cout << i << " -- " << result(test[i]) << endl;
	}

	return 0;
}
