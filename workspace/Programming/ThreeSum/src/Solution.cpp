/*
 * Solution.cpp
 *
 *  Created on: Feb 17, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	void printV(vector<vector<int>> v);
    vector<vector<int>> threeSum(vector<int>& nums);
};

void Solution::printV(vector<vector<int>> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " " << flush;
		}
		cout << "}," << flush;
	}
	cout << "}" << endl;
}

vector<vector<int>> Solution::threeSum(vector<int>& nums)
{
	int ns = nums.size();

	// Return empty if the number of elements are less than 3.
	if (ns < 3)
		return vector<vector<int>> {};

	set<vector<int>> result;
	map<int, int> lkp;

	// Create the lookup first. Lookup for easy retrieval.
	for (int i = 0; i < ns; i++) {
		if (lkp.find(nums[i]) == lkp.end())
			lkp.insert(pair<int, int>(nums[i], 1));
		else
			lkp[nums[i]]++;
	}

	if (lkp.find(0) != lkp.end()) {
		if (lkp[0] >= 3)
			result.insert({0,0,0});
	}

	int k1, k2, k3;
	int nk = lkp.size();
	for (auto it = lkp.begin(); it != lkp.end(); it++) {
		k1 = it->first;
		lkp[k1]--;
		if ((lkp[k1] >= 1) && (lkp.find(0 - (2 * k1)) != lkp.end())) {
			lkp[k1] --;
			lkp[0-(2*k1)]--;
			 if (lkp[k1] >= 0 && lkp[0-(2*k1)] >= 0) {
				 vector<int> ir {k1, k1, -(2 * k1)};
				 sort(ir.begin(), ir.end());
				 result.insert(ir);
			 }
		}

		for (auto its = next(it,1); its != lkp.end(); its++) {
			k2 = its->first;
			lkp[k2]--;
			k3 = 0 - (k1 + k2);
			if ((lkp.find(k3) != lkp.end()) && (lkp[k3] > 0)) {
				vector<int> ir {k1, k2, k3};
				sort(ir.begin(), ir.end());
				result.insert(ir);
			}
			lkp[k2]++;
		}
		lkp[k1]++;
	}

	vector<vector<int>> v(result.begin(), result.end());
	printV(v);
	return v;
}

struct ti {
	vector<int> n;
};

vector<ti> t = {
		{
				.n = {-1,0,1,2,-1,-4},
		},
		{
				.n = {},
		},
		{
				.n = {0},
		},
		{
				.n = {-2,0,0,2,2},
		},
#if 0
		{
				.n = {34,55,79,28,46,33,2,48,31,-3,84,71,52,-3,93,15,21,-43,57,-6,86,56,94,74,83,-14,28,-66,46,-49,62,-11,43,65,77,12,47,61,26,1,13,29,55,-82,76,26,15,-29,36,-29,10,-70,69,17,49}
		},
#endif
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		s->threeSum(t[i].n);
	}
	return 0;
}
