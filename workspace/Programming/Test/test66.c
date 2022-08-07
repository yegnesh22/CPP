#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x) / sizeof(x[0])))

main()
{
	int a[] = { 0, 10, 20, 30 };
	int *p;
	int i;
	int nc = ARRAY_SIZE(a);

	p = a;
	printf("%d\n", nc);

	for(i = 0; i < nc; i++) {
		printf("p[%d]=%d\n", i, p[i]);
	}
}

