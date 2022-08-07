#include <stdio.h>
#define ARRAY_SIZE(x)	((sizeof(x) / sizeof(x[0])))
int resi_val[] = {
	68237,
	53650,
	42506,
	33892,
	27219,
	22021,
	17926,
	14674,
	12081,
	10000,
	8315,
	6948,
	5834,
	4917,
	4161,
	3535,
	3014,
	2586,
	2228,
	1925,
	1669,
	1452,
	1268,
	1110,
	974,
	858,
	758,
	672,
	596,
	531,
};


main()
{
	int temp = -200 + 2731;
	int len = ARRAY_SIZE(resi_val);
	int i;

	printf("Name \(LPAT\, Package\(0x3C\)\n\{\n");
	for (i = 0; i < len ; i++) {
		printf("0x%04x,\n0x%08x,\n", temp, resi_val[i]);
		temp += 50;
	}
	printf("\}\n");
}
