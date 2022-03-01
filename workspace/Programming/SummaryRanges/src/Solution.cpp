/*
 * Solution.cpp
 *
 *  Created on: Feb 28, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums);
};

vector<string> Solution::summaryRanges(vector<int>& nums)
{
	int ns = nums.size();
	int right = 0;
	int left = 0;
	string rstr;
	vector<string> result;

    if (nums.empty())
        return result;

	for (int i = 0; i < ns - 1; i++) {
		if (nums[i] + 1 == nums[i+1])
			right = i;
		else {
			right = i;
			if (left == right)
				rstr = to_string(nums[left]);
			else
				rstr = to_string(nums[left]) + "->" + to_string(nums[right]);
			//cout << "pushing back -- " << rstr << endl;
			result.push_back(rstr);
			left = i + 1;
			right = i + 1;
		}
	}

    // last one
    right = ns - 1;
    if (left == right)
        rstr = to_string(nums[left]);
    else
        rstr = to_string(nums[left]) + "->" + to_string(nums[right]);
    //cout << "pushing back -- " << rstr << endl;
    result.push_back(rstr);

	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	vector<string> eo;
	vector<string> ao;
};

vector<ti> t = {
		{
				.nums = {0,1,2,4,5,7},
				.eo = {"0->2","4->5","7"},
		},
		{
				.nums = {0,2,3,4,6,8,9},
				.eo = {"0","2->4","6","8->9"},
		},
		{
				.nums = {-1},
				.eo = {"-1"},
		},
		{
				.nums = {},
				.eo = {},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->summaryRanges(t[i].nums);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
