/*
 * Solution.cpp
 *
 *  Created on: Mar 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.n = 2,
				.eo = {0,1,1},
		},
		{
				.n = 5,
				.eo = {0,1,1,2,1,2},
		},
};

class Solution {
public:
	vector<int> countBits(int n);
};

vector<int> Solution::countBits(int n)
{
	vector<int> res(n+1, 0);

	for (int i = 1; i <= n; i++)
		res[i] = res[i >> 1] + (i & 1);

	return res;
}

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countBits(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
