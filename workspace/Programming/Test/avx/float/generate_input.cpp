#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void genInput(string c) {
	string filename = c + ".cpp";
	cout << "generating " << filename << endl;
	ofstream f(filename);
	
	f << "float " << c << "[" << INPUT_SIZE << "] = {" << endl;

	for (int i = 0; i < INPUT_SIZE; i++)
		f << (float)(i % 256) << "," << endl;

	f << "};" << endl;
	f.close();

}

int main()
{
	genInput("a");
	genInput("b");
	return 0;
}
