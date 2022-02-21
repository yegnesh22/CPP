/*
 * Solution.cpp
 *
 *  Created on: Feb 21, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<string> i;
	vector<string> eo;
	vector<string> ao;
};

class Solution {
public:
    vector<string> removeComments(vector<string>& source);
};

vector<string> Solution::removeComments(vector<string>& source)
{
	vector<string> modified;
	stack<char> cb;
	string cs;
	bool slc;
	string m;
	int l;

	for (int i = 0; i < source.size(); i++) {
		l = source[i].length();
		cs = source[i];
		slc = false;
		for (int j = 0; j < l && !slc; j++) {
			if (!cb.empty()) {
				if (cs[j] == '*' && cs[j+1] == '/') {
					while (!cb.empty()) cb.pop();
					j++;
					continue;
				}
				cb.push(cs[j]);
				continue;
			}
			if (cs[j] == '/' && cs[j+1] == '/') {
				slc = true;
				continue;
			}
			if (cs[j] == '/' && cs[j+1] == '*') {
				cb.push(cs[j]);
				cb.push(cs[j+1]);
				j++;
				continue;
			}

			m.push_back(cs[j]);
		}

		if (!m.empty() && cb.empty()) {
			modified.push_back(m);
            m.clear();
		}
	}

	return modified;
}

vector<ti> t = {
		{
				.i = {
						"/*Test program */",
						"int main()",
						"{ ",
						"  // variable declaration ",
						"int a, b, c;",
						"/* This is a test",
						"   multiline  ",
						"   comment for ",
						"   testing */",
						"a = b + c;",
						"}"
				},
				.eo = {
						"int main()",
						"{ ",
						"  ",
						"int a, b, c;",
						"a = b + c;",
						"}"
				},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeComments(t[i].i);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
