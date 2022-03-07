/*
 * Solution.cpp
 *
 *  Created on: Mar 7, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

struct compare {
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const
	{
		if (p1.second == p2.second)
			return p1.first < p2.first;
		return p1.second > p2.second;
	}
};

class Solution {
public:
	int minimumOperations(vector<int>& nums);
};

int Solution::minimumOperations(vector<int>& nums)
{
	int nl = nums.size();
	map<int, int> even;
	map<int, int> odd;
	int ops;

	for (int i = 0; i < nl; i++) {
		if (i & 1)
			odd[nums[i]]++;
		else
			even[nums[i]]++;
	}

	set<pair<int, int>, compare> odd_set(odd.begin(), odd.end());
	set<pair<int, int>, compare> even_set(even.begin(), even.end());

	auto oe = odd_set.begin();
	auto ee = even_set.begin();
	while (oe != odd_set.end() && ee != even_set.end() && oe->first == ee->first) {
		auto oen = ++oe;
		auto een = ee;

		int s1 = oen->second + een->second;
		oen = --oe;
		een = ++ee;
		int s2 = oen->second + een->second;

		if (s1 > s2) {
			oe++;
			ee--;
		}
	}

	if (oe == odd_set.end() || ee == even_set.end())
		return min(odd_set.begin()->second, even_set.begin()->second);

	ops = nl - (oe->second + ee->second);
	return ops;
}

int main()
{
	Solution* s = new Solution();
	//vector<int> v ({3,1,3,2,4,3});
	//vector<int> v ({1,2,2,2,2});
	//vector<int> v ({69,91,47,74,75,94,22,100,43,50,82,47,40,51,90,27,98,85,47,14,55,82,52,9,65,90,86,45,52,52,95,40,85,3,46,77,16,59,32,22,41,87,89,78,59,78,34,26,71,9,82,68,80,74,100,6,10,53,84,80,7,87,3,82,26,26,14,37,26,58,96,73,41,2,79,43,56,74,30,71,6,100,72,93,83,40,28,79,24});
	//vector<int> v ({1,1,1,1,1});
	//vector<int> v ({4,3,4,3,4,3,3,5,3,5,3,3});
	//vector<int> v ({2,3,4,1,4,2,2,2});
	//vector<int> v ({2,1,3,1,1,3,1,3});
	vector<int> v ({1,3,4,3,3,2,3,3,2,2,3});

	int ao = s->minimumOperations(v);
	cout << "ao:" << ao << endl;
	return 0;
}
