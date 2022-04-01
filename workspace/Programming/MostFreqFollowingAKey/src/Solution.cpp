/*
 * Solution.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second < b.second;
	}
};

class Solution {
public:
	int mostFrequent(vector<int>& nums, int key);
};

int Solution::mostFrequent(vector<int>& nums, int key)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pwq;
	vector<int> freq(1001, 0);
	int ns = nums.size();

	for (int i = 0; i < (ns - 1); i++) {
		if (nums[i] == key) {
			freq[nums[i+1]]++;
			pwq.push({nums[i+1], freq[nums[i+1]]});
		}
	}

	return pwq.top().first;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")
struct ti {
	vector<int> n;
	int k;
	int eo;
	int ao;
	ti(vector<int> tn, int tk, int teo): n(tn), k(tk), eo(teo) {}
};

vector<ti> t = {
		ti({1,100,200,1,100}, 1, 100),
		ti({2,2,2,2,3}, 2, 2),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->mostFrequent(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
