/*
 * Solution.cpp
 *
 *  Created on: Feb 7, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <Solution.h>

vector<ti> t = {
		{
				.g = {{1,0,0,0}, {1,1,1,0}},
				.h = {{1,0}},
				.eo = {2},
		},
		{
				.g = {{1,0,0,0},{1,1,0,0}},
				.h = {{1,1},{1,0}},
				.eo = {0,0},
		},
		{
				.g = {{1},{1},{1},{1},{1}},
				.h = {{3,0},{4,0},{1,0},{2,0},{0,0}},
				.eo = {1,0,1,0,0},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->hitBricks(t[i].g, t[i].h);
		s->print1DV(t[i].ao);
		s->print1DV(t[i].eo);
		cout << i << " -- " << result(t[i]) << endl;
	}
	return 0;
}
