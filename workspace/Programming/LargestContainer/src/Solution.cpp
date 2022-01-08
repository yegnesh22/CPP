/*
 * Solution.cpp
 *
 *  Created on: 07-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int length, width, area, maxarea;
    	int right = height.size() - 1;
    	int left = 0;

    	maxarea = 0;
    	while (left < right) {
    		width = right - left;
    		length = min(height[left], height[right]);
    		maxarea = max(maxarea, length * width);
    		if (height[left] < height[right])
    			left++;
    		else
    			right--;
    	}
    	return maxarea;
    }
};

int main()
{
	Solution s;
	vector<vector <int>> t = {
			{1, 8, 6, 2, 5, 4, 8, 3, 7},
			{1, 1},
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << s.maxArea(*it) << endl;

	return 0;
}
