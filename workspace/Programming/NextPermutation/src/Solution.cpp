/*
 * Solution.cpp
 *
 *  Created on: Jan 23, 2022
 *      Author: ysiyer
 */

/*
 * Approach 2: Single Pass Approach
 *
 * Algorithm
 *
 * First, we observe that for any given sequence that is in descending order,
 * no next larger permutation is possible. For example, no next permutation
 * is possible for the following array: [9, 5, 4, 3, 1].
 *
 * We need to find the first pair of two successive numbers a[i] and a[i-1],
 * from the right, which satisfy a[i] > a[i-1]. Now, no rearrangements to the
 * right of a[i-1] can create a larger permutation since that subarray
 * consists of numbers in descending order. Thus, we need to rearrange the numbers
 * to the right of a[i-1] including itself.
 *
 * Now, what kind of rearrangement will produce the next larger number? We want to
 * create the permutation just larger than the current one. Therefore, we need to
 * replace the number a[i-1] with the number which is just larger than itself
 * among the numbers lying to its right section, say a[j].
 *
 * Next Permutation
 *
 * We swap the numbers a[i-1] and a[j]. We now have the correct number at index i-1.
 * But still the current permutation isn't the permutation that we are looking for.
 * We need the smallest permutation that can be formed by using the numbers only to
 * the right of a[i-1]. Therefore, we need to place those numbers in ascending order
 * to get their smallest permutation.
 *
 * But, recall that while scanning the numbers from the right, we simply kept
 * decrementing the index until we found the pair a[i] and a[i-1] where, a[i] > a[i-1].
 * Thus, all numbers to the right of a[i-1] were already sorted in descending order.
 * Furthermore, swapping a[i-1] and a[j] didn't change that order. Therefore, we simply
 * need to reverse the numbers following a[i-1] to get the next smallest lexicographic
 * permutation.
 *
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

class Solution {
public:
    virtual void nextPermutation(vector<int>& nums) = 0;
};

class MySolution : public Solution {
public:
	void swap(int &a, int &b) {
		int t;

		t = a;
		a = b;
		b = t;
	}

#ifdef DEBUG
	void printV(vector<int>& n) {
		cout << "v <-- " << flush;
		for(int i = 0; i < n.size(); i++)
			cout << n[i] << " " << flush;
		cout << endl;
	}
#endif

	void reverse(vector<int>& nums, int s, int e) {
#ifdef DEBUG
		cout << "reversing " << s << " and " << e << endl;
#endif
		while (s < e) {
			swap(nums[s], nums[e]);
			s++;
			e--;
		}
	}

    void nextPermutation(vector<int>& nums) {
    	int nl = nums.size() - 1;
    	int j;
    	int i;

    	for (i = nl; i > 0; i--) {
    		if(nums[i] > nums[i-1]) {
#ifdef DEBUG
    			cout << "matches -- [" << i
    					<< "]:" << nums[i]
    					<< " [" << (i - 1)
						<< "]:" << nums[i -1]
						<< endl;
#endif
    			for (j = i + 1; j < nl + 1; j++) {
#ifdef DEBUG
    				cout << "running match loop for " << j << endl;
#endif
    				if (nums[i - 1] >= nums[j]) {
#ifdef DEBUG
    					cout << "loop breaks" << endl;
#endif
    					break;
    				}
    			}
#ifdef DEBUG
    			cout << "j = " << j << endl;
    			cout << "swapping [" << (i - 1)
    					<< "] = " << nums[i - 1] << " with [" << (j - 1)
						<< "] = " << nums[j - 1] << endl;
#endif
    			swap(nums[i-1], nums[j - 1]);
#ifdef DEBUG
    			printV(nums);
#endif
    			break;
    		}
    	}

    	reverse(nums, i, nl);

    	return;
    }
};

struct TI {
	vector<int> i;
	vector<int> eo;
};

vector<TI> t = {
#ifndef DEBUG
		{
				.i = {1,2,3},
				.eo = {1,3,2},
		},
		{
				.i = {3,2,1},
				.eo = {1,2,3},
		},
		{
				.i = {1,1,5},
				.eo = {1,5,1},
		},
		{
				.i = {1,5,1},
				.eo = {5,1,1},
		},
#endif
		{
				.i = {1,3,2},
				.eo = {2,1,3},
		},
};

int main()
{
	Solution *s = new MySolution();

	for (int i = 0; i < t.size(); i++) {
		s->nextPermutation(t[i].i);
		cout << "t[" << i << "] -- r:" << ((t[i].eo == t[i].i) ? "pass" : "fail") << endl;
	}

	return 0;
}
