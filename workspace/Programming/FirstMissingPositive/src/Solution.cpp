/*
 * Solution.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

bool compare(int a, int b)
{
	return (a < b);
}

class Solution {
public:
#ifdef DEBUG
	void printV(vector<int>a) {
		cout << "inputs:" << flush;
		for (int i = 0; i < a.size(); i++)
			cout << " " << a[i] << flush;
		cout << endl;
	}
#endif
    int firstMissingPositive(vector<int>& nums) {
    	sort(nums.begin(), nums.end(), compare);
#ifdef DEBUG
    	printV(nums);
#endif
        int as = nums.size();
    	int i = 0;

    	while (i < as && nums[i] <= 0)
    		i++;

        if (i == as) {
            if (nums[i - 1] > 0)
                return nums[i - 1] + 1;
            else
                return 1;
        }

    	if (nums[i] != 1)
    		return 1;

    	while (((i + 1) < as) &&
    			((nums[i] == nums[i+1]) || (nums[i] + 1 == nums[i+1]))){
    		i++;
    	}

    	if (i == as)
    		return nums[i - 1] + 1;

    	return nums[i] + 1;
    }
};

struct TI {
	vector<int> i;
	int eo;
	int ao;
};

int main()
{
	vector<TI> t = {
			{.i = {1,2,0}, .eo = 3},
			{.i = {3,4,-1,1}, .eo = 2},
			{.i = {7,8,9,11,12}, .eo = 1},
			{.i = {0}, .eo = 1},
#ifdef DEBUG
			{.i = {0,2,2,1,1}, .eo = 3},
#endif
	};
	Solution s;

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s.firstMissingPositive(t[i].i);
		cout << "t[" << i << "] - eo = " << t[i].eo << " ao = " << t[i].ao
				<< " r = " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
