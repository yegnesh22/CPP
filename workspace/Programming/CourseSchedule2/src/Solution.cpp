/*
 * Solution.cpp
 *
 *  Created on: Apr 18, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses, vector<int>{});
		int pl = prerequisites.length();
		vector<int> result;

		for (int i = 0; i < pl; i++)
			graph[prerequisites[i][0]].append(prerequisites[i][1]);


		return result;
	}
};

struct ti {
	vector<vector<int>> prerequisites;
	int numCourses;
	vector<int> eo;
	vector<int> ao;
	ti(vector<vector<int>> prerequisites, int numCourses, vector<int> eo): prerequisites(prerequisites), numCourses(numCourses), eo(eo) {}
};

vector<ti> tests = {
		ti({{1,0}}, 2, {0,1}),
		ti({{2,0}, {3,1}, {3,2}}, 4, {0,2,1,3}),
		ti({}, 1, {0}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.eo = s->findOrder(t.numCourses, t.prerequisites);
		assert(t.eo == t.ao);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
