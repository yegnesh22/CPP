/*
 * Solution.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	long long minimalKSum(vector<int>& nums, int k);
};

long long Solution::minimalKSum(vector<int>& nums, int k)
{
	int ns = nums.size();
	long long sum = 0;
	int end;
	int st;

	sort(nums.begin(), nums.end());

	st = 1;
	end = nums[0];

	while (st < end && k > 0) {
#ifdef DEBUG
		cout << "Adding number " << st << endl;
#endif
		sum += st;
		st++;
		k--;
	}

	for (int i = 1; i < ns && k > 0; i++) {
		st = nums[i - 1] + 1;
		end = nums[i];

		while (st < end && k > 0) {
#ifdef DEBUG
			cout << "Adding number " << st << endl;
#endif
			sum += st;
			st++;
			k--;
		}
	}

	st = nums[ns - 1] + 1;
	while (k > 0) {
		sum += st;
		st++;
		k--;
	}

#ifdef DEBUG
	cout << "returning sum " << sum << endl;
#endif
	return sum;
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
		ti({1,4,25,10,25}, 2, 5),
		ti({5,6}, 6, 25),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minimalKSum(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}
}
