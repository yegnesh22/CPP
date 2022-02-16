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

#define NUM_BITS 32

struct BitWiseTrie {
	BitWiseTrie* bit[2];
	BitWiseTrie() {
		bit[0] = nullptr;
		bit[1] = nullptr;
	}
};

class Trie: public Solution {
private:
	BitWiseTrie* TrieRoot;
	void insert(int x);
	int maxXOR(int n);
public:
	int findMaximumXOR(vector<int>& nums);
};

void Trie::insert(int x)
{
	BitWiseTrie* t = TrieRoot;
	bitset<NUM_BITS> b(x);

	for (int i = NUM_BITS-1; i >= 0; i--) {
		if (t->bit[b[i]] == nullptr)
			t->bit[b[i]] = new BitWiseTrie();
		t = t->bit[b[i]];
	}
}

int Trie::maxXOR(int n)
{
	BitWiseTrie* t = TrieRoot;
	bitset<NUM_BITS> b(n);
	bitset<NUM_BITS> mXOR(0);

	for (int i = NUM_BITS-1; i >= 0; i--) {
		if (t->bit[!b[i]] != nullptr) {
			t = t->bit[!b[i]];
			mXOR[i] = 1;
		} else
			t = t->bit[b[i]];
	}
	return (int)mXOR.to_ulong();
}

int Trie::findMaximumXOR(vector<int>& nums)
{
	int ns = nums.size();
	int mXOR = 0;

	// Create the trie
	TrieRoot = new BitWiseTrie();
	for (int i = 0; i < ns; i++)
		insert(nums[i]);

	for (int i = 0; i < ns; i++)
		mXOR = max(mXOR, maxXOR(nums[i]));

	return mXOR;
}

int main()
{
	//Solution *s = new BasicSolution();
	Solution *s = new Trie();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findMaximumXOR(t[i].nums);
		cout << t[i].ao << endl;
		cout << i << " -- r: " << ((t[i].ao == t[i].eo) ? "pass": "fail") << endl;
	}
	return 0;
}
