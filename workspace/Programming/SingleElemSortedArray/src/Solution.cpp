/*
 * Solution.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int eo;
	int ao;
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums);
    int quickSearch(vector<int>& nums, int s, int e);
};

int Solution::quickSearch(vector<int>& nums, int s, int e)
{
	int sl, el;
	int sr, er;
	int m;

	if (s > e)
		return -1;

	if (s == e)
		return s;

	m = (e - s) / 2 + s;
#ifdef DEBUG
	cout << "m:" << m
			<< " s:" << s
			<< " e:" << e
			<< endl;
#endif

	if ((nums[m] != nums[m+1]) && nums[m] != nums[m-1]) {
#ifdef DEBUG
		cout << "returns " << nums[m] << endl;
#endif
		return m;
	}

	sr = m;
	er = e;
	while ((sr < e) && (nums[sr] == nums[sr+1])) sr++;
	sr++;

	sl = s;
	el = m;
	while ((el > s) && (nums[el] == nums[el-1])) el--;
	el--;

	int lr = quickSearch(nums, sl, el);
	int rr = quickSearch(nums, sr, er);

	return ((lr == -1) ? (rr == -1 ? -1 : rr) : lr);
}

int Solution::singleNonDuplicate(vector<int>& nums)
{
	int r = quickSearch(nums, 0, nums.size() - 1);
	return ((r >= 0) ? nums[r] : -1);
}

vector<ti> t = {
#ifdef DEBUG
		{
				.n = {1},
				.eo = 1,
		}
#else
		{
				.n = {1,1,2,3,3,4,4,8,8},
				.eo = 2,
		},
		{
				.n = {3,3,7,7,10,11,11},
				.eo = 10,
		},
		{
				.n = {3,3,7,7,11,11},
				.eo = -1,
		},
		{
				.n = {1,3,3,7,7,11,11},
				.eo = 1,
		},
		{
				.n = {3,3,7,7,11,11,12},
				.eo = 12,
		},
#endif
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->singleNonDuplicate(t[i].n);
#ifdef DEBUG
		cout << t[i].ao << endl;
#endif
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
