#include <stdio.h>

main()
{
	short sres = 0x7fff;
	int ires = sres;
	int vval = sres * 156;

	printf("ires=%d sres=%d\n",ires,sres);
	printf("vval=%d uA\n",vval);
}
