#include <stdio.h>

#define MASK1 0xF0
#define MASK2 0x0F

main()
{
	unsigned char value;
	unsigned char new_num;

	printf("Enter an 8-bit number in hex: ");
	scanf("%x", &value);

	new_num = ((value & MASK1) >> 4) | ((value & MASK2) << 4);

	printf("Entered num:%x after nibble swap:%x\n", value, new_num);
}

