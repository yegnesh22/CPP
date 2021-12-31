/*
 * Solution.cpp
 *
 *  Created on: 31-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	int length;
    	int ml = 1;

    	length = s.length();
    	for (int i = length; i >= ml; i--) {
    		cout << "i = " << i << endl;
    		for (int j = 0; j < (length - i + 1); j++) {
    			cout << "j = " << j << endl;
    			string sst = s.substr(j, i);
    			int sstlen = sst.length();
    			int start, end;
    			bool found = true;
    			cout << "sst:" << sst << endl;
    			start = 0;
    			end = sstlen - 1;
    			while (start < end) {
    				//cout << sst[start] << "==" << sst[end] << endl;
    				if (sst[start] != sst[end]) {
    					ml = max(ml, (sstlen - end));
    					cout << "ml=" << ml << endl;
    					//char c = getchar();
    					found = false;
    					break;
    				}
    				start++;
    				end--;
    			}
    			if (found)
    				return sst;
    		}
    	}
    	return s.substr(0,1);
    }
};

int main()
{
	Solution s;
	//string t = "babad";
	string t = "cbbd";
	//string t = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

	cout << t.length() << endl;
	string result = s.longestPalindrome(t);
	cout << result << endl;
	cout << result.length() << endl;
	return 0;
}
