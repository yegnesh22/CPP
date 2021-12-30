/*
 * SmallestNumDivByK.cpp
 *
 *  Created on: 30-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
        int smallestRepunitDivByK(int k) {
                vector<bool>lookup(k,false);
                int length = 1;
                int rem = 1;

                while (!lookup[rem % k]) {
                        if ((rem % k) == 0)
                                return length;
                        lookup[rem % k] = true;
                        rem = ((rem * 10) + 1) % k;
                        length++;
                }
                return -1;
        }
};

int main()
{
	Solution s;
	int k = 81;

	cout << "Output: " << s.smallestRepunitDivByK(k) << endl;
	return 0;
}

