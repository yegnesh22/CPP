#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string fname = "test.txt";
	ofstream outf;

	outf.open(fname);
	if (outf.is_open()) {
		outf << "Hello there" << endl;
		outf << 123 << endl;
		outf << "goodbye!!" << endl;
		outf.close();
	}
	else {
		cout << "Could not open file " << fname << endl;
	}

	ifstream inf;
	inf.open(fname);

	if (inf.is_open()) {
		string txt;
		while (!inf.eof()) {
			getline(inf, txt);
			cout << txt << endl;
		}
		inf.close();
	}
	else {
		cout << "Cannot open file " << fname << endl;
	}

	return 0;
}