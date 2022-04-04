/*
 * Solution.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	int triangularSum(vector<int>& nums) {
		int ns = nums.size();
		vector<vector<int>> r(ns, vector<int> {});

		r[0] = nums;

		for (int i = 1; i < ns; i++) {
			for (int j = 0; j < (r[i-1].size() - 1); j++)
				r[i].push_back((r[i-1][j]+r[i-1][j+1]) % 10);
		}

		//cout << "returning " << r[ns-1][0] << endl;
		return r[ns-1][0];
	}
};

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> n, int e): nums(n), eo(e) {}
};

vector<ti> t = {
		ti({1,2,3,4,5}, 8),
		ti({5}, 5),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->triangularSum(t[i].nums);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass " << endl;
	}

	return 0;
}
