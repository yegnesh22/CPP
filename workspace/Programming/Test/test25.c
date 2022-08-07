#include <stdio.h>

void printfn(const char* fn, int ln)
{
	printf("%s %d\n", fn, ln);
}

main()
{
	printfn(__func__, __LINE__);
}
