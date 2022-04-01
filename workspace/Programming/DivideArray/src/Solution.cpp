/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool divideArray(vector<int>& nums);
};

bool Solution::divideArray(vector<int>& nums)
{
	int ns = nums.size();
	map<int, int> lkp;

	if (ns & 1)
		return false;

	for (int i = 0; i < ns; i++)
		lkp[nums[i]]++;

	for (auto it = lkp.begin(); it != lkp.end(); it++) {
		if (lkp[it->first] & 0x1)
			return false;
	}

	return true;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	bool eo;
	bool ao;
	ti(vector<int> a, bool e): nums(a), eo(e) {}
};

vector<ti> t = {
		ti({3,2,3,2,2,2}, true),
		ti({1,2,3,4}, false),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->divideArray(t[i].nums);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
