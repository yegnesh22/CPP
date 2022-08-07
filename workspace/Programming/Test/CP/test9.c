#include <stdio.h>

typedef union {
	unsigned char b;
	struct {
		unsigned char b0:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
	} bits;
} byte;

main()
{
	byte b;

	b.b = 0x16;
	printf("sizeof(byte):%d\n", sizeof(b));
	printf("b.b:%x\n", b.b);
	printf("b.b0:%x\n", b.bits.b0);
	printf("b.b1:%x\n", b.bits.b1);
	printf("b.b2:%x\n", b.bits.b2);
	printf("b.b3:%x\n", b.bits.b3);
	printf("b.b4:%x\n", b.bits.b4);
	printf("b.b5:%x\n", b.bits.b5);
	printf("b.b6:%x\n", b.bits.b6);
	printf("b.b7:%x\n", b.bits.b7);

	return 0;
}
