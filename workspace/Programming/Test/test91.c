#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

main()
{
	int a = 10, b = 20, c = 30, d = 40, e = 50;
	/* Array of pointers */
	int *ptr[6];
	int i;
	char alc[] = "Yegnesh";

	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;
	ptr[3] = &d;
	ptr[4] = &e;
	ptr[5] = alc; /* Warning seen as it is pointing to incomaptible type */

	printf("alc address=%p alc=%d\n", alc, alc);
	for (i = 0; i < ARRAY_SIZE(ptr); i++)
		printf("ptr[%d] = %p content of ptr[%d]:%d\n",
			i, ptr[i], i, *ptr[i]);
}
