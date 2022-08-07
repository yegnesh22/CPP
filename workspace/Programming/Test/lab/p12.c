#include <stdio.h>

#define MASK1 0xAAAAAAAA
#define MASK2 0x55555555

main()
{
	unsigned int num, num_new, res1, res2;
	
	printf("Program to swap the odd and even bits\n");
	printf("Enter a number in hex: \n");
	scanf("%x", &num);
	
	res1 = (num >> 1) & MASK2;
	res2 = (num << 1) & MASK1;
	
	num_new = res1 | res2;
	
	printf ("Entered number   : %x\n", num);
	printf ("After conversion : %x\n", num_new);
}