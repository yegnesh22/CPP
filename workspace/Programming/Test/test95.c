#include <stdio.h>

union byte {
	unsigned char byte;
	struct {
		char b0:1;
		char b1:1;
		char b2:1;
		char b3:1;
		char b4:1;
		char b5:1;
		char b6:1;
		char b7:1;
	} sbits;
	struct {
		unsigned char b0:1;
		unsigned char b1:1;
		unsigned char b2:1;
		unsigned char b3:1;
		unsigned char b4:1;
		unsigned char b5:1;
		unsigned char b6:1;
		unsigned char b7:1;
	} ubits;
};

main()
{
	union byte b;
	b.byte = 0x55;

	printf("sbit 0 = %x\n", b.sbits.b0);
	printf("sbit 1 = %x\n", b.sbits.b1);
	printf("sbit 2 = %x\n", b.sbits.b2);
	printf("sbit 3 = %x\n", b.sbits.b3);
	printf("sbit 4 = %x\n", b.sbits.b4);
	printf("sbit 5 = %x\n", b.sbits.b5);
	printf("sbit 6 = %x\n", b.sbits.b6);
	printf("sbit 7 = %x\n", b.sbits.b7);
	printf("ubit 0 = %x\n", b.ubits.b0);
	printf("ubit 1 = %x\n", b.ubits.b1);
	printf("ubit 2 = %x\n", b.ubits.b2);
	printf("ubit 3 = %x\n", b.ubits.b3);
	printf("ubit 4 = %x\n", b.ubits.b4);
	printf("ubit 5 = %x\n", b.ubits.b5);
	printf("ubit 6 = %x\n", b.ubits.b6);
	printf("ubit 7 = %x\n", b.ubits.b7);
}
