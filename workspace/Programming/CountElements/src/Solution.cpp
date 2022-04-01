/*
 * Solution.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	int countElements(vector<int>& nums);
};

int Solution::countElements(vector<int>& nums)
{
	int ns = nums.size();
	int count  = 0;
	bool lfound;
	bool rfound;
	int l, r;

	sort(nums.begin(), nums.end());

	for (int i = 1; i < (ns - 1); i++) {
		l = i - 1;
		r = i + 1;
		lfound = false;
		rfound = false;
		while (l >= 0) {
			if (nums[l] < nums[i]) {
				lfound = true;
				break;
			}
			l--;
		}
		while (r <= ns - 1) {
			if (nums[i] < nums[r]) {
				rfound = true;
				break;
			}
			r++;
		}
		count += (lfound & rfound);
	}

	cout << "returning " << count << endl;
	return count;
}

struct ti {
	vector<int> nums;
	int eo;
	int ao;
	ti(vector<int> n, int e): nums(n), eo(e) {}
};

vector<ti> t = {
		ti({11,7,2,15}, 2),
		ti({-3,3,3,90}, 2),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countElements(t[i].nums);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
