/*
 * Solution.cpp
 *
 *  Created on: 02-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
    	vector<int> count(60, 0);
    	int numPairs = 0;
    	int mod;

    	for (size_t i = 0; i < time.size(); i++) {
    		mod = time[i] % 60;
    		count[mod]++;
    	}

    	for (size_t i = 1; i < 30; i++) {
    		// Choose 1 number from 1st set, 1 number from 2nd set
    		// (nC1 * nC1)
    		numPairs += (count[i] * count[60 - i]);
    	}

    	numPairs += count[0] * (count[0] - 1) / 2;
    	numPairs += count[30] * (count[30] - 1) / 2;
    	return numPairs;
    }
};

void printV(vector<int> v)
{
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	return;
}

int main()
{
	Solution s;

	vector<vector <int>> t = {
			{30, 20, 150, 100, 40},
			{60, 60, 60},
			{20, 40},
	};

	for (vector<vector<int>>::iterator it = t.begin(); it != t.end();
			it++) {
		cout << "Test sample: " << flush;
		printV(*it);
		cout << s.numPairsDivisibleBy60(*it) << endl;
	}
}
