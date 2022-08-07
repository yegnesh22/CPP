#include <bits/stdc++.h>

using namespace std;

typedef vector<int> matrixrow;
typedef vector<vector<int>> matrix;

matrix MatAdd(matrix& X, matrix& Y) {
	matrix result;

	for (size_t i = 0; i < X.size(); i++) {
		matrixrow r;
		for (size_t j = 0; j < X[i].size(); j++)
			r.push_back(X[i][j] + Y[i][j]);
		result.push_back(r);
	}

	return result;
}

matrix MatSub(matrix& X, matrix& Y) {
	matrix result;

	for (size_t i = 0; i < X.size(); i++) {
		matrixrow r;
		for (size_t j = 0; j < X[i].size(); j++)
			r.push_back(X[i][j] - Y[i][j]);
		result.push_back(r);
	}

	return result;
}

matrix MatMul(matrix& X, matrix& Y) {
	matrix result;
	for (size_t i = 0; i < X.size(); i++) {
		matrixrow row;
		for (size_t j = 0; j < Y[0].size(); j++) {
			int e = 0;
			for (size_t k = 0; k < Y.size(); k++) {
				e += X[i][k] * Y[k][j];
			}
			row.push_back(e);
		}
		result.push_back(row);
	}
	return result;
}

void printV(matrix& r) {
	for (size_t i = 0; i < r.size(); i++) {
		cout << "[ " << flush;
		for (size_t j = 0; j < r[i].size(); j++)
			cout << r[i][j] << " " << flush;
		cout << "]" << endl;
	}
}

int main()
{
	matrix X = {{12,7,3}, {4 ,5,6}, {7 ,8,9}};
	matrix Y = {{5,8,1}, {6,7,3}, {4,5,9}};
	matrix result;

	printV(X);
	printV(Y);

	result = MatAdd(X, Y);
	printV(result);

	result = MatSub(X, Y);
	printV(result);

	result = MatMul(X, Y);
	printV(result);
	
	return 0;
}
