/*
 * Solution.cpp
 *
 *  Created on: Jan 10, 2022
 *      Author: ysiyer
 */
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

void printL(vector<int> v)
{
	cout << "( " << flush;
	for (auto it = v.begin(); it != v.end(); it++)
		cout << *it << " " << flush;
	cout << ")" << flush;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> result(2, -1);
    	int length = nums.size();
    	int start, end;
    	int mid;

    	if (length == 0)
    		return result;

    	start = 0;
    	end = length;

    	mid = (end - start) / 2;
    	while (mid >= start && mid < end) {
#ifdef DEBUG
    		cout << "nums[" << mid << "]=" << nums[mid] << endl;
#endif
    		if (nums[mid] == target) {
    			int j;

    			result[0] = mid;
    			result[1] = mid;
    			j = mid - 1;
    			while (j >= start && nums[j] == target) {
#ifdef DEBUG
    				cout << "Left Hit: nums[" << j << "]=" << nums[j] << endl;
#endif
    				result[0] = j;
    				j--;
    			}

    			j = mid + 1;
				while (j < end && nums[j] == target) {
#ifdef DEBUG
					cout << "Right Hit: nums[" << j << "]=" << nums[j] << endl;
#endif
					result[1] = j;
					j++;
				}
    			return result;
    		}
    		if (nums[mid] < target) {
    			start =  mid + 1;
#ifdef DEBUG
    			cout << "Ignore left half start=" << start << " end=" << end << endl;
#endif

    		} else if (nums[mid] > target) {
    			end = mid;
#ifdef DEBUG
    			cout << "Ignore right half start=" << start << " end=" << end << endl;
#endif
    		}
    		mid = start + (end - start) / 2;
#ifdef DEBUG
    		cout << "mid=" << mid << endl;
#endif
    	}

    	return result;
    }
};

struct test_input {
	vector<int> list;
	int target;
};

int main()
{
	vector<test_input> t = {
#if 1
			{.list = {5, 7, 7, 8, 8, 10}, .target = 8},
			{.list = {5, 7, 7, 8, 8, 10}, .target = 6},
			{.list = {}, .target = 6},
			{.list = {2, 2}, .target = 2},
			{.list = {1, 3}, .target = 1},
			{.list = {1,2,3}, .target = 3},
#endif
			{.list = {2, 2}, .target = 3},
	};
	vector<int> result;
	Solution s;

	for (auto it = t.begin(); it != t.end(); it++) {
		result = s.searchRange((*it).list, (*it).target);
		printL(result);
	}

}
