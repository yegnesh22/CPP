/*
 * Solution.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k);
};

bool Solution::checkSubarraySum(vector<int>& nums, int k)
{
	map<int, int>::iterator it;
	int ns = nums.size();
	map<int, int> lkp;
	int sum = 0;
	int r;

    sum = nums[0];
    lkp.insert(pair<int, int>(sum % k, 0));
	for (int i = 1; i < ns; i++) {
		sum += nums[i];
		r = sum % k;
        if (r == 0)
            return true;
		it = lkp.find(r);
		if (it != lkp.end()) {
            if ((i - it->second) > 1)
			    return true;
            else if (((nums[i] + nums[it->second]) % k) == 0)
                return true;
        }
		lkp.insert(pair<int, int>(r, i));
	}

	return false;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.n = {23,2,4,6,7},
				.k = 6,
				.eo = true,
		},
		{
				.n = {23,2,6,4,7},
				.k = 6,
				.eo = true,
		},
		{
				.n = {23,2,6,4,7},
				.k = 13,
				.eo = false,
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->checkSubarraySum(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
