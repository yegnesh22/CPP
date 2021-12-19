#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        // Code here.
        int index = 0;
        multimap<int, int> lookup;
        vector<int> result;

        for (vector<int>::iterator it = nums.begin(); it != nums.end();
            it++, index++) {
            if (lookup.count(*it) == 0)
                lookup.insert(make_pair(*it, index));
            else
                lookup.erase(*it);
        }
        
        for (multimap<int, int>::iterator it = lookup.begin(); it != lookup.end();
            it++) {
            result.push_back(it->first);
        }

        return result;
    }
};

int main()
{
    vector<int> nums({ 1, 2, 3, 2, 1, 4 });
    vector<int> result;
    Solution s;

    result = s.singleNumber(nums);
    for (vector<int>::iterator it = result.begin(); it != result.end();
        it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
