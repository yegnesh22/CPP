/*
 * two-sum.cpp
 *
 *  Created on: 20-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target) {
		map<int, vector<int>>::iterator match;
		map<int, vector<int>> lookup;
		vector<int> result;
		int search_num;
		int i = 0;

		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
				search_num = target - *it;
				match = lookup.find(search_num);
				if (match !=  lookup.end()) {
					result.push_back((lookup[search_num])[0]);
					result.push_back(i);
					break;
				} else {
					lookup[*it].push_back(i);
				}
				i++;
		}
		return result;
	}
};

int main()
{
	//vector<int> nums = {2, 7, 11, 15};
	//vector<int >nums = {3, 2, 4};
	vector<int> nums = {3, 3};
	vector<int> result;
	//int target = 9;
	//int target = 6;
	int target = 6;
	Solution s;

	result = s.twoSum(nums, target);

	for (vector<int>::iterator it = result.begin(); it != result.end(); it++)
		cout << *it << " " << flush;

	cout << endl;
}
