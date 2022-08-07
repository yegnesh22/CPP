#include <stdio.h>

main()
{
	unsigned int val = 0xA5A5A5A5;
	unsigned int bitPos = sizeof(val)*8 - 1;
	unsigned int mask = 1 << bitPos;
	while (mask) {
		printf("%1x", (val & mask) >> bitPos);
		mask >>= 1;
		bitPos --;
	}
	printf("\n");
}
