/*
 * Solution.cpp
 *
 *  Created on: Jan 17, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

// Extension of isomorphic strings case.
// On the second string instead of character,
// generate code for words.

//#define DEBUG

using namespace std;

class Solution {
public:
    bool wordPattern(string p, string s) {
    	map<string, int>::iterator s_it;
    	map<char, int>::iterator p_it;
    	map<string, int> scodes;
    	map<char, int> pcodes;
    	int numC = p.length();
    	int slen = s.length();
    	int pcode = 1;
    	int scode = 1;
    	int pkey = 0;
    	int skey = 0;
    	string word;
    	int j = 0;

    	for (int i = 0; i < numC; i++) {
    		// New letter - assign a new code
    		p_it = pcodes.find(p[i]);
    		if (p_it == pcodes.end()) {
    			pcodes.insert(pair<char, int>(p[i], pcode));
#ifdef DEBUG
    			cout << "p --- " << p[i] << ":" << pcode << endl;
#endif
    			pkey += pcode;
    			pcode++;
    		} else {
    			pkey += p_it->second;
    		}
    		// New word - assign a new code
    		word.clear();
    		while ((s[j] != ' ') && (j < s.length())) {
    			word += s[j];
    			j++;
    		}
    		j++;
    		s_it = scodes.find(word);
    		if (s_it == scodes.end()) {
    			scodes.insert(pair<string, int>(word, scode));
#ifdef DEBUG
    			cout << "s --- " << word << ":" << scode << endl;
#endif
    			skey += scode;
    			scode++;
    		} else {
    			skey += s_it->second;
    		}

    		// If the pattern breaks in-between, then return false.
    		if (skey != pkey)
    			return false;

    		// If pattern is pending, but word collection ends, then also return failed.
    		// Expectation is number of words in the word collection should be same
    		// as number of characters in the pattern.
    		if ((j >= slen) && ((i + 1) < numC))
    			return false;
    	}

    	// Some pending patterns left
    	if (j < slen)
    		return false;

    	return true;
    }
};

struct TestInput {
	string p;
	string s;
	bool eo;
	bool ao;
};

int main()
{
	vector<TestInput> t = {
			{.p = "abba", .s = "dog cat cat dog", .eo = true},
			{.p = "abba", .s = "dog cat cat fish", .eo = false},
			{.p = "aaaa", .s = "dog cat cat dog", .eo = false},
			{.p = "aaa", .s = "aa aa aa aa", .eo = false},
	};
	Solution s;

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s.wordPattern(t[i].p, t[i].s);
		cout << "t[" << i << "] -- eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}

	return 0;
}
