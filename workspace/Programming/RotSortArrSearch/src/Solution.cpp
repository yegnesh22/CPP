/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	virtual bool search(vector<int>& nums, int target) = 0;
};

class BasicSolution: public Solution {
public:
	bool search(vector<int>& nums, int target) {
		int ns = nums.size();
		int start = 1;
		int incr = 1;
		int end  = ns;

		if (nums[0] == target)
			return true;

		if (nums[0] > target) {
			start = ns - 1;
			incr = -1;
			end = 0;
		}

		for (int i = start; i != end; i += incr) {
			if (nums[i] == target)
				return true;

			if ((i > 1) && (nums[i] > target && nums[i - 1] < target))
				return false;
		}

		return false;
	}
};

struct ti {
	vector<int> i;
	int t;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.i = {2,5,6,0,0,1,2},
				.t = 0,
				.eo = true,
		},
		{
				.i = {2,5,6,0,0,1,2},
				.t = 3,
				.eo = false,
		},
		{
				.i = {2,2,2,3,2,2,2},
				.t = 3,
				.eo = true,
		}
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->search(t[i].i, t[i].t);
		cout << i << " -- r:" << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
