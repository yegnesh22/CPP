#include <stdio.h>

main()
{
	int poll = 1200000;

	printf("%d bits %x %d\n", sizeof(poll)*8, poll, poll);
}
