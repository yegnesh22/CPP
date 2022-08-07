#include <stdio.h>

main()
{
	int eax = 0x4050007;

	eax &= ~0x02;

	printf("%x\n", eax);
}
