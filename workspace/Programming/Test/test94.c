#include <stdio.h>

main()
{
	const int a = 10;
	int (* const ptr) = &a;

	printf("*ptr=%d\n", *ptr);
}
