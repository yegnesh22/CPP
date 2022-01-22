/*
 * Solution.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int search(vector<int>& nums, int target) = 0;
};

class Obvious: public Solution {
public:
    int search(vector<int>& nums, int target) {
    	int last = nums.size() - 1;
    	int i;
    	bool fs;

    	if (target < nums[0] && target > nums[last]) {
    		// number does not exist
    		return -1;
    	}

    	if (target >= nums[0])
    		fs = true;

    	if (target <= nums[last])
    		fs = false;

    	if (fs) {
    		i = 0;
    		while ((target > nums[i]) && (i < last)) {
    			i++;
    		}
    		if (target == nums[i])
    			return i;
    		else
    			return -1;
    	}
    	if (!fs) {
    		i = last;
    		while ((target < nums[i]) && (i > 0)) {
    			i--;
    		}
    		if (target == nums[i])
    			return i;
    		else
    			return -1;
    	}

    	return -1;
    }
};


struct TI {
	vector<int> i;
	int t;
	int eo;
	int ao;
};

int main()
{
	vector<TI> t = {
			{.i = {4,5,6,7,0,1,2}, .t = 0, .eo = 4},
			{.i = {4,5,6,7,0,1,2}, .t = 3, .eo = -1},
			{.i = {1}, .t = 0, .eo = -1},
			{.i = {3,1}, .t = 1, .eo = 1},
	};
	Solution *s = new Obvious();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->search(t[i].i, t[i].t);
		cout << "t[" << i << "] -- eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}
}
