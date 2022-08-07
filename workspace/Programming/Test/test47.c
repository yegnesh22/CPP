#include <stdio.h>
#include <stdlib.h>

main()
{
	int *c;
	int *d;

	c = (int *) malloc(sizeof(c));
	d = (int *) calloc(1, sizeof(d));

	printf("c=%d d=%d\n", *c, *d);
}
