/*
 * main.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <Base.h>
#include <Basic.h>

vector<ti> t = {
		{
				.i = {{1,2,3},{4,5,6},{7,8,9}},
				.eo = {1,2,3,6,9,8,7,4,5},
		},
		{
				.i = {{1,2,3,4},{5,6,7,8},{9,10,11,12}},
				.eo = {1,2,3,4,8,12,11,10,9,5,6,7},
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->spiralOrder(t[i].i);
		s->printV(t[i].eo);
		s->printV(t[i].ao);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
