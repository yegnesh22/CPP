/*
 * Solution.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums);
};

int Solution::majorityElement(vector<int>& nums)
{
	int ns = nums.size();

	sort(nums.begin(), nums.end());
	int mid = ns / 2;

	return nums[mid];
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = {3,2,3},
				.eo = 3,
		},
		{
				.n = {2,2,1,1,1,2,2},
				.eo = 2,
		}
};

int main()
{
	Solution* s =  new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->majorityElement(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
