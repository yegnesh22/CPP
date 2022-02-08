/*
 * Solution.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

#define result(x) x << " -- " << ((t[x].ao == t[x].eo) ? "pass" : "fail")

using namespace std;

struct ti {
	string s;
	string t;
	char eo;
	char ao;
};

class Solution {
public:
    char findTheDifference(string s, string t);
};

/*
 * Sort and then compare the strings.
 */

char Solution::findTheDifference(string s, string t)
{
	vector<char> vs;
	vector<char> vt;
	int i;

	for (i = 0; i < s.length(); i++) {
		vt.push_back(t[i]);
		vs.push_back(s[i]);
	}

	for (;i < t.length(); i++)
		vt.push_back(t[i]);

	sort(vt.begin(), vt.end(), [] (const char& a, const char& b) {return a < b;});
	sort(vs.begin(), vs.end(), [] (const char& a, const char& b) {return a < b;});

	for (i = 0; i < s.length(); i++) {
		if(vt[i] != vs[i])
			return vt[i];
	}

	return vt[i];
}

vector<ti> t = {
		{
				.s = "abcd",
				.t = "abcde",
				.eo = 'e'
		},
		{
				.s = "",
				.t = "y",
				.eo = 'y',
		}
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->findTheDifference(t[i].s, t[i].t);
		cout << result(i) << endl;
	}
	return 0;
}
