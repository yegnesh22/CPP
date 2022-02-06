/*
 * Solution.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int eo;
	int ao;
};

class Solution {
public:
    int findPeakElement(vector<int>& nums);
};

int Solution::findPeakElement(vector<int>& nums)
{
	nums.insert(nums.begin(), INT_MIN);
	nums.push_back(INT_MIN);

	for (int i = 1; i <= nums.size() - 2; i++) {
		if ((nums[i] > nums[i - 1]) && (nums[i] > nums[i + 1]))
			return i - 1;
		else if (nums[i] < nums[i - 1])
			i++;
	}

	return -1;
}

vector<ti> t = {
		{
				.n = {1,2,3,1},
				.eo = 2,
		},
		{
				.n = {1,1,1,3,5,6,4},
				.eo = 5,
		},
		{
				.n = {1},
				.eo = 0,
		},
		{
				.n = {1,2},
				.eo = 1,
		},
		{
				.n = {3,2,1},
				.eo = 0,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findPeakElement(t[i].n);
		cout << "ao:" << t[i].ao << endl;
		cout << "eo:" << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
