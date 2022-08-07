#include <stdio.h>

main()
{
	const int v1 = 10;
	const int v2 = 20;
	const int* p; // pointer to a const int
	const int* const p1 = &v1; // const pointer
	p = &v1;
	//(*p)++; // error - updating a read only location &v1.
	printf("%d\n", *p);
	p = &v2; // valid operation since the pointer is not constant
	//(*p)++;// error - updating a read only location &v1.
	printf("%d\n", *p);

	return 0;
}
