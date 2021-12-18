#ifndef __ARR_H__
#define __ARR_H__

using namespace std;

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

static int arr[] = {64, 34, 25, 12, 22, 11, 90};
static int n = ARRAY_SIZE(arr);

static void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << flush;
	}
	cout << endl;
}

static void swap(int &a, int &b)
{
	int t;

	t = b;
	b = a;
	a = t;
}

#endif

