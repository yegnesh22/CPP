#include <stdio.h>

#define array_size(x) (sizeof(x)/sizeof(x[0]))

int val [] = 
{
	0x091B, 
	0x3952, 
	0x094D, 
	0x2B69, 
	0x097F, 
	0x2135, 
	0x09B1, 
	0x19A7, 
	0x09E3, 
	0x13FE, 
	0x0A15, 
	0x0FB8, 
	0x0A47, 
	0x0C74, 
	0x0A79, 
	0x09EE, 
	0x0AAB, 
	0x07F9, 
	0x0ADD, 
	0x0674, 
	0x0B0F, 
	0x0540, 
	0x0B41, 
	0x044D, 
	0x0B73, 
	0x038A, 
	0x0BA5, 
	0x02EE, 
	0x0BD7, 
	0x0270, 
	0x0C09, 
	0x0209, 
	0x0C3B, 
	0x01B6, 
	0x0C6D, 
	0x0171, 
	0x0C9F, 
	0x0138, 
	0x0CD1, 
	0x0109, 
	0x0D03, 
	0xE2, 
	0x0D35, 
	0xC2, 
	0x0D67, 
	0xA7, 
	0x0D99, 
	0x90, 
	0x0DCB, 
	0x7D, 
	0x0DFD, 
	0x6D, 
	0x0E2F, 
	0x5F, 
	0x0E61, 
	0x53, 
	0x0E93, 
	0x49, 
	0x0EC5, 
	0x40, 
	0x0EF7, 
	0x39, 
	0x0F29, 
	0x32, 
	0x0F5B, 
	0x2D, 
	0x0F8D, 
	0x28
};


main()
{
	int i;

	for (i = 0; i < array_size(val); i += 2)
	{
		printf("temp:%d adc_val=%d\n", val[i], val[i+1]);
	}
}
