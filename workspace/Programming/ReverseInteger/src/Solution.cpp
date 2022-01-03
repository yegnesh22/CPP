/*
 * Solution.cpp
 *
 *  Created on: 02-Jan-2022
 *      Author: yegnesh
 */
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int num = x;
    	int nnum = 0;
    	int d;

    	while (num != 0) {
    		d = num % 10;
    		if ((nnum > (INT_MAX / 10)) || ((nnum == INT_MAX / 10) && (d >= 7))) {
    			return 0;
    		}
    		if ((nnum < (INT_MIN / 10)) || ((nnum == INT_MIN / 10) && (d <= -8))) {
    			return 0;
    		}
			nnum = nnum * 10 + d;
			num = num / 10;
    	}
    	return nnum;
    }
};

int main()
{
	Solution s;
	vector<int> t = {
			123,
			-123,
			120,
			-2147483412,
			1534236469,
	};

	for (vector<int>::iterator it = t.begin(); it != t.end(); it++)
		cout << *it  << " " << s.reverse(*it) << endl;
	return 0;
}
