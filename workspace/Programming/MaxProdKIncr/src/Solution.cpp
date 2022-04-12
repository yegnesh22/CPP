/*
 * Solution.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <climits>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#ifdef MIN_HEAP_SOLN
class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> wq;
		int ns = nums.size();
		long long int prod = 1;

		for (int i = 0; i < ns; i++)
			wq.push(nums[i]);

		while (k > 0) {
			wq.push(wq.top() + 1);
			wq.pop();
			k--;
		}

		while (!wq.empty()) {
			if (wq.top() == 0)
				return 0;
			prod = (prod * wq.top()) % 1000000007;
			wq.pop();
		}

		return prod;
	}
};
#else
class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		map<int, int> lkp;
		int ns = nums.size();
		long long int prod = 1;

		for (int i = 0; i < ns; i++)
			lkp[nums[i]]++;

		while (k > 0) {
			auto it = lkp.begin();
			int num = it->first;
			if (it->second == 1)
				lkp.erase(num);
			else
				lkp[num]--;
			lkp[num+1]++;
			k--;
		}

		for (auto it = lkp.begin(); it != lkp.end(); it++) {
			if (it->first == 0)
				return 0;
			for (int i = 0; i < it->second; i++)
				prod = (prod * it->first) % 1000000007;
		}

		return prod;
	}
};
#endif

struct ti {
	vector<int> nums;
	int k;
	int eo;
	int ao;
	ti(vector<int> N, int K, int E): nums(N), k(K), eo(E) {}
};

vector<ti> tests = {
		ti({0,4}, 5, 20),
		ti({6,3,3,2}, 2, 216),
		ti({24,5,64,53,26,38}, 54, 180820950),
		ti({92,36,15,84,57,60,72,86,70,43,16}, 62, 800222867),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->maximumProduct(t.nums, t.k);
		cout << "ao:" << t.ao << endl;
		assert(t.ao == t.eo);
		cout << i << " -- pass" << endl;
		i++;
	}
}
