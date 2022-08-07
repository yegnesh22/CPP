#include <stdio.h>
#include <stdlib.h>

main()
{
	int bit_pos_high;
	int bit_pos_low;
	unsigned int value;

	printf("Enter the LSB from which the bits should be set:\n");
	scanf("%d", &bit_pos_low);
	printf("Enter the MSB till which the bits should be set:\n");
	scanf("%d", &bit_pos_high);

	if ((bit_pos_high > 31) || (bit_pos_low > 31) ||
		(bit_pos_high < bit_pos_low)) {
		printf("Invalid input\n");
		exit(0);
	}

	value = (((1 << (bit_pos_high + 1)) - 1) ^ 
			((1 << bit_pos_low) - 1));
	printf("value:%x\n",value);
}
