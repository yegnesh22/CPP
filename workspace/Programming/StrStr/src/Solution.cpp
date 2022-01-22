/*
 * Solution.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int strStr(string haystack, string needle) = 0;
};


class BasicSolution: public Solution {
public:
	int strStr(string haystack, string needle) {
		int hl = haystack.length();
		int nl = needle.length();
		bool found;

		for (int i = 0; i <= (hl - nl); i += 1) {
			found = true;
			for (int j = 0; j < nl; j++) {
				if (haystack[i + j] != needle[j]) {
					found = false;
					break;
				}
			}
			if (found)
				return i;
		}

		return -1;
	}
};

struct TI {
	string h;
	string n;
	int eo;
	int ao;
};

vector<TI> t = {
		{
				.h = "hello",
				.n = "ll",
				.eo = 2,
		},
		{
				.h = "aaaa",
				.n = "bba",
				.eo = -1,
		},
		{
				.h = "",
				.n = "",
				.eo = 0,
		},
		{
				.h = "mississippi",
				.n = "issip",
				.eo = 4,
		},
		{
				.h = "abc",
				.n = "c",
				.eo = 2,
		},
		{
				.h = "mississippi",
				.n = "issi",
				.eo = 1,
		},
		{
				.h = "aabaaabaaac",
				.n = "aabaaac",
				.eo = 4,
		},
};

int main()
{
	Solution* s = new BasicSolution();

	for (int i  = 0; i < t.size(); i++) {
		t[i].ao = s->strStr(t[i].h, t[i].n);

		cout << "t[" << i << "] -- eo: " << t[i].eo
				<< " ao: " << t[i].ao
				<< " result: " << ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}

	return 0;
}
