#include <iostream>

using namespace std;

class Base {
	private:
		void funcC() { funcB(); };
	protected:
		void funcB() { funcA(); };
	public:
		virtual void funcA() = 0;
};

class child: public Base {
	public:
		virtual void funcA() { cout << "child funcA" << endl; };
};

int main()
{
	child c;
	c.funcB();
	return 0;
}
