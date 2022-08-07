#include <stdio.h>

main()
{
	int count = 0;
	int bsr_num = 0x28c;

	while (bsr_num >>= 1)
		count ++;

	printf("count=%x\n", count);
}
