/*
 * Solution.cpp
 *
 *  Created on: Mar 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k);
};

typedef vector<int> loc;
typedef pair<int, loc> qdata;
typedef priority_queue<qdata, vector<qdata>, greater<qdata>> pwq;

int Solution::kthSmallest(vector<vector<int>>& matrix, int k)
{
	int nc = matrix[0].size();
	int nr = matrix.size();
	int cnt = 1;
	qdata val;
	int r, c;
	pwq wq;

	// Push the first row
	for (int j = 0; j < nc; j++)
		wq.push({matrix[0][j], {0, j}});

    // Pop k elements from the q and push the corresponding elements
    //  in the next row back in.
	while(!wq.empty() && cnt < k) {
		val = wq.top();
		wq.pop();

		r = val.second[0];
		c = val.second[1];

		if (r+1 < nr)
			wq.push({matrix[r+1][c], {r+1,c}});

		cnt++;
	}

	return wq.top().first;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> m;
	int k;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.m = {{1,5,9},{10,11,13},{12,13,15}},
				.k = 8,
				.eo = 13,
		},
		{
				.m = {{-5}},
				.k = 1,
				.eo = -5,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->kthSmallest(t[i].m, t[i].k);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
