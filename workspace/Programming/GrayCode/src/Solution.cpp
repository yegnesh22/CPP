/*
 * Solution.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Approach 2: Recursion
 * Intuition
 * If you're not familiar with recursion, check out our Explore Card.
 * Consider the sequence generated for n = 0 to 3.
 * For n = 0 the Gray code sequence is [0].
 * For n = 1 the Gray code sequence is [0, 1].
 * Similarly, we had [0, 1] from n = 1 and for n = 2 the Gray code sequence
 * is [00, 01, 11, 10]. By observing the sequences generated with n = 0, 1,
 * 2.... we will find a pattern. We can obtain the Gray code sequence for n
 * from the Gray code sequence for n - 1.
 *
 * For example the Gray code sequence for n = 3 is
 * [000, 001, 011, 010, 110, 111, 101, 100]
 * (G(3)). This sequence can be obtained from the sequence [00, 01, 11, 10](say G(2))
 * for n = 2 as follows:
 * Add 0 to the (n - 1)^{th}(n-1) th position (0 based indexed, the 2^{nd} 2 nd
 * bit from the right) to the entire sequence of G(2). [00, 01, 11, 10] ->
 * [000, 001, 011, 010] (G(3a)).
 * Reverse G(2) sequence and add 1 (1 << n - 1) to the (n - 1)^{th}(n-1) th
 * position (the 2^{nd} 2nd bit from the right)
 * [00, 01, 11, 10] -> [10, 11, 01, 00] -> [110, 111 101, 100] (G(3b)).
 * Concatenate G(3a) and G(3b) to get the Gray code sequence for n = 3 (G(3)) :
 * [000, 001, 011, 010, 110, 111, 101, 100]
 */

struct ti {
	int n;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.n = 2,
				.eo = {0,1,3,2},
		},
		{
				.n = 1,
				.eo = {0,1},
		},
		{
				.n = 3,
				.eo = {0,1,3,2,6,7,5,4},
		},
};

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> vn1;
    	vector<int> v;
    	int vn1s;
    	int num;

    	if (n == 0) {
    		return {};
    	}

    	if (n == 1) {
    		v.push_back(0);
    		v.push_back(1);
    		return v;
    	}

    	vn1 = grayCode(n - 1);
    	vn1s = vn1.size() - 1;
    	v.insert(v.end(), vn1.begin(), vn1.end());

    	for (int i = vn1s; i >= 0; i--) {
    		num = (1 << n - 1) | vn1[i];
    		v.push_back(num);
    	}

    	return v;
    }
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->grayCode(t[i].n);
		cout << i << " --- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
