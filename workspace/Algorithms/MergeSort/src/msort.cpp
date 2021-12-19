/*
 * msort.cpp
 *
 *  Created on: 18-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <list>
#include "../../includes/arr.h"

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int ls, le, rs, re;
	list<int> newarr;
	int i, j;

	ls = l;
	le = m;
	rs = m + 1;
	re = r;
	i = ls;
	j = rs;

	while (i <= le && j <= re) {
		if (arr[i] < arr[j]) {
			newarr.push_back(arr[i]);
			i++;
		} else {
			newarr.push_back(arr[j]);
			j++;
		}
	}

	while (j <= re) {
		newarr.push_back(arr[j]);
		j++;
	}

	while (i <= le) {
		newarr.push_back(arr[i]);
		i++;
	}

	for (list<int>::iterator it = newarr.begin(); it != newarr.end(); it++) {
		arr[ls] = *it;
		ls++;
	}
}

void msort(int arr[], int l, int r)
{
	int mid;

	if (l < r) {
		mid = l + (r - l) / 2;

		msort(arr, l, mid);
		msort(arr, (mid + 1), r);
		merge(arr, l, mid, r);
	}
	return;
}


int main()
{
	msort(arr, 0, (n-1));
	printArr(arr, n);
	return 0;
}

