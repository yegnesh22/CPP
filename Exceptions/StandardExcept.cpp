#include <iostream>
using namespace std;

class CCanGoWrong {
	public:
		CCanGoWrong() {
			char *pMemory = new char[999999999999999999];
			delete [] pMemory;
		}
};

int main()
{
	try {
		CCanGoWrong wrong;
	} catch (bad_alloc &e) {
		cout << "Exceptions: " << e.what() << endl;
	}
	cout << "Still running" << endl;

	return 0;
}
