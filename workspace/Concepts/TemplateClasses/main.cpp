#include <iostream>
#include "Complex.h"

using namespace std;
using namespace complexns;

template<class T>
class Test {
private:
	T obj;
public:
	Test(T obj) {
		this->obj = obj;
	}
	void print() {
		cout << obj << endl;
	}
};

template<typename T>
void print(T n)
{
	cout << "Template version:" << flush;
	cout << n << endl;
}

void print(int n)
{
	cout << "Non-template version:" << flush;
	cout << n << endl;
}

int main()
{
	Test<string> test1("Hello");
	test1.print();

	Test<int> test2(10);
	test2.print();

	Test<Complex> test3(Complex(10, 20));
	test3.print();

	print(5);
	print<int>(5);
	print("Halon");
	print(Complex(20, 30));
	print(5.5);
}
