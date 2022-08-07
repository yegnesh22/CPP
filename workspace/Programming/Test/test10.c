#include <stdio.h>

main()
{
	unsigned char valueH = 0xFF;
	unsigned char valueL = 0x1D;
	int val1;

	val1 = (char)valueH;
	val1 <<= 4;
	val1 |= (valueL >> 4);
	
	printf("val1=%x\n",val1);
}
