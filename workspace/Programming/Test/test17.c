#include <stdio.h>

main()
{
	unsigned char array[] = {0x43, 0x21};
	unsigned short pmic_intr = *((unsigned short*)&array[0]);
	unsigned char chgrirq0;
	unsigned char chgrirq1;

	chgrirq0 = (unsigned char)pmic_intr;
	chgrirq1 = (unsigned char)(pmic_intr >> 8);

	printf("%p irq0=0x%x\n",&array[0], chgrirq0);
	printf("%p irq1=0x%x\n",&array[1], chgrirq1);
}
