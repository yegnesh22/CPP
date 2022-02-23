/*
 * Solution.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	long lineLength(vector<int> p1, vector<int> p2);
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4);
};

long Solution::lineLength(vector<int> p1, vector<int> p2)
{
	long dy = p2[1] - p1[1];
	long dx = p2[0] - p1[0];

	return (dy*dy + dx*dx);
}

bool Solution::validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
{
	vector<vector<int>> points;
	points.push_back(p1);
	points.push_back(p2);
	points.push_back(p3);
	points.push_back(p4);

	sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];});

	long s1 = lineLength(points[0], points[1]);
	long s2 = lineLength(points[1], points[3]);
	long s3 = lineLength(points[3], points[2]);
	long s4 = lineLength(points[2], points[0]);
	long d1 = lineLength(points[0], points[3]);
	long d2 = lineLength(points[1], points[2]);

	return (s1 == s2 && s2 == s3 && s3 == s4 && d1 == d2 && s1 != 0);
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> p1;
	vector<int> p2;
	vector<int> p3;
	vector<int> p4;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.p1 = {0,0}, .p2 = {1,1}, .p3 = {1,0}, .p4 = {0,1}, .eo = true,
		},
		{
				.p1 = {0,0}, .p2 = {1,1}, .p3 = {1,0}, .p4 = {0,12}, .eo = false,
		},
		{
				.p1 = {1,0}, .p2 = {-1,0}, .p3 = {0,1}, .p4 = {0,-1}, .eo = true,
		},
		{
				.p1 = {0,0}, .p2 = {5,0}, .p3 = {5,4}, .p4 = {0,4}, .eo = false,
		},
		{
				.p1 = {1,1}, .p2 = {5,3}, .p3 = {3,5}, .p4 = {7,7}, .eo = false,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->validSquare(t[i].p1, t[i].p2, t[i].p3, t[i].p4);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
