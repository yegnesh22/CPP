#include <stdio.h>

main()
{
	int value;

	printf("Enter the number:\n");
	scanf("%d", &value);

	if ((value != 1) && (value & (value - 1))) {
		printf("%d is not a power of 2\n",value);
	} else {
		printf("%d is a power of 2\n",value);
	}
}
