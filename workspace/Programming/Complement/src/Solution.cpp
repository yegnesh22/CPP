/*
 * Solution.cpp
 *
 *  Created on: 04-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <climits>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
    	if (n == 0) return (~0 & 1);
        if (n == INT_MAX || n == INT_MIN) return 0;
    	int mask = 1;
    	int num = n;

    	while (num) {
    		mask <<= 1;
    		mask |= 1;
    		num >>= 1;
    	}
    	mask >>= 1;
    	mask &= 0x7fffffff;
    	//cout << ~n << " " << mask << " " << flush;
    	//printf(" %x %x ", ~n, mask);
    	return (~n) & mask;
    }
};

int main()
{
	Solution s;
	vector<int> t = {
			5,
			7,
			10,
			0,
			2147483646,
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << *it << " " << s.bitwiseComplement(*it) << endl;
	return 0;
}
