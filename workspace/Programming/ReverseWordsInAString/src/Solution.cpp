/*
 * Solution.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

class Solution {
public:
    string reverseWords(string s);
};

string Solution::reverseWords(string s)
{
	int sl = s.length();
	string d = " ";
	string srev;
	string w;

	for(int i = 0; i < sl; i++) {
		if (s[i] == ' ') {
			while (s[i+1] == ' ') i++;
			if (!w.empty()) {
				if (!srev.empty())
					srev.insert(srev.begin(), d.begin(), d.end());
				srev.insert(srev.begin(), w.begin(), w.end());
				w.clear();
			}
		} else {
			w.push_back(s[i]);
		}
	}

	if (!w.empty()) {
		if (!srev.empty())
			srev.insert(srev.begin(), d.begin(), d.end());
		srev.insert(srev.begin(), w.begin(), w.end());
	}

	return srev;
}

struct ti {
	string s;
	string eo;
	string ao;
};

vector<ti> t = {
		{
				.s = "the sky is blue",
				.eo = "blue is sky the",
		},
		{
				.s = "  hello world  ",
				.eo = "world hello",
		},
		{
				.s = "a good   example",
				.eo = "example good a",
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->reverseWords(t[i].s);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}
}
