/*
 * Solution.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;

struct ti {
	vector<int> nums;
	int eo;
	int ao;
};


vector<ti> t = {
		{
				.nums = {3,10,5,25,2,8},
				.eo = 28,
		},
		{
				.nums = {14,70,53,83,49,91,36,80,92,51,66,70},
				.eo = 127,
		},
		{
				.nums = {2147483647,2147483646,2147483645},
				.eo = 3,
		},
};

class Solution {
public:
	virtual int findMaximumXOR(vector<int>& nums) = 0;
};

class BasicSolution: public Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
    	int r = 0;

    	for (int i = 0; i < nums.size(); i++) {
    		for (int j = i + 1; j < nums.size(); j++) {
    			r = max(r, nums[i] ^ nums[j]);
    		}
    	}

    	return r;
    }
};

class O1: public Solution {
private:
	int maxPXOR(int V) {
		int nbits = 0;

		while(V) {
			V >>= 1;
			nbits++;
		}

		if (nbits >= 32) {
			cout << "1 -- returned " << INT_MAX << endl;
			return INT_MAX;
		}

		cout << "2 -- returned " << ((1 << nbits) - 1) << endl;
		return (1 << nbits) - 1;
	}

public:
	int findMaximumXOR(vector<int>& nums) {
		map<int, bool> lookup;
		int ne = nums.size();
		int mV = nums[0];
		int mpXOR;
		int lv;

		for (int i = 0; i < ne; i++) {
			mV = max(mV, nums[i]);
			lookup.insert(pair<int, bool>(nums[i], true));
		}

		mpXOR = maxPXOR(mV);

		while (mpXOR) {
			cout << "check -- " << mpXOR << endl;
			for (int i = 0; i < ne; i++) {
				lv = mpXOR ^ nums[i];
				if (lookup.find(lv) != lookup.end()) // value found
					return mpXOR;
			}
			mpXOR--;
		}
	}
};

int main()
{
	//Solution *s = new BasicSolution();
	Solution *s = new O1();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findMaximumXOR(t[i].nums);
		cout << t[i].ao << endl;
		cout << i << " -- r: " << ((t[i].ao == t[i].eo) ? "pass": "fail") << endl;
	}
	return 0;
}
