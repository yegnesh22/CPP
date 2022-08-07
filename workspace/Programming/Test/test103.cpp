#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
	public:
		int coinsChange(vector<int>& coins, int amount);
		int countCoins(vector<int>& coins, int amount, vector<int>& pay);
};

int Solution::coinsChange(vector<int>& coins, int amount)
{
	if (amount <= 0)
		return 0;

	vector<int> pay(amount, 0);
	return countCoins(coins, amount, pay);
}

int Solution::countCoins(vector<int>& coins, int amount, vector<int>& pay)
{
	int res;

	if (amount < 0)
		return -1;
	if (amount == 0)
		return 0;
	if (pay[amount - 1] != 0)
		return pay[amount - 1];

	int minV = INT_MAX;
	int nc;

	for (int i = 0; i < coins.size(); i++) {
		res = countCoins(coins, amount - coins[i], pay);
		if (res >= 0 && res < minV) {
			minV = 1+res;
		}
	}

	pay[amount - 1] = (minV == INT_MAX) ? -1 : minV;
	return pay[amount - 1];
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> coins;
	int amount;
	int eo;
	int ao;
};

vector<ti> t = {
	{
		.coins = {1,2,5},
		.amount = 11,
		.eo = 3,
	},
	{
		.coins = {2},
		.amount = 3,
		.eo = -1,
	},
	{
		.coins = {1},
		.amount = 0,
		.eo = 0,
	},
	{
		.coins = {186,419,83,408},
		.amount = 6249,
		.eo = 20,
	}, 
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->coinsChange(t[i].coins, t[i].amount);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}

