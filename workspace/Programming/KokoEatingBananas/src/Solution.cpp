/*
 * Solution.cpp
 *
 *  Created on: Jan 20, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

#ifdef DEBUG
#define print(x) cout << #x << ":" << x << flush
#define println(x) cout << #x << ":" << x << endl;
#define line cout << endl;
#define space cout << " " << flush;
#else
#define print(x)
#define println(x)
#define line
#define space
#endif

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    	int np = piles.size();
    	int lb = 1;
    	int ub = 0;
    	int rh = h;
    	int speed;

    	for (int i = 0; i < np; i++) {
    		ub = max(ub, piles[i]);
    	}

    	while (lb < ub) {
    		rh = h;
    		speed  = (ub + lb) / 2;
    		//print(speed);space;print(lb);space;print(ub);space;
    		for (int i = 0; i < np; i++) {
    			rh -= (piles[i] / speed) + ((piles[i] % speed) ? 1 : 0);
    			if (rh < 0) {
    				// too slow.. go fast!!
    				lb = speed + 1;
    				break;
    			}
    		}
    		//print(rh);line;

    		if (rh >= 0) {
    			// too fast.. go slow!!
    			ub = speed;
    		}

    	}

    	return lb;
    }
};

struct TestInput {
	vector<int> p;
	int h;
	int eo;
	int ao;
};

int main()
{
	vector<TestInput> t = {
#ifndef DEBUG
			{
					.p = {3,6,7,11},
					.h = 8,
					.eo = 4
			},
			{
					.p = {30,11,23,4,20},
					.h = 5,
					.eo = 30
			},
			{
					.p = {30,11,23,4,20},
					.h = 6,
					.eo = 23
			},
			{
					.p = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184},
					.h = 823855818,
					.eo = 14
			},
#endif
			{
					.p = {6,6},
					.h = 11,
					.eo = 2
			},
			{
					.p = {6},
					.h = 5,
					.eo = 2
			},
	};
	Solution s;

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s.minEatingSpeed(t[i].p, t[i].h);
		cout << "t[" << i << "] -"
				<< " eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].eo == t[i].ao) ? "pass" : "fail")
				<< endl;
	}
	return 0;
}
