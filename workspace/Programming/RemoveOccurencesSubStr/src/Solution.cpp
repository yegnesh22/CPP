/*
 * Solution.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part);
};

string Solution::removeOccurrences(string s, string part)
{
	string r(s);
	size_t found;

	found = r.find(part);
	while (found != r.npos) {
		r.erase(r.begin()+found, r.begin()+found+part.length());
		found = r.find(part);
	}

	return r;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string p;
	string eo;
	string ao;
};

vector<ti> t = {
		{
				.s = "daabcbaabcbc",
				.p = "abc",
				.eo = "dab",
		},
		{
				.s = "axxxxyyyyb",
				.p = "xy",
				.eo = "ab",
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeOccurrences(t[i].s, t[i].p);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
