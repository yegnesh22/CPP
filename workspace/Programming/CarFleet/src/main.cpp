/*
 * main.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <O1.h>

vector<ti> t = {
		{
				.t = 12,
				.p = {10,8,0,5,3},
				.s = {2,4,1,1,3},
				.eo = 3,
		},
		{
				.t = 10,
				.p = {3},
				.s = {3},
				.eo = 1,
		},
		{
				.t = 100,
				.p = {0,2,4},
				.s = {4,2,1},
				.eo = 1,
		},
		{
				.t = 10,
				.p = {6,8},
				.s = {3,2},
				.eo = 2,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->carFleet(t[i].t, t[i].p, t[i].s);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
