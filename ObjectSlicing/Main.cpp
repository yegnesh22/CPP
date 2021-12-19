#include <iostream>
using namespace std;

class Parent {
public:
	Parent() {

	}
	Parent(const Parent& other) {
		cout << "copy Parent" << endl;
	}
	virtual void print() {
		cout << "parent" << endl;
	}

	virtual ~Parent() {

	}
};

class child : public Parent {
public:
	void print() {
		cout << "child" << endl;
	}
};

int main()
{
	child c1;
	Parent &p1 = c1;
	p1.print();
	Parent p2 = child();
	p2.print();
	return 0;
}