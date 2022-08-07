#include <stdio.h>
#include <string.h>

main()
{
	int a = 0x1234;
	short *c = &a;

	printf("%x\n",*(c));
	printf("%x\n",*(c+1));
	printf("%x\n",*(c+2));
	printf("%x\n",*(c+3));
}
