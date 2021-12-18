/*
 * isort.cpp
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

void isort(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
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

	isort(arr, n);
	printArr(arr, n);

	return 0;
}
