#include <stdio.h>
struct byte {
	char b1;
	char b2;
};

union alloc {
	struct byte b;
	short w;
};

main()
{
	union alloc u;
	u.w = 0x1122;
	char *c = (char*) &u.w;

	if (u.b.b1 == 0x22)
		printf("little endian\n");
	else 
		printf("big endian\n");

	printf("%p %p %p %x\n", &u.b.b1, &u.b.b2, c, *c);
}

