/*
 * Solution.cpp
 *
 *  Created on: 06-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	string result;
    	vector<int> divisors = {
    			1000, 900, 500, 400,
    			100, 90, 50, 40, 10,
				9, 5, 4, 1
    	};
    	vector<string> strs = {
    			"M", "CM", "D", "CD",
				"C", "XC", "L", "XL", "X",
				"IX", "V", "IV", "I"
    	};

    	for (size_t i = 0; i < divisors.size() && num > 0; i++) {
    		while (divisors[i] <= num) {
    			num -= divisors[i];
    			result += strs[i];
    		}
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	vector<int> t = {
			3,
			58,
			1994,
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << *it << " : " << s.intToRoman(*it) << endl;

	return 0;
}
