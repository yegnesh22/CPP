/*
 * Solution.cpp
 *
 *  Created on: Apr 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {
		int dcount;

		for (int i = 0; i < chars.size();) {
			dcount = 0;
			while (((i+1) < chars.size()) && (chars[i] == chars[i+1])) {
				chars.erase(chars.begin() + (i + 1));
				dcount++;
			}
			if (dcount > 0)
				dcount++;
			int dC = 1;
			while (dcount > 0) {
				char c = (dcount % 10) + '0';
				dcount /= 10;
				dC++;
				chars.insert(chars.begin()+i+1, c);
			}
			i += dC;
		}

		return chars.size();
	}
};

struct ti {
	vector<char> chars;
	vector<char> eoc;
	int eo;
	int ao;
	ti(vector<char> chars, vector<char> eoc, int eo): chars(chars), eoc(eoc), eo(eo) {}
};

vector<ti> tests = {
		ti ({'a','a','b','b','c','c','c'}, {'a', '2', 'b', '2', 'c', '3'}, 6),
		ti({'a'}, {'a'}, 1),
		ti({'a','b','b','b','b','b','b','b','b','b','b','b','b'}, {'a', 'b', '1', '2'}, 4),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.ao = s->compress(t.chars);
		assert(t.eo == t.ao && t.chars == t.eoc);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
