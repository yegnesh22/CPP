/*
 * Solution.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    virtual bool detectCapitalUse(string word) = 0;
};

class BasicSolution: public Solution {
public:
	bool isCaps(char c) {
		return ((c >= 'A') && (c <= 'Z'));
	}

	bool isSmall(char c) {
		return ((c >= 'a') && (c <= 'z'));
	}

    bool detectCapitalUse(string word) {
    	int l  = word.length();
    	bool sf = false;
    	int fso = -1;

    	for (int i = 0 ; i < l; i++) {
    		if (isSmall(word[i])) {
    			if (fso == -1 && i > 1) {
    				return false;
    			} else {
    				fso = i;
    			}
    			sf = true;
    		}

    		else if ((isCaps(word[i])) && sf)
    			return false;
    	}

    	return true;
    }
};

struct ti {
	string i;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.i = "USA",
				.eo = true,
		},
		{
				.i = "leetcode",
				.eo = true,
		},
		{
				.i = "Google",
				.eo = true,
		},
		{
				.i = "FlaG",
				.eo = false,
		},
		{
				.i = "FFFFFFFFFFFFFFFFFFFFf",
				.eo = false,
		},
		{
				.i = "Ff",
				.eo = true,
		},
};


int main()
{
	Solution* s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->detectCapitalUse(t[i].i);
		cout << "t[" << i << "] -- r: "
				<< ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}
	return 0;
}
