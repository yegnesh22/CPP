#include <iostream>
#include <map>
#include <climits>

using namespace std;

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int LargeButMinFreq(int arr[], int n)
{
	map<int, int> freq;
	int min_freq = INT_MAX;
	int val = 0;

	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
		min_freq = min(min_freq, it->second);

	for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++)
		val = max(val, it->first);

	return val;
	
}

int main()
{
	int arr[] = {2, 2, 5, 50, 1};
	int N;

	N = ARRAY_SIZE(arr);
	cout << LargeButMinFreq(arr, N);

	return 0;
}

