/*
 * Solution.cpp
 *
 *  Created on: Mar 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

#define NUMBITS 32

struct BitWiseTrie {
	BitWiseTrie* bit[2] = {nullptr};
};

class Solution {
private:
	BitWiseTrie* m_root;
public:
	int insert(int n);
	int findMaximumXOR(vector<int>& nums);
};

int Solution::insert(int n)
{
	BitWiseTrie* t = m_root;
	BitWiseTrie* mx = m_root;
	bitset<NUMBITS> XOR(0);
	bitset<NUMBITS> x(n);

	for (int i = (NUMBITS - 1); i >= 0; i--) {
		if (t->bit[x[i]] == nullptr)
			t->bit[x[i]] = new BitWiseTrie();
		if (mx->bit[!x[i]] != nullptr) {
			XOR[i] = 1;
			mx = mx->bit[!x[i]];
		} else
			mx = mx->bit[x[i]];

		t = t->bit[x[i]];
	}

	return (int)XOR.to_ulong();
}

int Solution::findMaximumXOR(vector<int>& nums)
{
	int thisXOR;
	int maxXOR = 0;
	int nl = nums.size();

	m_root = new BitWiseTrie();

	for (int i = 0; i < nl; i++) {
		thisXOR = insert(nums[i]);
		maxXOR = max(thisXOR, maxXOR);
	}

	return maxXOR;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

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
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findMaximumXOR(t[i].nums);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
