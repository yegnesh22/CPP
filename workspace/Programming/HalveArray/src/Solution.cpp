/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
	int halveArray(vector<int>& nums);
};

int Solution::halveArray(vector<int>& nums)
{
	priority_queue<double> wq;
	int ns = nums.size();
	int numOps = 0;
	double mS = 0;
	double iS;
	double v;

	for (int i = 0; i < ns; i++) {
		mS += nums[i];
		wq.push(nums[i]);
	}
	iS = mS;

	while (iS > (mS / 2)) {
		v = wq.top();
		wq.pop();
		if (v == 0)
			return numOps;
		iS = iS - v + (v / 2);
		//cout << iS  << " " << v << " " << v/2 << endl;
		wq.push(v / 2);
		numOps++;
	}

	return numOps;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> a, int e): nums(a), eo(e) {}
};

vector<ti> t = {
		ti({5,19,8,1}, 3),
		ti({3,8,20}, 3),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->halveArray(t[i].nums);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
