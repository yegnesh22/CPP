#include <stdio.h>

main()
{
	unsigned int value = 0x1;
	unsigned char *p;
	
	p = (unsigned char*)&value;
	
	if (*p)
		printf("Little endian system\n");
	else
		printf("Big endian system\n");
}