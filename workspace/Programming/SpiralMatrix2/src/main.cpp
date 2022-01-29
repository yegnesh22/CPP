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
				.i = 3,
				.eo = {{1,2,3},{8,9,4},{7,6,5}},
		},
		{
				.i = 1,
				.eo = {{1}},
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->generateMatrix(t[i].i);
		s->printV(t[i].eo);
		s->printV(t[i].ao);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
