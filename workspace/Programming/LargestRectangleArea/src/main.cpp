/*
 * main.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */


#include <ti.h>
#include <Basic.h>
#include <O1.h>
#include <O2.h>

vector<ti> t = {
		{
				.i = {2,1,5,6,2,3},
				.eo = 10,
		},
		{
				.i = {2,4},
				.eo = 4,
		},
		{
				.i = {2,1,2},
				.eo = 3,
		},
};

int main()
{
	//Solution *s = new BasicSolution();
	//Solution *s = new O1();
	Solution *s = new O2();

	// Add a new testcase with 30000 entries
	vector<int> newi (25000, 1);
	ti nt;
	nt.i = newi;
	nt.eo = newi.size();
	t.push_back(nt);

	for (int i  = 0; i < t.size(); i++) {
		t[i].ao = s->largestRectangleArea(t[i].i);
		cout << i << " -- " << (t[i].ao == t[i].eo ? "pass": "fail") << endl;
	}

	return 0;
}

