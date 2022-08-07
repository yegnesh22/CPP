#include <bits/stdc++.h>

using namespace std;

void printV(vector<int>& arr) {
	cout << "{" << flush;
	for (auto it: arr)
		cout << it << " " << flush;
	cout << "}" << endl;
}

bool findKey(int key, vector<int>& arr) {
	size_t ns = arr.size();
	size_t pivot = 0;

	for (size_t i = 0; i < ns-1; i++) {
		if (arr[i] > arr[i+1]) {
			pivot = i;
			break;
		}
	}

	size_t s = 0;
	size_t e = ns;

	if (pivot != 0) {
		// array rotated
		if (arr[0] < key && arr[pivot] > key)
			e = pivot+1;
		if (arr[pivot+1] < key && arr[ns-1] > key)
			s = pivot+1;
	}

	cout << "searching between indices " << s << " and " << e << endl;

	size_t m;
	while(s < e) {
		m = s + ((e - s) >> 1);
		cout << "arr[" << m << "]=" << arr[m] << endl;
		if (arr[m] == key)
			break;

		if (arr[m] < key)
			s = m+1;
		else
			e = m;
	}
	return arr[m] == key;
}

int main(int argc, char*argv[])
{
	//vector<int> arr = {176,188,199,200,210,222,1,10,20,47,59,63,75,88,99,107,120,133,155,162};
	vector<int> arr = {1,10,20,47,59,63,75,88,99,107,120,133,155,162,176,188,199,200,210,222};
	int key = arr[0];

	if (argc == 2)
		key = stoi(argv[1]);

	printV(arr);
	cout << key << ":" << (findKey(key, arr) ? "found":"Not found") << endl;
	return 0;
}
