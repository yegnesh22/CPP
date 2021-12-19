#include <iostream>

using namespace std;

void test()
{
	cout << __func__ << endl;
}

void test1()
{
	cout << __func__ << endl;
}

int main() {
	void (*fptr) ();

	fptr = test;
	fptr();

	fptr = test1;
	fptr();

	return 0;
}