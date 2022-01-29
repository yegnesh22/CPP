/*
 * Solution.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <Base.h>
#include <Backtrack.h>
#include <DP.h>
#include <Test.h>

vector<ti> t = {
		{
				.i = {2,3,1,1,4},
				.eo = true,
		},
		{
				.i = {3,2,1,0,4},
				.eo = false,
		},
};

int main()
{
	//Solution *s = new BacktrackSolution();
	Solution *s = new DP();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->canJump(t[i].i);
		cout << i << " -- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
