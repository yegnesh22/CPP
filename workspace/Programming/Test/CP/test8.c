#include <stdio.h>

main()
{
	printf("(char): %d\n", sizeof(char));
	printf("(short): %d\n", sizeof(short));
	printf("(int): %d\n", sizeof(int));
	printf("(long): %d\n", sizeof(long));
	printf("(long long): %d\n", sizeof(long long));
	printf("(float): %d\n", sizeof(float));
	printf("(double): %d\n", sizeof(double));
	printf("(void*): %d\n", sizeof(void*));
	return 0;
}
