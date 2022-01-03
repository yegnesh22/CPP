/*
 * Solution.cpp
 *
 *  Created on: 03-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define ARRAY_SIZE(x) ( sizeof(x) / sizeof(x[0]) )
//#define DEBUG

class Solution {
public:
	void printL(map<int, set<int>> l) {
		for (auto it = l.begin(); it != l.end(); it++) {
			cout << "Key:" << it->first << " Values:" << flush;
			for (auto its = it->second.begin(); its !=it->second.end(); its++)
				cout << " " << *its << flush;
		}
		cout << endl;
	}

    int findJudge(int n, vector<vector<int>>& trust) {
    	map<int, set<int>> trusted_by;
    	map<int, set<int>> trusts;
    	for (auto it = trust.begin(); it != trust.end(); it++) {
    		vector<int> v = *it;
    		trusted_by[v[1]].insert(v[0]);
    		trusts[v[0]].insert(v[1]);
    	}
#ifdef DEBUG
    	printL(trusted_by);
#endif
    	for (auto it = trusted_by.begin(); it != trusted_by.end(); it++) {
    		set<int> s = it->second;
    		if ( (s.size() ==  (n - 1)) &&
    				(s.find(it->first) == s.end()) &&
					(trusts.find(it->first) == trusts.end()) ) {
    			return it->first;
    		}
    	}

    	return -1;
    }
};

struct test_input {
	int n;
	vector<vector<int>> trust;
};

int main()
{
	Solution s;
	int n;

	struct test_input tests []= {
			[0] = { .n = 2, .trust = { {1, 2} } },
			[1] = { .n = 3, .trust = { {1, 3}, {2, 3} } },
			[2] = { .n = 3, .trust = { {1, 3}, {2, 3}, {3, 1} } },
	};

	n = ARRAY_SIZE(tests);
	for (int i = 0; i < n; i++)
		cout << s.findJudge(tests[i].n, tests[i].trust) << endl;;
	return 0;
}
