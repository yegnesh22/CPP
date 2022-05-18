/*
 * Solution.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		int sl = s.length();
		map<char, char> lkp;
		stack<char> stk;

		lkp[')'] = '(';
		lkp['}'] = '{';
		lkp[']'] = '[';

		for (int i = 0; i < sl; i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stk.push(s[i]);
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
				if (stk.empty() || stk.top() != lkp[s[i]])
					return false;
				else
					stk.pop();
			}
		}
		return stk.empty();
	}
};

struct ti {
	string s;
	bool eo;
	bool ao;
	ti(string s, bool eo): s(s), eo(eo) {}
};

vector<ti> tests = {
		ti("()", true),
		ti("()[]{}", true),
		ti("(]", false),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->isValid(t.s);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
