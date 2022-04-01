/*
 * Solution.cpp
 *
 *  Created on: Mar 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

class Solution {
public:
	void generateString(string& r, int cur, int& n, int& k);
	string getSmallestString(int n, int k);
};

void Solution::generateString(string& r, int cur, int& n, int& k)
{
	if (n == 1) {
		int d = min(k, 26);
		r[cur] = (char) (d + (int) 'a' - 1);
		k = d;
		return;
	}

	int nn = n - 1;
	int kk = k - 1;
	int d;

	generateString(r, cur+1, nn, kk);
	d = min(k - kk, 26);
	k = kk + d;
	r[cur] = (char)(d + (int)'a' - 1);
	return;
}

string Solution::getSmallestString(int n, int k)
{
	string result(n, 'a');
	generateString(result, 0, n, k);
	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	int k;
	string eo;
	string ao;
	ti(int tn, int tk, string teo): n(tn), k(tk), eo(teo) {}
};

vector<ti> t = {
		ti(3, 27, "aay"),
		ti(5, 73, "aaszz"),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->getSmallestString(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
