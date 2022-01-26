/*
 * Solution.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#include <BasicSolution.h>
#include <OptimalSolution.h>
#include <TestInput.h>

vector<ti> t = {
		{
				.t1 = new Tree( { 2, 1, 4 }),
				.t2 = new Tree( { 1, 0, 3 }),
				.eo = { 0, 1, 1, 2, 3, 4 },
		},
		{
				.t1 = new Tree( { 1, 8 }),
				.t2 = new Tree( { 8, 1 }),
				.eo = { 1, 1, 8, 8 },
		},
		{
				.t1 = new Tree(),
				.t2 = new Tree( {5,1,7,0,2}),
				.eo = { 0,1,2,5,7 },
		}
};

int main() {
	Solution *s = new BasicSolution();
	//Solution *s = new OptimalSolution();

	for (int i = 0; i < t.size(); i++) {
		s->printV(s->inorderTraverse(t[i].t1->m_root));
		s->printV(s->inorderTraverse(t[i].t2->m_root));
		t[i].ao = s->getAllElements(t[i].t1->m_root, t[i].t2->m_root);
		s->printV(t[i].ao);
		cout << i << " -- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
