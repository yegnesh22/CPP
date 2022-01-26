/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	virtual bool validMountainArray(vector<int>& arr) = 0;
};

class BasicSolution: public Solution {
public:
    bool validMountainArray(vector<int>& arr) {
    	int dirFlip = 0;
    	enum trend {
    		up = 0,
			down,
			flat,
    	};
    	trend ct, pt;

    	if (arr.size() == 1) // Only 1 point
    		return false;

    	int d = arr[0] - arr[1];
		if (d > 0)
    		pt = down;
    	else if (d < 0)
    		pt = up;
    	else
    		pt = flat;

    	if (pt != up)
    		return false;

    	for (int i = 1; i < arr.size(); i++) {
    		if ((arr[i - 1] - arr[i]) < 0)
    			ct = up;
    		else if ((arr[i - 1] - arr[i]) > 0)
    			ct = down;
    		else
    			ct = flat;

    		if (ct == flat)
    			return false;

    		if (pt != ct) {
    			dirFlip ++;
    			pt = ct;
    		}

    		// If there are more than 1 flips.
    		if (dirFlip > 1)
    			return false;
    	}

    	if (dirFlip == 0) // No mountain. Only a slope
    		return false;

    	return true;
    }
};

struct ti {
	vector<int> i;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.i = {2,1},
				.eo = false,
		},
		{
				.i = {3,5,5},
				.eo = false,
		},
		{
				.i = {0,3,2,1},
				.eo = true,
		},
		{
				.i = {2,0,2},
				.eo = false,
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->validMountainArray(t[i].i);
		cout << i << " : " << ((t[i].ao == t[i].eo) ? "pass":"fail") << endl;
	}
	return 0;
}
