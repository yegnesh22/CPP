/*
 * Solution.cpp
 *
 *  Created on: Mar 6, 2022
 *      Author: ysiyer
 */

/*
 * Given n orders, each order consist in pickup and delivery services.
 * Count all valid pickup/delivery possible sequences such that
 * delivery(i) is always after of pickup(i). Since the answer may be
 * too large, return it modulo 10^9 + 7.
 *
 * Example:
 * Input: n = 2
 * Output: 6
 * Explanation: All possible orders:
 * (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1)
 * and (P2,D2,P1,D1).
 * This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
 *
 * Math: Permutation and Combination.
 * n = 1 - P1, D1 - can be arranged only 1 way as D1, P1 will be invalid.
 * n = 2 - Consider P1,D1 as a single combo. Out of the 4 slots, choose 2 slots for
 *         P1 and D1. 4C2 ways - 4! / (2! * 2!) = 6 ways. Of these 6 ways, P1 and D1
 *         can be arranged only in 1 ways as calculated above in n=1 case. So total
 *         ways = 6.
 * n = 3 - Consider P1, D1 and P2, D2 as one unit. As calculate above these can inturn
 *         be arranged in 6 different ways. Include P3, D3 there are 6 slots. Out of
 *         these 6, choose 4 slots for P1,D1, P2 and D2. 6C2 ways = 6! / (4! * 2!) = 15 ways.
 *         Out of 15 ways, 6 different combinations of P1, D1, P2 and D2 can be done.
 *         So total ways of arranging = 15 * 6 = 90 ways. P3 and D3 can be arranged in 1 way,
 *         P3 first and D3 second. Total = 90 * 1 ways = 90 ways.
 *  So, N[n] = 2*n * (2*n - 1) / 2 * N[n-1] where N[i] is number of ways in which i orders
 *  can be delivered. N[n] = nC(n-2) * N[n-1].
 *
 *  Answer overflows the 10 bit limit, hence return the answer as modulo of 10^9 + 7 as
 *  mentioned in question.
 */


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int mod = pow(10, 9) + 7;
public:
	int countOrders(int n);
};

int Solution::countOrders(int n)
{
	if (n == 1)
		return 1;

    long prod = (long) n * (long) (2 * n - 1) * (long) countOrders(n - 1);
    return prod % mod;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = 1,
				.eo = 1,
		},
		{
				.n = 2,
				.eo = 6,

		},
		{
				.n = 3,
				.eo = 90,
		},
		{
				.n = 7,
				.eo = 681080400,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countOrders(t[i].n);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
