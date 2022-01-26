/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct ti {
	vector<vector<int>> i;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
};

class Solution {
public:
    virtual vector<vector<int>> merge(vector<vector<int>>& intervals) = 0;
    void getV(vector<int> v) {
   		cout << "[" << v[0] << "," << v[1] << "]," << flush;
    }

    string checkResult(struct ti t) {
    	if (t.ao.size() != t.eo.size()) {
    		cout << "Size mismatch ao:" << t.ao.size() << " eo:" << t.eo.size() << endl;
    		return "fail";
    	}

    	for (int i = 0; i < t.ao.size(); i++) {
    		if (t.ao[i] != t.eo[i]) {
    			cout << "content mismatch @ " << i << " ao:";
				getV(t.ao[i]);
				cout << " eo:";
				getV(t.eo[i]);
				cout << endl;
				return "fail";
    		}
    	}

    	return (t.ao == t.eo) ? "pass":"fail";
    }
};

class BasicSolution: public Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int ne = intervals.size();
		vector<int> key;
		vector<bool> lookup(ne, false);
		vector<vector<int>> r;

		// Sort based on start
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
		for (int i = 0; i < ne; i++) {
			key = intervals[i];

			// If the index is not already visited
			if (lookup[i] == false) {
				lookup[i] = true;
				for (int j = i+1; j < ne; j++) {
					if (key[1] >= intervals[j][0]) {
						// Overlapping intervals...
						// Update the limits
						key[1] = max(key[1], intervals[j][1]);
						// Set the index as visited to avoid duplication
						lookup[j] = true;
					}
				}
				r.push_back(key);
			}
		}
		return r;
	}
};

vector<ti> t = {
		{
				.i = {{1,3},{2,6},{8,10},{15,18}},
				.eo = {{1,6},{8,10},{15,18}},
		},
		{
				.i = {{1,4},{4,5}},
				.eo = {{1,5}},
		},
		{
				.i = {{1,4},{0,4}},
				.eo = {{0,4}},
		},
};

int main()
{
	Solution* s = new BasicSolution();

	for (int i  = 0; i < t.size(); i++) {
		t[i].ao = s->merge(t[i].i);
		cout << i << " -- r:" << s->checkResult(t[i]) << endl;
	}

	return 0;
}
