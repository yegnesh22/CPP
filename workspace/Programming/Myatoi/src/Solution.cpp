/*
 * Solution.cpp
 *
 *  Created on: 31-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//#define DEBUG

class Solution {
public:
    int myAtoi(string s) {
    	bool invert = false;
    	bool done = false;
    	bool ep = false;
    	bool sf = false;
    	size_t i = 0;
    	int num = 0;

    	while (!done) {
    		if (s[i] == ' ') {
    			if (sf) return 0;
    			i++;
    			continue;
    		}
    		if (s[i] >= '0' && s[i] <= '9') {
#ifdef DEBUG
    			cout << "Start number processing" << endl;
#endif
    			while(!ep) {
#ifdef DEBUG
    				cout << num << ":" << (num >= 214748364) << endl;
#endif
    				if (num > 214748364) { // Int limits
    					if (invert == true)
    						return INT_MIN;
    					else
    						return INT_MAX;
    				} else if (num == 214748364) {
    					if (invert == true && s[i] >= '8')
    						return INT_MIN;
    					else if ((invert == false) && s[i] >= '7') {
    						return INT_MAX;
    					}
    				}
    				num *= 10;
    				num += s[i] - '0';
    				i++;
#ifdef DEBUG
    				cout << s.length() << "==" << i << endl;
#endif
    				if ((i == s.length()) || ((s[i] < '0' || s[i] > '9')))
    					ep = done = true;
    			}
    			continue;
    		}
    		if (s[i] == '-' && !sf) {
    			invert = true;
    			i++;
    			sf = true;
    			continue;
    		}
    		if (s[i] == '+' && !sf) {
    			i++;
    			sf = true;
    			continue;
    		}
    		// Non-digit character
    		return 0;
       	}
    	if (invert)
    		num = -num;

    	return num;
    }
};

int main()
{
	Solution s;
	vector<string> t = {
			"42",
			"   42",
			"4193 with words",
			"words and 987",
			"-91283472332",
			"+1",
			"-2147483648",
			"2147483646",
			"  +  413",
	};

	for (vector<string>::iterator it = t.begin(); it != t.end(); it++)
		cout << *it << ":" << s.myAtoi(*it) << endl;
	return 0;
}

