#include <iostream>

using namespace std;

class CopyCon {
	public:
		int m;
	CopyCon(int v): m(v){}
	CopyCon(CopyCon& a) {
		cout << "I copied" << endl;
		m = a.m;
	}
	~CopyCon() {
		cout << "deleted" << endl;
	}
};

int main()
{
	CopyCon c1(5);
	cout << "c1 created" << endl;
	auto c2 = c1;
	cout << "c2 created" << endl;

	cout << c1.m << endl;
	cout << c2.m << endl;

	return 0;
}
