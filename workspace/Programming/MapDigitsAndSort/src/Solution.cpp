/*
 * Solution.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>

#define DEBUG

using namespace std;

struct cdata {
	int mn;
	int n;
	int i;
	cdata(int mapped, int orig, int index):mn(mapped), n(orig), i(index) {}
};

struct cmp {
	bool operator() (const struct cdata& a, const struct cdata& b) const {
		if (a.mn == b.mn)
			return a.i > b.i;
		return a.mn > b.mn;
	}
};

class Solution {
public:
	vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums);
};

vector<int> Solution::sortJumbled(vector<int>& mapping, vector<int>& nums)
{
	priority_queue<cdata, vector<cdata>, cmp> pwq;
	int ns = nums.size();

	for (int i = 0; i < ns; i++) {
		int multiplier = 1;
		int n = nums[i];
		int mn = 0;
		int d, md;
		if (n == 0)
			mn = mapping[0];
		while (n) {
			d = n % 10;
			n = n / 10;
			md = mapping[d];
			mn += (md * multiplier);
			multiplier *= 10;
		}
#ifdef DEBUG
		cout << i << " mapped " << nums[i] << " as " << mn << endl;
#endif
		pwq.push(cdata(mn, nums[i], i));
	}

	vector<int> result;

	while (!pwq.empty()) {
		result.push_back(pwq.top().n);
		pwq.pop();
	}

	return result;
}

struct ti {
	vector<int> mapping;
	vector<int> nums;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> m, vector<int> n, vector<int> e): mapping(m), nums(n), eo(e) {}
};

vector<ti> t = {
		ti({8,9,4,0,2,1,3,5,7,6}, {991,338,38}, {338,38,991}),
		ti({0,1,2,3,4,5,6,7,8,9}, {789,456,123}, {123,456,789}),
		ti({9,8,7,6,5,4,3,2,1,0}, {0,1,2,3,4,5,6,7,8,9}, {9,8,7,6,5,4,3,2,1,0}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->sortJumbled(t[i].mapping, t[i].nums);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
	}

	return 0;
}
