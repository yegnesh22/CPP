#include <iostream>
#include "Complex.h"

using namespace std;
using namespace complexns;

int main()
{
	Complex c1(5, 3); // Constructor with 2 arguments
	Complex c2(3, 8);
	Complex c3 = c1 + c2;
	Complex c4 = c3 + c2;
	
	cout << c1 << c2 << c3 << endl;

	cout << c2 + c3 << endl;

	cout << c2 + 5 << endl;
	cout << 5 + c3 << endl;

	if (c1 == c2) {
		cout << c1 << " and " << c2 << "are equal!!" << endl;
	} else {
		cout << c1 << " and " << c2 << "are not equal!!" << endl;
	}

	Complex c5 = c4;
	if (c4 == c5) {
		cout << c4 << " and " << c5 << "are equal!!" << endl;
	}
	else {
		cout << c4 << " and " << c5 << "are not equal!!" << endl;
	}
}