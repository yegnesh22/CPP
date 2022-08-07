#include <stdio.h>

#define MASK 0xFFFFFFFF

main()
{
	unsigned int value;
	unsigned int new_val;

	printf("Enter a 32-bit number in hex: ");
	scanf("%x", &value);

	new_val = value ^ MASK;

	printf("Entered value:%08x after toggling:%08x\n", value, new_val);
}
