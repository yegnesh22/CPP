#include <iostream>
#include <vector>

using namespace std;

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int> indices;
        unsigned long long sum;
        unsigned int sIndex;
        unsigned int eIndex;
        unsigned int index;
        bool found = false;

        for (int i = 0; i < n; i++) {
            sIndex = i;
            eIndex = i;
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if (sum > s)
                    break;
                else if (sum == s) {
                    indices.push_back(sIndex+1);
                    indices.push_back(j+1);
                    found = true;
                }
            }
            if (found)
                break;
        }
        if (!found)
            indices.push_back(-1);
        return indices;
    }
};

int main()
{
    int arr[] = { 142, 112, 54, 69, 148, 45, 63, 158, 38, 60, 124, 142, 130, 179, 117, 36, 191, 43, 89, 107, 41, 143, 65, 49, 47, 6, 91, 130, 171, 151, 7, 102, 194, 149, 30, 24, 85, 155, 157, 41, 167, 177, 132, 109, 145, 40, 27, 124, 138, 139, 119, 83, 130, 142, 34, 116, 40, 59, 105, 131, 178, 107, 74, 187, 22, 146, 125, 73, 71, 30, 178, 174, 98, 113 };
    vector<int> indices;
    Solution s;
    int S, n;

    cin >> S;
    n = ARRAY_SIZE(arr);
    indices = s.subarraySum(arr, n, S);

    for (vector<int>::iterator it = indices.begin(); it != indices.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}