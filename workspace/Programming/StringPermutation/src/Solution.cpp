/*
 * Solution.cpp
 *
 *  Created on: Feb 11, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s1;
	string s2;
	bool eo;
	bool ao;
};

class Solution {
public:
    bool checkInclusion(string s1, string s2);
#ifdef DEBUG
    void printL(vector<int> s1, vector<int> s2);
#endif
};

#ifdef DEBUG
void Solution::printL(vector<int> s1, vector<int> s2)
{
	vector<vector<int>> l = {s1, s2};

	for (int i = 0; i < l.size(); i++) {
		for (int j = 0; j < l[i].size(); j++)
			cout << (char)('a' + j) << ":" << l[i][j] << " " << flush;
		cout << endl;
	}
}
#endif

bool Solution::checkInclusion(string s1, string s2)
{
	vector<int> s1lkp(26, 0);
	vector<int> s2lkp(26, 0);
	int s1l = s1.length();
	int s2l = s2.length();
	string sw;
	int i;

	if (s1l > s2l)
		return false;

	for (i = 0; i < s1l; i++) {
		s1lkp[s1[i] - 'a']++;
		s2lkp[s2[i] - 'a']++;
	}

	if (s1lkp == s2lkp)
		return true;

	for (i = 0; i < (s2l - s1l); i++) {
		if (s1lkp == s2lkp)
			return true;

		s2lkp[s2[i + s1l] - 'a']++;
		s2lkp[s2[i] - 'a']--;
	}

	return s1lkp == s2lkp;
}

vector<ti> t = {
		{
				.s1 = "ab",
				.s2 = "eidbaooo",
				.eo = true,
		},
		{
				.s1 = "ab",
				.s2 = "eidboaoo",
				.eo = false,
		},
		{
				.s1 = "ab",
				.s2 = "ab",
				.eo = true,
		},
		{
				.s1 = "hello",
				.s2 = "ooolleoooleh",
				.eo = false,
		},
		{
				.s1 = "adc",
				.s2 = "dcda",
				.eo = true,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->checkInclusion(t[i].s1, t[i].s2);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
