/*
 * Solution.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printV(vector<int>v, int n) {
	cout << "v --" << flush;
	for (int i = 0; i < n; i++) {
		cout << " " << v[i] << flush;
	}
	cout << endl;
}

bool compare (int a, int b) {
	return (a < b);
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int nA = nums.size();
    	sort(nums.begin(), nums.end(), compare);

    	int i = 0;
    	while ((i < nA) && (nums[i] != val))
    		i++;
    	int adj = i;
    	int count = 0;
    	while ((i < nA) && (nums[i] == val)) {
    		count++;
    		i++;
    	}
    	while(i < nA) {
    		nums[adj] = nums[i];
    		i++;
    		adj++;
    	}

    	return (nA - count);
    }
};

struct TestInput {
	vector<int> i;
	int v;
};

int main()
{
	vector<TestInput> t = {
			{.i = {3,2,2,3}, .v = 3},
			{.i = {0,1,2,2,3,0,4,2}, .v = 2},
	};
	int nt = t.size();
	Solution s;
	int r;

	for (int i  = 0; i < nt; i++) {
		printV(t[i].i, t[i].i.size());
		r = s.removeElement(t[i].i,t[i].v);
		cout << "Num Elements after removal = " << r << endl;
		printV(t[i].i, r);
	}
	return 0;
}
