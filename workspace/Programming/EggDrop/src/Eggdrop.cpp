/*
 * Eggdrop.cpp
 *
 *  Created on: 15-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>

using namespace std;

class Solution {
public:
	int eggDrop(int N, int K);
};

int Solution::eggDrop(int N, int K)
{
	int mid;

	if ((N == 1) || (K == 1))
		return K;

	mid = (K + 1) / 2;

	if ((K - mid) > (mid - 1))
		return 1 + eggDrop(N, K - mid);
	else
		return 1 + eggDrop(N - 1, mid - 1);
}

int main()
{
	Solution s;
	int N, K;

	cout << "Number of eggs : " << endl;
	cin >> N;
	cout << "Number of floors : " << endl;
	cin >> K;
	cout << s.eggDrop(N, K) << endl;

	return 0;
}
