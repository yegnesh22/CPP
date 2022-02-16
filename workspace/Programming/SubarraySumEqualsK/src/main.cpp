/*
 * main.cpp
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#include <On2.h>
#include <On.h>
#include <ti.h>

vector<ti> t = {
#ifndef DEBUG
		{
				.n = {1,1,1},
				.k = 2,
				.eo = 2,
		},
		{
				.n = {1,2,3},
				.k = 3,
				.eo = 2,
		},
		{
				.n = {1,2,1,2,1},
				.k = 3,
				.eo = 4,
		},
#endif
		{
				.n = {1,-1,0},
				.k = 0,
				.eo = 3,
		},
};

int main()
{
	Base* s = new On();

	for (size_t i = 0; i < t.size(); i++) {
		t[i].ao = s->subarraySum(t[i].n, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
