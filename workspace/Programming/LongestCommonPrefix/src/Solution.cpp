/*
 * Solution.cpp
 *
 *  Created on: 05-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	auto itb = strs.begin();
    	string prefix = "";
    	string s1, s2;
    	char c1, c2;

    	s1 = *itb;
    	for (size_t i = 0; i < s1.max_size(); i++) {
    		c1 = s1[i];
    		if (i >= s1.length())
    		    return prefix;
    		for (auto it = itb + 1; it != strs.end(); it++) {
    			s2 = *it;
    			if (i >= s2.length())
    				return prefix;
    			c2 = s2[i];
    			if (c1 != c2)
    				return prefix;
    		}
    		prefix += c1;
    	}
    	return prefix;
    }
};

int main()
{
	Solution s;
	vector<vector<string>> t = {
			{ "flower","flow","flight" },
			{ "dog","racecar","car" },
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << "common prefix:" << s.longestCommonPrefix(*it) << endl;
	return 0;
}



