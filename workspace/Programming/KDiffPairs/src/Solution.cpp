/*
 * Solution.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	int eo;
	int ao;
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k);
};

int Solution::findPairs(vector<int>& nums, int k)
{
	map<vector<int>, int> l;
	int ns = nums.size();
	int d;

	sort(nums.begin(), nums.end());

	for(int i  = 0; i < ns; i++) {
		for(int j = i+1; j < ns; j++) {
			d = abs(nums[i]-nums[j]);
			if (d == k) {
				l.insert(pair<vector<int>, bool>({nums[i],nums[j]}, true));
				//cout << "Adding: (" << nums[i] << "," << nums[j] << ")" << endl;
			}
		}
	}
	return l.size();
}

vector<ti> t = {
		{
				.n = {3,1,4,1,5},
				.k = 2,
				.eo = 2,
		},
		{
				.n = {1,2,3,4,5},
				.k = 1,
				.eo = 4,
		},
		{
				.n = {1,3,1,5,4},
				.k = 0,
				.eo = 1,
		},
		{
				.n = {1,2,4,4,3,3,0,9,2,3},
				.k = 3,
				.eo = 2,
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->findPairs(t[i].n, t[i].k);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
