/*
 * Solution.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<int> findLonely(vector<int>& nums);
};

vector<int> Solution::findLonely(vector<int>& nums)
{
	int nl = nums.size();
	vector<int> result;
	bool lonely;
	int i = 0;
	int j;

    if (nl < 2)
        return nums;

	sort(nums.begin(), nums.end());
	while(i < (nl - 1)) {
		j = i;
		lonely = true;
		while ((j < nl - 1) && (nums[j+1] - nums[j]) <= 1) {
			lonely = false;
			j++;
		}
		if (lonely) {
			result.push_back(nums[i]);
			i++;
		} else
			i = j+1;
	}

    // Check for the last entry
	if ((nums[nl-1] - nums[nl-2]) > 1)
		result.push_back(nums[nl-1]);

	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.n = {10,6,5,8},
				.eo = {8,10},
		},
		{
				.n = {1,3,5,3},
				.eo = {1,5},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findLonely(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
