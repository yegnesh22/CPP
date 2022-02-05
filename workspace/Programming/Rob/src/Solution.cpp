/*
 * Solution.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> h;
	int eo;
	int ao;
};

class Solution {
public:
    int rob(vector<int>& nums);
    int robFrom(vector<int>& nums, int from, vector<int>& lookup);
};

int Solution::robFrom(vector<int>& nums, int from, vector<int>& lookup)
{
	//cout << from << endl;
	if (from >= nums.size() || from < 0)
		return 0;

	if ((from >= 0 && from <= nums.size()) && (lookup[from] != -1))
		return lookup[from];

	lookup[from] = max(robFrom(nums, from + 1, lookup), robFrom(nums, from + 2, lookup) + nums[from]);
	return lookup[from];
}

int Solution::rob(vector<int>& nums)
{
	vector<int> lookup(nums.size(), -1);
	return robFrom(nums, 0, lookup);
}

vector<ti> t = {
		{
				.h = {1,2,3,1},
				.eo = 4,
		},
		{
				.h = {2,7,9,3,1},
				.eo = 12,
		},
		{
				.h = {114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240},
				.eo = 4173,
		},
		{
				.h = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
				.eo = 0,
		},
};

int main()
{
	for(size_t i = 0; i < t.size(); i++) {
		Solution* s = new Solution();
		t[i].ao = s->rob(t[i].h);
		cout << "ao:" << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
		delete s;
	}
	return 0;
}
