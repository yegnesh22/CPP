/*
 * ssort.cpp
 *
 *  Created on: 18-Dec-2021
 *      Author: yegnesh
 */
#include <iostream>

using namespace std;

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

void swap(int &a, int &b)
{
	int t;

	t = b;
	b = a;
	a = t;
}

void ssort(int a[], int n)
{
	int pos;

	for (int i = 0; i < (n - 1); i++) {
		pos = i;
		for (int j = n; j > i; j--) {
			if (a[pos] > a[j])
				pos = j;
		}
		if (a[i] > a[pos])
			swap(a[i], a[pos]);
	}
}

void printArr(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " " << flush;
	cout << endl;
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = ARRAY_SIZE(arr);

	ssort(arr, n);
	printArr(arr, n);

	return 0;
}



