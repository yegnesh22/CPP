#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define check_result(x) ((x.eo == x.ao) ? "pass": "fail")

struct ti {
	vector<int> i;
	int k;
	bool eo;
	bool ao;
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k);
};

bool Solution::containsNearbyDuplicate(vector<int>& nums, int k)
{
        int ns = nums.size();
        map<int, bool> wwl;
        int i;

        // Set the first k in the watch window
        for (i = 0; (i < k) && (i < ns); i++) {
                if (wwl.find(nums[i]) == wwl.end())
                        wwl.insert(pair<int, bool>(nums[i], true));
                else
                        return true;
        }

        int wws = 0;
        for (; i < ns; wws++, i++) {
                if (wwl.find(nums[i]) == wwl.end())
                        wwl.insert(pair<int, bool>(nums[i], true));
                else
                        return true;
                wwl.erase(nums[wws]);
        }

        return false;
}

vector<ti> t = {
	{
		.i = {1,2,3,1},
		.k = 3,
		.eo = true,
	},
	{
		.i = {1,0,1,1},
		.k = 1,
		.eo = true,
	},
	{
		.i = {1,2,3,1,2,3},
		.k = 2,
		.eo = false,
	},
	{
		.i = {1},
		.k = 1,
		.eo = false,
	},
	{
		.i = {1,2,3,4,5,6,7,8,9,10},
		.k = 5,
		.eo = false,
	},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->containsNearbyDuplicate(t[i].i, t[i].k);
		cout << i << " -- " << check_result(t[i]) << endl;
	}
	return 0;
}
