/*
 * Solution.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> i;
	int eo;
	int ao;
};

class Solution {
public:
    virtual int maxProfit(vector<int>& prices) = 0;
};

class BF:public Solution {
public:
	int maxProfit(vector<int>& prices);
};

/*
 * Logic:
 * The points of interest are the peaks and valleys in the given graph. We need
 * to find the largest peak following the smallest valley. We can maintain two
 * variables - minprice and maxprofit corresponding to the smallest valley and
 * maximum profit (maximum difference between selling price and minprice)
 * obtained so far respectively.
 *
 */

class OP:public Solution {
public:
	int maxProfit(vector<int>& prices);
};

int BF::maxProfit(vector<int>& prices)
{
	int best = 0;

	for (int i = 0; i < prices.size(); i++) {
		for (int j = i + 1; j < prices.size(); j++) {
			if (prices[i] < prices[j])
				best = max(best, (prices[j] - prices[i]));
		}
	}

	return best;
}

int OP::maxProfit(vector<int>& prices)
{
	int best = 0;
	int lp = INT_MAX;

	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < lp)
			lp = prices[i];
		else if ((prices[i] - lp) > best)
			best = prices[i] - lp;
	}

	return best;
}


vector<ti> t = {
		{
				.i = {7,1,5,3,6,4},
				.eo = 5,
		},
		{
				.i = {7,6,4,3,1},
				.eo = 0,
		}
};

int main()
{
	//Solution *s = new BF();
	Solution *s = new OP();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->maxProfit(t[i].i);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
