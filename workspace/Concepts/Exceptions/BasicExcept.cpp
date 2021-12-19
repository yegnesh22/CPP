#include <iostream>
using namespace std;

void MightGoWrong()
{
	bool myError1 = false;
	bool myError2 = true;

	if (myError1) {
		throw "Something went wrong";
	}
	if (myError2) {
		throw string("Something else went wrong");
	}	
}

void UsesMightGoWrong() {
	MightGoWrong();
}

int main()
{
	try {
		UsesMightGoWrong();
	}
	catch(int e) {
		cout << "Error code: " << e << endl;
	}
	catch (char const* e) {
		cout << "Error code: " << e << endl;
	}
	catch (string &e) {
		cout << "Error code: " << e << endl;
	}
	cout << "Still running" << endl;
	return 0;
}
