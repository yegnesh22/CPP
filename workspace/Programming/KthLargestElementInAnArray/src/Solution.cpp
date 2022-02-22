/*
 * Solution.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k);
};

int Solution::findKthLargest(vector<int>& nums, int k)
{
	int ns = nums.size();
	sort(nums.begin(), nums.end());
	return (nums[ns - k]);
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = {3,2,1,5,6,4},
				.k = 2,
				.eo = 5,
		},
		{
				.n = {3,2,3,1,2,4,5,5,6},
				.k = 4,
				.eo = 4,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findKthLargest(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
