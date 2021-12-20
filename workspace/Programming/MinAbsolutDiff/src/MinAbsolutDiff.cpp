/*
 * MinAbsolutDiff.cpp
 *
 *  Created on: 20-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int> &arr)
	{
		map<int, vector<vector<int>>> diffList;
		int minDiff = INT_MAX;
		int diff;

		for (vector<int>::iterator it1 = arr.begin(); it1 != arr.end(); it1++) {
			for (vector<int>::iterator it2 = (it1 + 1); it2 != arr.end(); it2++) {
				diff = abs(*it1 - *it2);
				if (diff < minDiff) {
					minDiff = diff;
				}

				vector <int> p = { *it1, *it2 };
				diffList[diff].push_back(p);
			}
		}

		return diffList[minDiff];
	}
};

int main()
{
	//vector<int> arr = {4,2,1,3};
	//vector<int> arr = {1,3,6,10,15};
	vector<int> arr = {3, 8, -10, 23, 19, -4, -14, 27};
	vector<vector<int>> r;
	Solution s;

	r = s.minimumAbsDifference(arr);

	for (vector<vector<int>>::iterator it = r.begin(); it != r.end(); it++) {
		cout << "[" << flush;
		for (vector<int>::iterator its = (*it).begin(); its != (*it).end(); its++) {
			cout << *its << " " << flush;
		}
		cout << "]" << endl;
	}
	return 0;
}
