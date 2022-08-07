#include <stdio.h>

main()
{
	printf("(int):%d (long):%d\n", sizeof(int), sizeof(long));
	printf("(char):%d (short):%d\n", sizeof(char), sizeof(short));
	printf("(float):%d (double):%d\n", sizeof(float), sizeof(double));
}
