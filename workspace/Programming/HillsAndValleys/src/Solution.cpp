/*
 * Solution.cpp
 *
 *  Created on: Mar 20, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int countHillValley(vector<int>& nums);
};

int Solution::countHillValley(vector<int>& nums)
{
	int ns = nums.size();
	int hCount = 0;
	int vCount = 0;
	int lindex;
	int rindex;

	for (int i = 1; i < (ns - 1); i++) {
		lindex = i - 1;
		while (nums[lindex] == nums[i])
			lindex--;
		rindex = i + 1;
		while (nums[rindex] == nums[i]) {
			i++;
			rindex++;
		}
		if ((nums[i] > nums[lindex]) && (nums[i] > nums[rindex]))
			hCount++;
		else if ((nums[i] < nums[lindex]) && (nums[i] < nums[rindex]))
			vCount++;
	}

	return hCount + vCount;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> a, int e): nums(a), eo(e) {}
};

vector<ti> t = {
	ti({2,4,1,1,6,5}, 3),
	ti({6,6,5,5,4,1}, 0),
	ti({5,7,7,1,7}, 2),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countHillValley(t[i].nums);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}


