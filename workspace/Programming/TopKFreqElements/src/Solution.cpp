/*
 * Solution.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k);
};

struct data {
	int num;
	int freq;
};

vector<int> Solution::topKFrequent(vector<int>& nums, int k)
{
	vector<int> result;
	map<int, int>f;
	int i;

	for (i = 0; i < nums.size(); i++) {
		if (f.find(nums[i]) == f.end()) {
			f.insert(pair<int, int>(nums[i], 1));
		} else
			f[nums[i]]++;
	}

	// Create a priority queue with the count as the key.
	// As soon as we have k keys, stop.
	auto cmp = [&f](int a, int b) { return f[a] < f[b]; };
	priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

	for (auto it = f.begin(); it != f.end(); it++)
		pq.push(it->first);

	for (i = 0; i < k; i++) {
		result.push_back(pq.top());
		pq.pop();
	}

	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.n = {1,1,1,2,2,3},
				.k = 2,
				.eo = {1,2},
		},
		{
				.n = {1},
				.k = 1,
				.eo = {1},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->topKFrequent(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
