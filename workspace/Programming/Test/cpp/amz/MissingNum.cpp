#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr = {3,7,1,2,8,4,5,6,10};
	size_t n = arr.size() + 1;
	int sum = n * (n+1) / 2;
	int calc_sum = 0;

	for (size_t i = 0; i < arr.size(); i++)
		calc_sum += arr[i];

	cout << "missing number:" << sum - calc_sum << endl;

	return 0;
}
