/*
 * Solution.cpp
 *
 *  Created on: Jan 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	int fbSize = flowerbed.size();
    	int gap = 0;
    	int adj = 0;

    	// If n <= 0 return true
    	if (n <= 0)
    		return true;

    	// If n > flowerbed size return false
    	if (n > fbSize)
    		return false;

    	// If there is only one space
    	// return true if it is vacant
    	// false otherwise.
    	if (fbSize == 1) {
    		return (!flowerbed[0]);
    	}

    	for (int i = 0; i < fbSize; i++) {
    		if (flowerbed[i]) {
    			// check the last number of counts
    			n = n  - ((gap - adj) / 2);
    			// Reset counts
    			gap = 0;
    			adj = 1;
    		} else {
    			gap++;
    		}
    		if (n <= 0)
    			return true;
    	}

    	// Process the end gap
    	if (gap) {
    		if (!adj) // Empty array
    			n = n -  ((gap + 1) / 2);
    		else
    			n = n - (gap / 2);
    	}

    	return (n <= 0);
    }
};

struct TestInput {
	vector<int> fb;
	int n;
	bool eo;
	bool ao;
};


int main()
{
	vector<TestInput> t = {
			{.fb = {1,0,0,0,1}, .n = 1, .eo = true},
			{.fb = {1,0,0,0,1}, .n = 2, .eo = false},
			{.fb = {1,0,0,0,0,1}, .n = 2, .eo = false},
			{.fb = {1,0,1,0,1,0,1}, .n = 1, .eo = false},
			{.fb = {0,0,1,0,1}, .n = 1, .eo = true},
			{.fb = {1,0,1,0,0}, .n = 1, .eo = true},
			{.fb = {0}, .n = 1, .eo = true},
			{.fb = {1}, .n = 1, .eo = false},
			{.fb = {0}, .n = 0, .eo = true},
			{.fb = {1}, .n = 0, .eo = true},
			{.fb = {0,0,0}, .n = 2, .eo = true},
	};
	Solution s;

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s.canPlaceFlowers(t[i].fb, t[i].n);
		cout << "t[" << i << "] : eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].eo == t[i].ao) ? "pass": "fail")
				<< endl;
	}
	return 0;
}
