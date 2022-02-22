/*
 * Solution.cpp
 *
 *  Created on: Feb 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define DEBUG

class Solution {
public:
	void printV(vector<int> v);
	vector<int> findClosestElements(vector<int>& arr, int k, int x);
};

void Solution::printV(vector<int> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << flush;
	cout << "}" << endl;
}

vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x)
{
	vector<int> result;
	int ns = arr.size();

	if (x <= arr[0]) {
		result.insert(result.begin(), arr.begin(), arr.begin() + k);
		return result;
	}

	if (x >= arr[ns - 1]) {
		result.insert(result.begin(), arr.begin() + (ns - k), arr.begin() + ns);
		return result;
	}

	// Do a binary search
	int s, e, m;
	int ri, li;
	int left, right;

	s = 0;
	e = ns;
	m = (e - s) / 2 + s;
	while ((s < e) && (m < ns-1)) {
		m = (e - s) / 2 + s;
		if ((arr[m] < x) && (arr[m+1] > x))
			break;
		if ((arr[m-1] < x) && (arr[m] > x))
			break;
		if (arr[m] == x)
			break;
		else if (arr[m] > x)
			e = m - 1;
		else
			s = m + 1;
	}


	m = (e - s) / 2 + s;
#ifdef DEBUG
	cout << "mid: " << m << endl;
#endif
	li = m - 1;
	ri = m;
	while ((result.size() != k) && (ri < ns) && (li >= 0)) {
		left = abs(x - arr[li]);
		right = abs(arr[ri] - x);
#ifdef DEBUG
		cout << "l:" << left << " r:" << right << endl;
#endif
		if (left <= right) {
#ifdef DEBUG
			cout << "pushing left " << arr[li] << endl;
#endif
			result.insert(result.begin(), arr[li]);
			li--;
		} else {
#ifdef DEBUG
			cout << "pushing right " << arr[ri] << endl;
#endif
			result.push_back(arr[ri]);
			ri++;
		}
	}

	if (li < 0) {
		while (result.size() != k) {
			result.push_back(arr[ri]);
			ri++;
		}
	}
	if (ri >= ns) {
		while (result.size() != k) {
			result.insert(result.begin(), arr[li]);
			li--;
		}
	}

	return result;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	int x;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.n = {1,2,3,4,5},
				.k = 3,
				.x = 3,
				.eo = {2,3,4},
		},
		{
				.n = {1,2,3,4,5},
				.k = 4,
				.x = 3,
				.eo = {1,2,3,4},
		},
		{
				.n = {1,2,3,4,5},
				.k = 4,
				.x = -1,
				.eo = {1,2,3,4},
		},
		{
				.n = {1,2,3,4,5},
				.k = 4,
				.x = 6,
				.eo = {2,3,4,5},
		},
		{
				.n = {1,1,1,10,10,10},
				.k = 1,
				.x = 9,
				.eo = {10},
		},
		{
				.n = {-2,-1,1,2,3,4,5},
				.k = 7,
				.x = 3,
				.eo = {-2,-1,1,2,3,4,5},
		},
		{
				.n = {0,0,1,2,3,3,4,7,7,8},
				.k = 3,
				.x = 5,
				.eo = {3,3,4},
		},
		{
				.n = {0,0,0,1,3,5,6,7,8,8},
				.k = 2,
				.x = 2,
				.eo = {1,3},
		},
		{
				.n = {1,10,15,25,35,45,50,59},
				.k = 1,
				.x = 30,
				.eo = {25},
		},
		{
				.n = {1,2},
				.k = 1,
				.x = 1,
				.eo = {1},
		},
		{
				.n = {1,5,10},
				.k = 1,
				.x = 4,
				.eo = {5},
		},
		{
				.n = {1,1,2,3,3,3,4,6,8,8},
				.k = 6,
				.x = 1,
				.eo = {1,1,2,3,3,3},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->findClosestElements(t[i].n, t[i].k, t[i].x);
		s->printV(t[i].ao);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
