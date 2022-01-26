/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ti {
	vector<int> i;
	vector<int> eov;
	int eo;
	int ao;
};

class Solution {
public:
	virtual int removeDuplicates(vector<int>& nums) = 0;
	string checkResult(struct ti t) {
		if (t.ao != t.eo) {
			cout << "Count check failed ao:" << t.ao << " eo:" << t.eo << endl;
			return "fail";
		}

		for (int i = 0; i < t.ao; i++) {
			if (t.i[i] != t.eov[i]) {
				cout << "Mismatch at index " << i << " " << t.i[i] << " -- " << t.eov[i] << endl;
				return "fail";
			}
		}

		return "pass";
	}
};

class BasicSolution: public Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	map<int, int> lookup;
    	int ns = nums.size();
    	int dpc = 0;

    	for (int i = 0; i < (ns - dpc); i++) {
    		if (lookup.find(nums[i]) != lookup.end()) {
    			if (lookup[nums[i]] == 2) {
    				// Remove the remaining duplicates
    				for (int j = i; j < (ns - dpc - 1); j++) {
    					nums[j] = nums[j+1];
    				}
    				i--;
    				dpc++;
    			} else
    				lookup[nums[i]]++;
    		} else
    			lookup.insert(pair<int, int> (nums[i], 1));
    	}

    	return ns - dpc;
    }
};

vector<ti> t = {
		{
				.i = {1,1,1,2,2,3},
				.eov = {1,1,2,2,3},
				.eo = 5,
		},
		{
				.i = {0,0,1,1,1,1,2,3,3},
				.eov = {0,0,1,1,2,3,3},
				.eo = 7,
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeDuplicates(t[i].i);

		cout << i << " -- r = " << s->checkResult(t[i]) << endl;
	}
	return 0;
}
