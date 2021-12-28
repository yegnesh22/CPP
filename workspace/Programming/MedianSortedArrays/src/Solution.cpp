/*
 * Solution.cpp
 *
 *  Created on: 28-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> s(nums1);
    	double m;

    	s.insert(s.end(), nums2.begin(),nums2.end());
    	sort (s.begin(), s.end());
    	size_t n = s.size();

    	if ((n & 1) == 0) {
    		int i1, i2;
    		i1 = (n + 1) / 2;
    		i2 = (n - 1) / 2;
    		m = double (s[i1] + s[i2]) / double (2);
    	} else {
    		m = s[n / 2];
    	}

    	return m;
    }
};

int main()
{
	Solution s;
	vector<int> a1 = { 1, 3};
	vector<int> a2 = { 2 };

	cout << "median: " << s.findMedianSortedArrays(a1, a2) << endl;
	return 0;
}

