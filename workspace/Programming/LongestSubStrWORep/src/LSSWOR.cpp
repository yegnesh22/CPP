/*
 * LSSWOR.cpp
 *
 *  Created on: 21-Dec-2021
 *      Author: yegnesh
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unsigned int i = 0, j = i + 1;
    	multimap<int, string> sslist;
    	map<char, int> ssClookup;
    	vector<int> sslen;
    	string ss;

    	if (s.length() <= 1)
    		return s.length();

    	ssClookup.insert(make_pair(s[i], i));
    	ss += s[i];
    	while((i < s.length()) && (j < s.length())) {
    		if (ssClookup.count(s[j]) != 0) { // Repeating character found!!
    			sslist.insert(make_pair(ss.length(), ss));
    			sslen.push_back(ss.length());
    			//cout << ss << " ";
    			i = i + 1;
    			j = j;
    			ssClookup.clear();
    			ss = s.substr(i, (j - i));
    			for (unsigned int k = 0; k < ss.length(); k++) {
    				ssClookup.insert(make_pair(s[i + k], (i + k)));
    			}
    		} else { // Repeating character not found!!
    			ssClookup.insert(make_pair(s[j], j));
    			ss += s[j];
    			j++;
    		}
    	}
    	sslist.insert(make_pair(ss.length(), ss));
    	sslen.push_back(ss.length());

    	if (sslen.size()) {
    		sort(sslen.begin(), sslen.end());
    		return sslen[sslen.size() - 1];
    	} else {
    		return s.length();
    	}
    }
};

int main()
{
	Solution s;

	//cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	//cout << s.lengthOfLongestSubstring("bbbbb") << endl;
	//cout << s.lengthOfLongestSubstring("pwwkew") << endl;
	//cout << s.lengthOfLongestSubstring(" ") << endl;
	//cout << s.lengthOfLongestSubstring("") << endl;
	//cout << s.lengthOfLongestSubstring("a") << endl;
	//cout << s.lengthOfLongestSubstring("aa") << endl;
	//cout << s.lengthOfLongestSubstring("ab") << endl;
	//cout << s.lengthOfLongestSubstring("abc") << endl;
	//cout << s.lengthOfLongestSubstring("abb") << endl;
	//cout << s.lengthOfLongestSubstring("aab") << endl;
	cout << s.lengthOfLongestSubstring("dvdf") << endl;
	return 0;
}
