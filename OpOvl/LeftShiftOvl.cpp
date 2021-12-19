#include <iostream>
#include "test.h"

using namespace std;

int main()
{
	Test t1(1, "Mike");

	cout << t1 << endl;

	Test t2 = t1;

	cout << t2 << endl;
}

