/*
 * Solution.cpp
 *
 *  Created on: Feb 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
	int checkCoins(vector<int>& coins, int amount, vector<int>& pay);
    int coinChange(vector<int>& coins, int amount);
};

int Solution::checkCoins(vector<int>& coins, int amount, vector<int>& pay)
{
	if (amount == 0)
		return 0;

	if (amount < 0)
		return -1;

	if (pay[amount - 1] != 0)
		return pay[amount - 1];

	int minV = INT_MAX;
	// For each amount less than the current, find the minimum number if coins
	// to pay that amount.
	for (int i = 0; i < coins.size(); i++) {
		int res = checkCoins(coins, amount - coins[i], pay);
		if (res >= 0 && res < minV)
			minV = 1 + res;
	}
	// Update the minimum value to pay the amount.
	pay[amount - 1] = (minV == INT_MAX) ? -1 : minV;
	return pay[amount - 1];
}

int Solution::coinChange(vector<int>& coins, int amount)
{
    if (amount < 1)
        return 0;

    vector<int> pay(amount, 0);
    return checkCoins(coins, amount, pay);
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> c;
	int a;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.c = {1,2,5},
				.a = 11,
				.eo = 3,
		},
		{
				.c = {2},
				.a = 3,
				.eo = -1,
		},
		{
				.c = {1},
				.a = 0,
				.eo = 0,
		},
		{
				.c = {186,419,83,408},
				.a = 6249,
				.eo = 20,
		},
};

int main()
{
	Solution* s  = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->coinChange(t[i].c, t[i].a);
		cout << "num coins:"  << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
