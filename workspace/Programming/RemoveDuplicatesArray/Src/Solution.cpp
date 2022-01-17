/*
 * Solution.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int len = nums.size();
        int cur = 0;

        if (len == 1 || len == 0) // no duplicate check required
        	return len;

        for (int j = 1; j < len; j++) {
        	if (nums[j] == nums[j - 1])
        		continue;
        	else {
        		nums[cur] = nums[j - 1];
        		//cout << "copying " << nums[j - 1] << "to " << cur << endl;
        		cur++;
        	}
        }
        nums[cur] = nums[len - 1];
        cur++;
        return cur;
    }
};

struct Test {
	vector<int> t;
	vector<int> te;
};

int main()
{
	vector<Test> t = {
			{.t = {1,1,2}, .te = {1,2}},
			{.t = {0,0,1,1,1,2,2,3,3,4}, .te = {0,1,2,3,4}},
			{.t = {0,0,1,1,1,2,2,3,3,4,4}, .te = {0,1,2,3,4}},
			{.t = {1}, .te = {1}},
			{.t = {1,1}, .te = {1}},
			{.t = {}, .te = {}},
	};
	Solution s;
	int k;

	for (int i = 0; i < t.size(); i++) {
		bool result;
		k = s.removeDuplicates(t[i].t);
		//cout << "actual result: " << k << " expected: " << t[i].te.size() << endl;
		result = (k == t[i].te.size());
		//cout << result << endl;
		for (int j = 0; (j < k) && result; j++) {
			result = (t[i].t[j] == t[i].te[j]);
			//cout << "actual result: " << t[i].t[j] << " expected: " << t[i].te[j] << endl;
		}
		cout << "Testcase " << i << (result ? " pass" : " fail") << endl;
	}
	return 0;
}
