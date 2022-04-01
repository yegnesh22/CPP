/*
 * Solution.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

class Solution {
public:
	vector<string> cellsInRange(string s);
};

vector<string> Solution::cellsInRange(string s)
{
	vector<string> res;
	int sl = s.length();
	int row[2];
	char col[2];

	col[0] = s[0];
	row[0] = s[1];
	col[1] = s[3];
	row[1] = s[4];

	string cell(2, 'A0');
	for (int i = (char)col[0]; i <= (char)col[1]; i++) {
		for (int j = (char)row[0]; j <= (char)row[1]; j++) {
			cell[0] = (char)i;
			cell[1] = (char)j;
#ifdef DEBUG
			cout << "pushing back " << cell << endl;
#endif
			res.push_back(cell);
		}
	}
	return res;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	string s;
	vector<string> eo;
	vector<string> ao;
	ti(string ts, vector<string> teo): s(ts), eo(teo) {}
};

vector<ti> t = {
		ti("K1:L2", {"K1","K2","L1","L2"}),
		ti("A1:F1", {"A1","B1","C1","D1","E1","F1"}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->cellsInRange(t[i].s);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
