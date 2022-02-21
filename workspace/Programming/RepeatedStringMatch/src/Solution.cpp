/*
 * Solution.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b);
};

int Solution::repeatedStringMatch(string a, string b)
{
    string wc(a);
    int bl = b.length();
    int maxl = bl + a.length();
	int count = 1;

	while (wc.find(b, 0) == wc.npos) {
		count++;
        if (wc.length() > maxl)
            return -1;
		wc.append(a.begin(), a.end());
	}

	return count;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string a;
	string b;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.a = "abcd",
				.b = "cdabcdab",
				.eo = 3,
		},
		{
				 .a = "a",
				 .b = "aa",
				 .eo = 2,
		},
		{
				.a = "abc",
				.b = "cabcabca",
				.eo = 4,
		},
		{
				.a = "abc",
				.b = "wxyz",
				.eo = -1,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->repeatedStringMatch(t[i].a, t[i].b);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
