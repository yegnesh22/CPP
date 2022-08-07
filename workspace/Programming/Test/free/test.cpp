#include <iostream>
using namespace std;
class O {
	public:
		void f1() {
			cout << this << endl;
			delete this;
		}
		void f2() {
			cout << this << endl;
			cout << "print" << endl;
		}
};

int main()
{
	O n1;

	n1.f2();
	n1.f1();
	n1.f2();
	n1.f1();

	return 0;
}
