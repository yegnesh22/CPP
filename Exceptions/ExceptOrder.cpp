// bad_alloc is a sub-class of exception
// Hence while catching the exception, the subclass's catch block should be first
// Else the main class block would catch it as subclass's object can be used with
// a mainclass's pointer

#include <iostream>
#include <exception>

using namespace std;

void goesWrong()
{
	bool err1 = true;
	bool err2 = false;

	if (err1) {
		throw bad_alloc();
	}
	if (err2) {
		throw exception();
	}

	return; 
}


int main()
{
	try {
		goesWrong();
	} 
	catch (bad_alloc &e) {
		cout << "Bad Alloc: " << e.what() << endl;
	}
	catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
	}

}
