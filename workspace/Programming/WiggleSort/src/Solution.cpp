/*
 * Solution.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	void printV(vector<int>& v);
	void wiggleSort(vector<int>& nums);
	void wiggleSort2(vector<int>& nums);
};

void Solution::printV(vector<int>& v)
{
	cout << "[" << flush;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << flush;
	cout << "]" << endl;
}

//nums[0] <= nums[1] >= nums[2] <= nums[3]
void Solution::wiggleSort(vector<int>& nums)
{
	int ns = nums.size() - 1;
	int t;

	sort(nums.begin(), nums.end());

	for (int i = 1; i < ns; i+=2) {
		t = nums[i];
		nums[i] = nums[i+1];
		nums[i+1] = t;
	}

	printV(nums);
	return;
}

// nums[0] < nums[1] > nums[2] < nums[3]
void Solution::wiggleSort2(vector<int>& nums)
{
	vector<int> v(nums.begin(), nums.end());
	int ns = nums.size();
	int j = ns - 1;
	int t;

	sort(v.begin(), v.end());
	for (int i = 1; i < ns; i+=2)
		nums[i] = v[j--];

	for (int i = 0; i < ns; i+=2)
		nums[i] = v[j--];

	printV(nums);
	return;
}

int main()
{
	vector<int> t1 = {1,5,1,1,6,4};
	Solution* s = new Solution();
	vector<int> t = {1,2,3};

	s->wiggleSort(t);
	s->wiggleSort2(t1);

	return 0;
}

