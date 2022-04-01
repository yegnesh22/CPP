/*
 * Solution.cpp
 *
 *  Created on: Mar 20, 2022
 *      Author: ysiyer
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	 int countCollisions(string directions);
};

int Solution::countCollisions(string directions)
{
	int dl = directions.length();
	stack<char> stk;
	int cc = 0;

	for (int i = 0; i < dl; i++) {
		if (directions[i] == 'R')
			stk.push('R');

		if (directions[i] == 'S') {
			if (!stk.empty()) {
				while (!stk.empty() && stk.top() == 'R') {
					cc++;
					stk.pop();
				}
			}
			stk.push('S');
		}
		if (directions[i] == 'L') {
			if (!stk.empty()) {
				if (stk.top() == 'R') {
					cc += 2;
					stk.pop();
                    while (!stk.empty() && stk.top() == 'R')  {
                        cc++;
                        stk.pop();
                    }
					stk.push('S');
				}
				else
					cc++;
			}
		}
	}

	//cout << "returning cc " << cc << endl;
	return cc;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	string directions;
	int eo;
	int ao;
	ti(string d, int e): directions(d), eo(e) {}
};

vector<ti> t = {
	ti("RLRSLL", 5),
	ti("LLRR", 0),
	ti("LLRLRLLSLRLLSLSSSS", 10),
	ti("SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR", 20),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->countCollisions(t[i].directions);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}

