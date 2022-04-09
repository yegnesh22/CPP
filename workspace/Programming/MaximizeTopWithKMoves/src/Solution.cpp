/*
 * Solution.cpp
 *
 *  Created on: Mar 26, 2022
 *      Author: ysiyer
 */

#include <assert.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int maximumTop(vector<int>& nums, int k);
};

int Solution::maximumTop(vector<int>& nums, int k)
{
	int ns = nums.size();
	int top_index = 0;
	int p_max = -1;

    if (k == 0)
        return nums[0];

	if (ns == 1) {
        if (k & 0x1)
		    return -1;
        else
            return nums[0];
    }

	if (k == 1) // Only one operation possible. Pop one element from array.
		return nums[1];

	while ((k > 1) && (top_index < (ns - 1))) {
		p_max = max(p_max, nums[top_index]);
		top_index++;
		k--;
	}

	if (k > 1) { // Could have entered the while loop
		int top = nums[top_index];
		if (p_max != -1) // Entered the while loop case
			top = max(top, p_max);
		return top;
	} else
		return max(p_max, nums[top_index + 1]);

	return -1;
}

struct ti {
	vector<int> nums;
	int k;
	int eo;
	int ao;
	ti(vector<int> n, int tk, int teo): nums(n), k(tk), eo(teo) {}
};

vector<ti> t = {
#ifndef DEBUG
		ti({5,2,2,4,0,6}, 4, 5),
		ti({99,95,68,24,18}, 69, 99),
		ti({73,63,62,16,95,92,93,52,89,36,75,79,67,60,42,93,93,74,94,73,35,86,96}, 59, 96),
		ti({91,98,17,79,15,55,47,86,4,5,17,79,68,60,60,31,72,85,25,77,8,78,40,96,76,69,95,2,42,87,48,72,45,25,40,60,21,91,32,79,2,87,80,97,82,94,69,43,18,19,21,36,44,81,99}, 2, 91),
		ti({2}, 1, -1),
		ti({35,43,23,86,23,45,84,2,18,83,79,28,54,81,12,94,14,0,0,29,94,12,13,1,48,85,22,95,24,5,73,10,96,97,72,41,52,1,91,3,20,22,41,98,70,20,52,48,91,84,16,30,27,35,69,33,67,18,4,53,86,78,26,83,13,96,29,15,34,80,16,49}, 15, 94),
#endif
		ti({68,76,53,73,85,87,58,24,48,59,38,80,38,65,90,38,45,22,3,28,11}, 1, 76),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->maximumTop(t[i].nums, t[i].k);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
	}

	return 0;
}
