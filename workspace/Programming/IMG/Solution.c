/*
 * Solution.c
 *
 *  Created on: Jul 14, 2022
 *      Author: ysiyer
 */


#include <stdio.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

/*
 * @A[]: Array of ints in the the range 1 to N (inclusive) with
 * any element repeating any number of times. Array is mutable.
 * @N: number of elements in the array.
 * @return: number of repeated numbers found and printed.
 *
 * This function prints repeated elements in the array to standard output.
 */
int partition(int A[], int s, int e) {
    int pivot = A[e];
    int i = s-1;
    int t;

    for (int j = s; j <= e; j++) {
        if (A[j] < pivot) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i+1];
    A[i+1] = A[e];
    A[e] = t;
    return i+1;
}

void quickSort(int A[], int s, int e) {
    int p;
    if (s < e) {
        p = partition(A, s, e);
        quickSort(A, s, p-1);
        quickSort(A, p+1, e);
    }
    return;
}

int cmpfunc(const void* a, const void* b) {
	return(*(int*) a - *(int*)b);
}

int solution(int A[], int N) {
    // write your algorithm in C
    int count = 0;

    // sort the array
    //quickSort(A, 0, N-1);
    qsort(A, N, sizeof(int), cmpfunc);

    int i = 0;
    int j;
    while (i < N) {
        j = i+1;
        while (A[i] == A[j]) {
            printf("%d ", A[j]);
            j++;
            count++;
        }
        i = j;
    }

    return count;
}

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int main()
{
	int A[] = {2, 10, 4, 8, 6, 2, 8, 2, 10, 10};
	printf("\n repeats = %d\n", solution(A, ARRAY_SIZE(A)));
	return 0;
}
