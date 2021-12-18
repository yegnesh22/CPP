/*
 * isort.cpp
 *
 *  Created on: 18-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include "../../includes/arr.h"

using namespace std;

void isort(int a[], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
		}
	}
}

int main()
{
	isort(arr, n);
	printArr(arr, n);

	return 0;
}
