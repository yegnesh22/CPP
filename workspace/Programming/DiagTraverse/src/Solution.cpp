/*
 * Solution.cpp
 *
 *  Created on: Feb 4, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")
#define printD(a,b,c,d,e) \
		cout << "(" << a << "," << b << "," << c << "," << d << "," << e << ")" << endl;

struct ti {
	vector<vector<int>> i;
	vector<int> eo;
	vector<int> ao;
};

class Solution {
public:
	void printV(vector<int> v);
	vector<int> getDiagonal(vector<vector<int>>& mat, int dc);
	vector<int> findDiagonalOrder(vector<vector<int>>& mat);
};

void Solution::printV(vector<int> v)
{
	cout << "v -- " << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << flush;
	return;
}

vector<int>Solution::getDiagonal(vector<vector<int>>& mat, int dc)
{
	vector<int> ir;
	int nc, nr;
	int c, r;

	nr = mat.size();
	nc = mat[0].size();

	if (dc < nc) {
		r = 0;
		c = dc;
	} else {
		r = dc - nc + 1;
		c = nc - 1;
	}

	while (c >= 0 && r < nr) {
		ir.push_back(mat[r][c]);
		r++;
		c--;
	}

	return ir;
}

vector<int> Solution::findDiagonalOrder(vector<vector<int>>& mat)
{
	int nd = mat.size() + mat[0].size() - 1;
	vector<int> result;
	vector<int> ir;
	int count = 0;

	while (count < nd) {
		ir = getDiagonal(mat, count);
		if ((count & 1) == 0)
			result.insert(result.end(), ir.rbegin(), ir.rend());
		else
			result.insert(result.end(), ir.begin(), ir.end());
		count++;
	}

	return result;
}

vector<ti> t = {
		{
				.i = {{1,2,3},{4,5,6},{7,8,9}},
				.eo = {1,2,4,7,5,3,6,8,9},
		},
		{
				.i = {{1,2},{3,4}},
				.eo = {1,2,3,4},
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->findDiagonalOrder(t[i].i);
		s->printV(t[i].ao);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
