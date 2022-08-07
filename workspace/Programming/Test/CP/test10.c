#include <stdio.h>

typedef union {
	int i;
	short s;
	char c;
} types;

main()
{
	printf("sizeof(types):%ld\n", sizeof(types));
	return 0;
}
