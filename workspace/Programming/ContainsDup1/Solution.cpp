#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define check_result(x) ((x.eo == x.ao) ? "pass" : "fail")

struct ti {
	vector<int> i;
	bool eo;
	bool ao;
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};

bool Solution::containsDuplicate(vector<int>& nums)
{
	map<int,bool> lookup;
	int ns = nums.size();

	for (int i = 0; i < ns; i++) {
		if (lookup.find(nums[i]) == lookup.end())
			lookup.insert(pair<int, bool>(nums[i], true));
		else
			return true;
	}

	return false;
}

vector <ti> t = {
	{
		.i = {1,2,3,1},
		.eo = true,
	},
	{
		.i = {1,2,3,4},
		.eo = false,
	},
	{
		.i = {1,1,1,3,3,4,3,2,4,2},
		.eo = true,
	},
};

int main()
{
	Solution* s = new Solution();

	for (int i  = 0; i < t.size(); i++) {
		t[i].ao = s->containsDuplicate(t[i].i);
		cout << i << " -- " << check_result(t[i]) << endl;
	}
	return 0;
}
