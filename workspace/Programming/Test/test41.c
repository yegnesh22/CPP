#include <stdio.h>

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof (x[0]))

int regs[] = {
	0x01,
	0x02,
#if (defined (CONFIG_PMIC_WHISKEYCOVE) || defined (CONFIG_PMIC_SHADYCOVE))
	0x03,
#endif
};

main()
{
	int i;
	int size = ARRAY_SIZE(regs);

	for (i = 0; i < size; i ++) {
		printf("regs[%d]=%d\n", i, regs[i]);
	}
}



