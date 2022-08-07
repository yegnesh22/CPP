#include <stdio.h>

struct base {
	unsigned char a:1;
	unsigned char b:7;
};


main()
{
	struct base b;
	b.a = 1;

	printf("%x %x\n", b.a,b.b);
}
