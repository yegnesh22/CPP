#include <stdio.h>

main()
{
	unsigned int value;
	int set_count = 0;

	printf("Enter a number in hex:\n");
	scanf("%x", &value);

	while(value) {
		value = value & (value - 1);
		set_count ++;
	}

	printf("Number of set bits = %d, number of unset bits = %d\n",
			set_count, (32-set_count));
}
