/*
 * Solution.cpp
 *
 *  Created on: May 30, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <assert.h>
#include <vector>
#include <queue>

using namespace std;

struct ti {
	vector<vector<int>> matrix;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
	ti(vector<vector<int>> matrix, vector<vector<int>> eo): matrix(matrix), eo(eo) {}
};

class Solution {
private:
	void printV(vector<vector<int>>& m) {
		for (int i = 0; i < m.size(); i++) {
			for (int j = 0; j < m[i].size(); j++)
				cout << m[i][j] << " " << flush;
			cout << endl;
		}
	}
public:
	void rotateM(int s, vector<vector<int>>& m) {
		int e = m.size() - 1 - s;

		if (e <= s)
			return;

		// Rotate the outer ring by 90 degrees
		queue<int> wq;
		for (int i = s; i <= e; i++) {
			cout << "pushing " << m[s][i] << endl;
			wq.push(m[s][i]);
		}
		for (int j = s+1; j <= e; j++) {
			wq.push(m[j][e]);
			cout << "pushing " << m[j][e] << endl;
			m[j-1][e] = wq.front();
			cout << "m[" << j-1 << "][" << e << "]=" << m[j-1][e] << endl;
			wq.pop();
		}
		for (int i = e-1; i >= s; i--) {
			wq.push(m[e][i]);
			cout << "pushing " << m[e][i] << endl;
			m[e][i+1] = wq.front();
			cout << "m[" << e << "][" << i+1 << "]=" << m[e][i+1] << endl;
			wq.pop();
		}
		for (int j = e-1; j > s; j--) {
			wq.push(m[j][s]);
			cout << "pushing " << m[j][s] << endl;
			m[j+1][s] = wq.front();
			cout << "m[" << j+1 << "][" << s << "]=" << m[j+1][s] << endl;
			wq.pop();
		}
		for (int i = s+1; i >= s; i--) {
			m[i][s] = wq.front();
			cout << "m[" << i << "][" << s << "]=" << m[i][s] << endl;
			wq.pop();
		}
		for (int j = s+1; j < e; j++) {
			m[s][j] = wq.front();
			cout << "m[" << s << "][" << j << "]=" << m[s][j] << endl;
			wq.pop();
		}


		// Recursive call for rotating the inner square
		rotateM(s+1, m);
		return;
	}
	void RotMatrix(vector<vector<int>>& m) {
		rotateM(0, m);
		printV(m);
	}
};

vector<ti> tests = {
		ti({{1,2,3},{4,5,6},{7,8,9}}, {{7,4,1}, {8,5,2}, {9,6,3}}),
		ti({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}, {{13,9,5,1},{14,10,6,2},{15,11,7,3},{16,12,8,4}}),
		ti({{1,2},{3,4}},{{3,1},{4,2}}),
};

int main()
{
	Solution* s = new Solution();

	for (auto t: tests) {
		s->RotMatrix(t.matrix);
		assert(t.matrix == t.eo);
	}

	return 0;
}
