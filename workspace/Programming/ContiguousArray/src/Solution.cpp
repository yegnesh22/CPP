/*
 * Solution.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int eo;
	int ao;
};

class Solution {
public:
    int findMaxLength(vector<int>& nums);
};

int Solution::findMaxLength(vector<int>& nums)
{
	map<int, vector<int>> indices;
	int ns = nums.size();
	int incr[2] = {-1, 1};
	int count = 0;
	int m = 0;

	indices.insert(pair<int, vector<int>> (0,{0}));
	for(int i = 0; i < ns; i++) {
		count += incr[nums[i]];
		if (indices.find(count) == indices.end())
			indices.insert(pair<int, vector<int>>(count, {i+1}));
		else
			indices[count].push_back(i+1);
	}

	for(auto it = indices.begin(); it != indices.end(); it++) {
		vector<int> v = it->second;
		int vs = v.size();
		for (int i = 0; i < vs; i++) {
			int last = vs - 1;
			m = max(m, v[last] - v[0]);
		}
	}

	return m;
}

vector<ti> t = {
		{
				.n = {0,1},
				.eo = 2,
		},
		{
				.n = {0,0,0,1,1,0,1,0},
				.eo = 6,
		},
		{
				.n = {0,1,0},
				.eo = 2,
		},
		{
				.n = {0},
				.eo = 0,
		},
		{
				.n = {},
				.eo = 0,
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->findMaxLength(t[i].n);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
