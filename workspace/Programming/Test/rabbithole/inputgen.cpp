#include "Solution.h"

//#define COMPLEX_TI

int main()
{
	ofstream tif("input.cpp");
	int i = 1;
	tif << "#include \"Solution.h\"" << endl;
	tif << "#include \"input.h\"" << endl;
	tif << "vector<ti> tests = {ti(500000, {" << flush;
	for (int i = 1; i < 500000; i++)
#ifdef COMPLEX_TI
		tif << i+1 << "," << flush;
	tif << "1}, 500000)};" << flush;
#else
		tif << "500000, " << flush;
	tif << "1}, 3)};" << flush;
#endif
	tif.close();

	return 0;
}
