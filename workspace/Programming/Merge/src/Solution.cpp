/*
 * Solution.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int i, j;
    	int key;
    	int kp;

    	for (i = 0; i < n; i++) {
    		key = nums2[i];

    		kp = -1;
    		// Find the position in nums1 where the key should be
    		// placed.
    		for (j = (m - 1);(j >= 0) && (nums1[j] > key); j--);
    		kp = j + 1;
    		cout << "key:" << key << " pos:" << kp << endl;

    		// Shift the elements from last to kp
    		for (j = m - 1; j >= kp; j--) {
    			nums1[j+1] = nums1[j];
    		}
    		m++;

    		nums1[kp] = key;
    	}
    }
};

struct ti {
	vector<int> a1;
	int m;
	vector<int> a2;
	int n;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.a1 = {1,2,3,0,0,0},
				.m = 3,
				.a2 = {2,5,6},
				.n = 3,
				.eo = {1,2,2,3,5,6},
		},
		{
				.a1 = {1},
				.m = 1,
				.a2 = {},
				.n = 0,
				.eo = {1}
		},
		{
			.a1 = {0},
			.m = 0,
			.a2 = {1},
			.n = 1,
			.eo = {1},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		s->merge(t[i].a1, t[i].m, t[i].a2, t[i].n);
		cout << i << ":" << ((t[i].a1 == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
