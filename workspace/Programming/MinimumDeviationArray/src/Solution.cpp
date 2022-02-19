/*
 * Solution.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

class Solution {
#ifdef DEBUG
private:
	void printV(vector<int> nums);
#endif
public:
	int minimumDeviation(vector<int>& nums);
	void modifyArr(vector<int>& n, vector<int>& a, int l);
};

#ifdef DEBUG
void Solution::printV(vector<int> nums)
{
	cout << "v --> " << flush;
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " " << flush;
	cout << endl;
}
#endif

void Solution::modifyArr(vector<int>& n, vector<int>& a, int l)
{
	int as = a.size();

	for (int i = 0; i < as; i++) {
		if ((a[i] != l) && (a[i] <= n[i]))
			a[i] <<= 1;
	}
}

int Solution::minimumDeviation(vector<int>& nums)
{
	int ns = nums.size();
	priority_queue<int> maxV;
	int minE = INT_MAX;
	int minD = INT_MAX;
	int cmax;
	int n;

	// Create array with possible maxs
	// Increase all odds by multiplying it by 2.
	// Leave the evens as they are already at the max.
	for (int i = 0; i < ns; i++) {
		n = nums[i];
		if (n & 0x01) {
			n <<= 1;
		}
		maxV.push(n);
		minE = min(minE, n);
	}

	// Keep reducing the maximums until maxs cant be reduced further.
	// Priority queue can return the max value in log(n) time.
	// Keep track of the minimum in the minE variable.s
	while (!maxV.empty()) {
		cmax = maxV.top();
		maxV.pop();
		minD = min(minD, cmax - minE);
		if (!(cmax & 0x1)) {
			cmax >>= 1;
			maxV.push(cmax);
			minE = min(minE, cmax);
		} else
			break;
	}

	return minD;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = {1,2,3,4},
				.eo = 1,
		},
		{
				.n = {4,1,5,20,3},
				.eo = 3,
		},
		{
				.n = {2,10,8},
				.eo = 3,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minimumDeviation(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
