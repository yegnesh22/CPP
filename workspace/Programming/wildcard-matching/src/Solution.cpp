/*
 * Solution.cpp
 *
 *  Created on: Mar 15, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	string m_s;
	string m_p;
public:
	bool isMatch(string s, string p);
	bool check(int ss, int se, int ps, int pl);
};

bool Solution::check(int ss, int se, int ps, int pl)
{
	int si = ss;
	int pi = ps;

	while (si < se && pi < pe) {
		if (m_p[pi] != '?' && m_p[pi] != '*') {
			if (m_p[pi] != m_s[si])
				return false;
			else {
				pi++;
				si++;
			}
		}
		else if (m_p[pi] == '?') {
			si++;
			pi++;
		}
		else if (m_p[pi] == '*') {

		}
	}

	return true;
}


bool Solution::isMatch(string s, string p)
{
	int pl = p.length();
	int sl = s.length();

	if (pl > sl)
		return p[0] == '*';

	return check(0, sl, 0, pl);
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string p;
	bool eo;
	bool ao;
	ti(string i, string pat, bool exp): s(i), p(pat), eo(exp) {}
};

vector<ti> t = {
		ti("aa", "a", false),
		ti("aa", "*", true),
		ti("cb", "?a", false),
		ti("adceb", "*a*b", true),
		ti("adceb", "*a*b", true),
		ti("a","aa", false),
		ti("abcabczzzde","*abc???de*", true),
		ti("acdcb", "a*c?b", false),
		ti("aaaa", "***a", true),
		ti("adceb", "*a*b", true),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->isMatch(t[i].s, t[i].p);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
