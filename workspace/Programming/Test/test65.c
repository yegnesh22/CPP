#include <stdio.h>


main()
{
	int result;
	int result1;
	int adc_val = 0x2e8;

	result = adc_val;
	result1 = adc_val;

	result = result * 80 / 80;
	printf("result: %x\n", result);
	result1 = result1 * 80 / 60;
	printf("result1: %x\n", result1);
}
