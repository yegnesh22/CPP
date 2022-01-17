/*
 * Solution.cpp
 *
 *  Created on: Jan 17, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <map>
#include <vector>

//#define DEBUG

using namespace std;

/* Algorithm:
 * Generate a code for each new character encountered in the patterns.
 * Add up the code to find the final code for each pattern.
 * If the code differs in between or at the end, then the
 * patterns are not isomorphic else true.
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if (s.length() != t.length())
    		return false;

    	map<char, int>::iterator s_it;
    	map<char, int>::iterator t_it;
    	map<char, int> scodes;
    	map<char, int> tcodes;
    	int numC = s.length();
    	int scode = 1;
    	int tcode = 1;
    	int tkey = 0;
    	int skey = 0;

    	for (int i = 0; i < numC; i++) {
    		// New letter - assign a new code
    		s_it = scodes.find(s[i]);
    		if (s_it == scodes.end()) {
    			scodes.insert(pair<char, int>(s[i], scode));
#ifdef DEBUG
    			cout << "s --- " << s[i] << ":" << scode << endl;
#endif
    			skey += scode;
    			scode++;
    		} else {
    			skey += s_it->second;
    		}
    		// New letter - assign a new code
    		t_it = tcodes.find(t[i]);
    		if (t_it == tcodes.end()) {
    			tcodes.insert(pair<char, int>(t[i], tcode));
#ifdef DEBUG
    			cout << "t --- " << t[i] << ":" << tcode << endl;
#endif
    			tkey += tcode;
    			tcode++;
    		} else {
    			tkey += t_it->second;
    		}

    		if (tkey != skey) // If inbetween the pattern breaks, then return false
    			return false;
    	}
#ifdef DEBUG
    	cout << "tkey:" << tkey << " skey:" << skey << endl;
#endif
    	return true;
    }
};

struct TestInput {
	string s;
	string t;
	bool eo;
	bool ao;
};

int main()
{
	vector<TestInput> t = {
#ifndef DEBUG
			{.s = "egg", .t = "add", .eo = true},
			{.s = "foo", .t = "bar", .eo = false},
			{.s = "title", .t = "paper", .eo = true},
#endif
			{.s = "bbbaaaba", .t = "aaabbbba", .eo = false},
	};
	Solution s;

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s.isIsomorphic(t[i].s, t[i].t);
		cout << "t[" << i << "] -- eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}

	return 0;
}
