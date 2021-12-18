/*
 * bsort.cpp
 *
 *  Created on: 18-Dec-2021
 *      Author: yegnesh
 */
#include <iostream>

using namespace std;

#define ARRAY_SIZE(x) ((sizeof(x) / sizeof(x[0])))

void swap(int &a, int &b)
{
	int t;

	t = b;
	b = a;
	a = t;
}

void bsort(int a[], int n)
{
	int i, j;
	bool swapped;

	for (i = 0; i < (n - 1) ; i++) {
		swapped = false;
		for (j = 0; j < (n - i -1); j++) {
			if (a[j] > a[j+1] ) {
				swap(a[j], a[j+1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << flush;
	}
	cout << endl;
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = ARRAY_SIZE(arr);

	bsort(arr, n);
	printArr(arr, n);

	return 0;
}


