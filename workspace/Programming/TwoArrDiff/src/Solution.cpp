/*
 * Solution.cpp
 *
 *  Created on: Mar 27, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

//#define DEBUG

#ifdef DEBUG
void printM(vector<vector<int>> n)
{
	for (int i = 0; i < 2; i++) {
		cout << i << " --> " << flush;
		for (int j = 0; j < n[i].size(); j++) {
			cout << n[i][j] << " " << flush;
		}
		cout << endl;
	}
}
#endif

class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
};

vector<vector<int>> Solution::findDifference(vector<int>& nums1, vector<int>& nums2)
{
	sort(nums1.begin(), nums1.end());
	sort(nums2.begin(), nums2.end());

	size_t n1i = 0;
	size_t n2i = 0;

	while (n1i < nums1.size() && n2i < nums2.size()) {
#ifdef DEBUG
		cout << "[0]: i: "<< n1i << " s:" << nums1.size() << endl;
		cout << "[1]: i: "<< n2i << " s:" << nums2.size() << endl;
#endif
		if (nums1[n1i] == nums2[n2i]) {
			int key = nums1[n1i];
			while ((n1i < nums1.size()) && (nums1[n1i] == key)) {
#ifdef DEBUG
				cout << "[1]: (" << n1i << "," << nums1[n1i] << ")" << endl;
#endif
				nums1.erase(nums1.begin() + n1i);
			}
			while ((n2i < nums2.size()) && (nums2[n2i] == key)) {
#ifdef DEBUG
				cout << "[2]: (" << n2i << "," << nums2[n2i] << ")" << endl;
#endif
				nums2.erase(nums2.begin() + n2i);
			}
#ifdef DEBUG
			cout << "1 -- next indices " << n1i << " " << n2i << endl;
			printM({nums1, nums2});
#endif
			continue;
		}
		if (nums1[n1i] < nums2[n2i]) {
			int key = nums1[n1i];
			while ((n1i < nums1.size() - 1) && (nums1[n1i+1] == key))
				nums1.erase(nums1.begin() + (n1i+1));
			n1i++;
#ifdef DEBUG
			cout << "2 -- next indices " << n1i << " " << n2i << endl;
			printM({nums1, nums2});
#endif
			continue;
		}
		if (nums1[n1i] > nums2[n2i]) {
			int key = nums2[n2i];
			while ((n2i < nums2.size() - 1) && (nums2[n2i+1] == key))
				nums2.erase(nums2.begin() + (n2i+1));
			n2i++;
#ifdef DEBUG
			cout << "3 -- next indices " << n1i << " " << n2i << endl;
			printM({nums1, nums2});
#endif
			continue;
		}
	}

	while ((nums1.size() > 1) && (n1i < nums1.size() - 1)) {
		if (nums1[n1i+1] == nums1[n1i])
			nums1.erase(nums1.begin() + (n1i+1));
		else
			n1i++;
#ifdef DEBUG
		cout << "4 -- next indices " << n1i << " " << n2i << endl;
		printM({nums1, nums2});
#endif
	}
	while ((nums2.size() > 1) && (n2i < nums2.size() - 1)) {
		if (nums2[n2i+1] == nums2[n2i])
			nums2.erase(nums2.begin() + (n2i+1));
		else
			n2i++;
#ifdef DEBUG
		cout << "5 -- next indices " << n1i << " " << n2i << endl;
		printM({nums1, nums2});
#endif
	}

	return {{nums1, nums2}};
}

struct ti {
	vector<int> nums1;
	vector<int> nums2;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
	ti(vector<int> n1, vector<int> n2, vector<vector<int>> teo): nums1(n1), nums2(n2), eo(teo) {}
};

vector<ti> t = {
#ifndef DEBUG
	ti({1,2,3}, {2,4,6}, {{1,3}, {4,6}}),
	ti({1,2,3,3}, {1,1,2,2}, {{3}, {}}),
	ti({180,159,326,412},
		{51,69,-401,268,-216,289,207,9,-305,321,426,495,419,-474,481,-181,-420,
		-280,73,-500,-294,337,-24,-90,496,368,-235,-202,426,393,-464,415,24,55,
		-444,-436,139,458,383,-384,-396},
		{{159,180,326,412},
		{-500,-474,-464,-444,-436,-420,-401,-396,-384,-305,-294,-280,-235,-216,
		-202,-181,-90,-24,9,24,51,55,69,73,139,207,268,289,321,337,368,383,393,
		415,419,426,458,481,495,496}}),
#endif
	ti({20,-12,25,24,-15,-3,-21,10,20,23,2,-8,18,13,5,25,-14,-12,25,-2,-14,-5,21,1,-13},
		{-10,-17,-13,-7,4,-14,0,11,-23,13,20,11,-19,-15,-13,11,4,-9,16,-9,4,7,-25,-24,14},
		{{-21,-12,-8,-5,-3,-2,1,2,5,10,18,21,23,24,25},{-25,-24,-23,-19,-17,-10,-9,-7,0,4,7,11,14,16}}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findDifference(t[i].nums1, t[i].nums2);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- " << "pass" << endl;
	}

	return 0;
}


