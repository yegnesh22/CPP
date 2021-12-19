#include <iostream>
using namespace std;

// Abstract base class - Cannot create object of type animal. Both pure virtual functions have to be 
// defined.
class Animal {
public:
	virtual void run() = 0;
	virtual void speak() = 0;
};

// Abstract base class - Cannot create an object of Dog as it does not have the implementation of the
// pure virtual function 'run'.
class Dog : public Animal {
public:
	virtual void speak() {
		cout << "Woof!!" << endl;
	}
};

// Derived class
class Labrador : public Dog {
public:
	virtual void run() {
		cout << "Labradon running!!" << endl;
	}
};

int main()
{
	Animal* animals[5];
	Labrador lab;

	animals[0] = &lab;
	animals[0]->run();
	animals[0]->speak();

	return 0;
}