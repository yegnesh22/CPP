/*
 * Solution.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string bs;
	int eo;
	int ao;
};

class Solution {
public:
    virtual int hammingWeight(unsigned int n) = 0;
    unsigned int ConvertBStoI(string s);
};

unsigned int Solution::ConvertBStoI(string s)
{
	unsigned int n = 0;
	int count = 31;
	int i = 0;

	while (count >= 0) {
		n = n | ((s[i] - '0') << count);
		count--;
		i++;
	}

	cout << n << endl;
	return n;
}

class Basic: public Solution {
public:
	int hammingWeight(unsigned int n);
};

int Basic::hammingWeight(unsigned int n)
{
	int count = 0;

	while(n) {
		count += n & 1;
		n = n >> 1;
	}
	return count;
}

vector<ti> t = {
		{
				.bs = "00000000000000000000000000001011",
				.eo = 3,
		},
		{
				.bs = "00000000000000000000000010000000",
				.eo = 1,
		},
		{
				.bs = "11111111111111111111111111111101",
				.eo = 31,
		},
};

int main()
{
	Solution* s = new Basic();

	for (size_t i = 0; i < t.size(); i++) {
		t[i].ao = s->hammingWeight(s->ConvertBStoI(t[i].bs));
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
