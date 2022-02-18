/*
 * Solution.cpp
 *
 *  Created on: Feb 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k);
};

string Solution::removeKdigits(string num, int k)
{
	int nl = num.length();
	string result;
	int i = 0;
    int el = nl - k;

	if (k >= nl)
		return "0";

	while (i < nl) {
		while ((!result.empty()) && (num[i] < result.back()) && (k > 0)) {
			result.pop_back();
			k--;
		}

        result.push_back(num[i]);
		i++;
	}

    while (k > 0) {
        result.pop_back();
        k--;
    }

    while (result.front() == '0')
    	result.erase(0, 1);

    if (result.empty())
        return "0";

	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string i;
	int k;
	string eo;
	string ao;
};

vector<ti> t = {
		{
				.i = "1432219", .k = 3, .eo = "1219",
		},
		{
				.i = "10200", .k = 1, .eo = "200",
		},
		{
				.i = "10", .k = 2, .eo = "0",
		},
		{
				.i = "10001", .k = 4, .eo = "0",
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeKdigits(t[i].i, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
