#include <stdio.h>

#define CHGRIRQ0_ADDR_BC 0x011E
#define CHGRIRQ0_ADDR_SC 0x001E
#define CHGRIRQ0_ADDR_WC 0x5E1E

#define CHGRIRQ0_ADDR(x) ((x > 0) ? ( (x == 1) ? CHGRIRQ0_ADDR_SC : CHGRIRQ0_ADDR_WC ) : CHGRIRQ0_ADDR_BC)


main()
{
	int pmic;

	pmic = 0;
	printf("%x\n", CHGRIRQ0_ADDR(pmic));
	pmic = 1;
	printf("%x\n", CHGRIRQ0_ADDR(pmic));
	pmic = 2;
	printf("%x\n", CHGRIRQ0_ADDR(pmic));
}
