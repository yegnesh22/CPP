/*
 * triplet.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>

using namespace std;

#define ARRAY_SIZE(n)	((sizeof(n) / sizeof(n[0])))

class Solution {
public:
	bool findTriplets(int arr[], int n)
	{
		int i, j, k;
		int sum;

		for (i = 0; i < (n-2) ; i++) {
			for (j = (i + 1); j < (n - 1); j++) {
				for (k = (j + 1); k < n; k++) {
					sum = arr[i] + arr[j] + arr[k];
					if (sum == 0)
						return true;
				}
			}
		}
		return false;
	}
};

int arr[] = { -1, 0, 1, 2, 3};
//int arr[] = {1, 2, 3};

int main()
{
	Solution s;
	string result;

	result = (s.findTriplets(arr, ARRAY_SIZE(arr))) ? "" : "No ";
	cout <<  result << "Triplets found!!" << endl;
}


