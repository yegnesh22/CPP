/*
 * Solution.cpp
 *
 *  Created on: Jan 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int rstart, rlen;
    	unsigned int k;
    	string result;
    	int carry = 0;
    	int sum = 0;
    	int i, j;
    	char ch;

    	i = a.length() - 1;
    	j = b.length() - 1;
    	k = max(a.length(), b.length());
    	rlen = k + 1;
    	result.resize(rlen);
    	while (i >= 0 && j >= 0) {
    		sum = (a[i] - '0') + (b[j] - '0') + carry;
    		ch = (sum & 0x1) + '0';
    		carry = (sum & 0x2) >> 1;
    		result[k] = ch;
#ifdef DEBUG
    		cout << "result[" << k << "]=" << result[k] << endl;
#endif
    		i--;
    		j--;
    		k--;
    	}

#ifdef DEBUG
    	cout << "(" << i << "," << j << ")" << endl;
#endif
    	while (j >= 0) {
    		sum = (b[j] - '0') + carry;
    		ch = (sum & 0x1) + '0';
    		carry = (sum & 0x2) >> 1;
    		result[k] = ch;
#ifdef DEBUG
    		cout << "result[" << k << "]=" << result[k] << endl;
#endif
    		j--;
    		k--;
    	}

    	while (i >= 0) {
    		sum = (a[i] - '0') + carry;
    		ch = (sum & 0x1) + '0';
    		carry = (sum & 0x2) >> 1;
    		result[k] = ch;
#ifdef DEBUG
    		cout << "result[" << k << "]=" << result[k] << endl;
#endif
    		i--;
    		k--;
    	}

    	if (carry) {
    		result[k]='1';
#ifdef DEBUG
    		cout << "result[" << k << "]=" << result[k] << endl;
#endif
    		rstart = 0;
    	} else
    		rstart = 1;

#ifdef DEBUG
    	cout << "rstart=" << rstart
    			<< "rlen=" << rlen
				<< "result=" << result << endl;
#endif
    	return result.substr(rstart, rlen);
    }
};

int main()
{
	Solution s;
	vector<vector<string>> t = {
			{"11", "1"},
			{"1010", "1011"},
	};

	for (auto it = t.begin(); it != t.end(); it++) {
		string a, b;
		a = (*it)[0];
		b = (*it)[1];
		cout << a << " + " << b << " = " << s.addBinary(a, b) << endl;
	};

	return 0;
}
