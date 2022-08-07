#include <stdio.h>

int fn(void)
{
	int val = 0;
	return ++val;
}

main()
{
	printf("%d\n", fn());
}

