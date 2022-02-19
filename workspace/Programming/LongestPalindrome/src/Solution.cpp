/*
 * Solution.cpp
 *
 *  Created on: Feb 18, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int getPalindromeLength(string s, int b, int e);
    string longestPalindrome(string s);
};

int Solution::getPalindromeLength(string s, int b, int e)
{
	int left = b, right = e;

	while ((left >= 0) && (right < s.length()) && (s[left] == s[right])) {
		left--;
		right++;
	}

	return right - left - 1;
}

string Solution::longestPalindrome(string s)
{
	if (s.empty() || s.length() < 1)
		return "";

	int b = 0, e = 0;
	for (int i = 0; i < s.length(); i++) {
		int len1 = getPalindromeLength(s, i, i);
		int len2 = getPalindromeLength(s, i, i+1);
		int len = max(len1, len2);
		if (len > (e - b)) {
			b = i - (len - 1) / 2;
			e = i + len / 2;
		}
	}

	return s.substr(b, e - b + 1);
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string s;
	string eo;
	string ao;
};

vector<ti> t = {
		{
				.s = "babad",
				.eo = "aba",
		},
		{
				.s = "cbbd",
				.eo = "bb",
		},
		{
				.s = "ac",
				.eo = "c",
		},
		{
				.s = "bb",
				.eo = "bb",
		},
		{
				.s = "abb",
				.eo = "bb",
		},
};

int main()
{
	Solution*s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->longestPalindrome(t[i].s);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
