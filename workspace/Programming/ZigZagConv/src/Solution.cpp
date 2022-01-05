/*
 * Solution.cpp
 *
 *  Created on: 01-Jan-2022
 *      Author: yegnesh
 */
#include <iostream>
#include <vector>

using namespace std;

struct test_input {
	string input;
	int numRows;
};

typedef enum {
	zig,
	zag
} direction;

class Solution {
public:
	void printS(vector<string> sc) {
		for (auto it = sc.begin(); it != sc.end(); it++)
			cout << *it << endl;
	}

    string convert(string s, int numRows) {
    	if (numRows == 1)
    		return s;

    	int len = s.length();
    	int j = 0;
    	direction dir = zig;
    	vector<string> sc(numRows);

    	for (int i = 0; i < len; i++) {
    		sc[j] += s[i];
#ifdef DEBUG
    		cout << "i=" << i << " j=" << j << endl;
    		printS(sc);
#endif
    		if(dir == zig)
    			j++;
    		else
    			j--;

    		if (j == numRows) {
    			j = numRows - 2;
    			dir = zag;
    		}
    		if (j == -1) {
    			j = 1;
    			dir = zig;
    		}
    	}

#ifdef DEBUG
    	printS(sc);
#endif
    	string result;
    	for (auto it = sc.begin(); it != sc.end(); it++)
    		result += *it;
    	return result;
    }
};


int main()
{
	Solution s;
	vector<test_input> t = {
			{ .input = "PAYPALISHIRING", .numRows = 3 },
			{ .input = "PAYPALISHIRING", .numRows = 4 },
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << s.convert((*it).input, (*it).numRows) << endl;
	return 0;
}
