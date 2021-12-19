/*
 * ssort.cpp
 *
 *  Created on: 18-Dec-2021
 *      Author: yegnesh
 */
#include <iostream>
#include "../../includes/arr.h"

using namespace std;

void ssort(int a[], int n)
{
	int pos;

	for (int i = 0; i < (n - 1); i++) {
		pos = i;
		for (int j = (i + 1); j < n; j++) {
			if (a[pos] > a[j])
				pos = j;
		}
		if (a[i] > a[pos])
			swap(a[i], a[pos]);
	}
}

int main()
{
	ssort(arr, n);
	printArr(arr, n);

	return 0;
}



