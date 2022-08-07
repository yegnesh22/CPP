#include <bits/stdc++.h>

using namespace std;

void findIndex(vector<int>& arr, int key, size_t& l, size_t& h) {
	size_t ss = arr.size();
	size_t e = ss;
	size_t s = 0;
	size_t m;

	h = -1;
	l = -1;

	cout << "h:" << h << " l:" << l << endl;
	while (s < e) {
		m = s + ((e - s) >> 1);
		if (arr[m] == key)
			break;
		if (arr[m] < key)
			s = m+1;
		else
			e = m;
	}

	if (m < e && arr[m] == key) {
		h = m;
		l = m;
		while (arr[l] == key && l >= 0) l--;
		l++;
		while (arr[h] == key && h < ss) h++;
		h--;
	} else
		cout << key << " not found" << endl;

	cout << "h:" << h << " l:" << l << endl;
	return;
}

int main(int argc, char* argv[])
{
                        // 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
	vector<int> arr = {1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 8};
	size_t lo;
	size_t hi;
	int key = arr[0]; // default key

	cout << argc << endl;
	if (argc == 2)
		key = stoi(argv[1]);

	cout << "Looking for key: " << key << endl;
	for (size_t i = 0; i < arr.size(); i++)
		cout << "[" << i << "]=" << arr[i] << endl;
	findIndex(arr, key, lo, hi);

	cout << "key:" << key << " lo:" << lo << " hi:" << hi << endl;
	return 0;
}

