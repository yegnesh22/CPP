#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr = {5,7,1,2,8,4,3};
	map<int, int> lkp;
	int tsum = 10;

	for (size_t i = 0; i < arr.size(); i++)
		lkp[arr[i]]++;

	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i] == (tsum - arr[i]) && lkp[arr[i]] >= 2) {
			cout << "found combination sum " << arr[i] << " and " << tsum - arr[i] << " = " << tsum << endl;
			return true;
		}
		else if (arr[i] != (tsum - arr[i]) && lkp.find(tsum - arr[i]) != lkp.end()) {
			cout << "found combination sum " << arr[i] << " and " << tsum - arr[i] << " = " << tsum << endl;
			return true;
		}
	}

	cout << "combination sum not found!!" << endl;
	return false;
}

