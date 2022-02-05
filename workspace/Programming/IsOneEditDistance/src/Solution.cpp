/*
 * Solution.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string t;
	bool ao;
	bool eo;
};

class Solution {
public:
    bool isOneEditDistance(string s, string t);
};

bool Solution::isOneEditDistance(string s, string t)
{
	int sl = s.length();
	int tl = t.length();
	int ld = abs(sl - tl);

	if (ld > 1)
		return false;

	if (sl == 0 && tl == 0)
		return false;

	if (sl == 0 || tl == 0)
		return true;

	int err = 0;
	int ti = 0;
	int si = 0;

	while (si < sl && ti < tl) {
		if (s[si] != t[ti]) {
			err++;

			if (err > 1) return false;

			if (tl > sl) {
				ti++;
				continue;
			} else if (tl < sl) {
				si++;
				continue;
			}
		}
		si++;
		ti++;
	}

	if (err == 1)
		return true;
	else if ((err == 0) && (sl != tl))
		return true;
	return false;
}

vector<ti> t = {
		{
				.s = "ab",
				.t = "acb",
				.eo = true,
		},
		{
				.s = "",
				.t = "",
				.eo = false,
		},
		{
				.s = "jcb",
				.t = "cab",
				.eo = false,
		},
		{
				.s = "pan",
				.t = "an",
				.eo = true,
		},
		{
				.s = "fan",
				.t = "ran",
				.eo = true,
		},
		{
				.s = "an",
				.t = "man",
				.eo = true,
		},
		{
				.s = "a",
				.t = "",
				.eo = true,
		},
		{
				.s = "a",
				.t = "ac",
				.eo = true,
		},

};

int main()
{
	Solution *s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->isOneEditDistance(t[i].s, t[i].t);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
