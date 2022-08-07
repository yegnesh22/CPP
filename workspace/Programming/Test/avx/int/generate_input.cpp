#include <bits/stdc++.h>
#include "input.h"

using namespace std;

void genInput(string c) {
	string filename = c + ".cpp";
	cout << "generating " << filename << endl;
	ofstream f(filename);

	//f << "#pragma pack(4)" << endl;	
	f << "unsigned int " << c << "[" << INPUT_SIZE << "] = {" << endl;

	for (int i = 0; i < INPUT_SIZE; i++)
		f << (int)(i % 256) << "," << endl;

	f << "};" << endl;
	f.close();

}

int main()
{
	genInput("a");
	genInput("b");
	return 0;
}
