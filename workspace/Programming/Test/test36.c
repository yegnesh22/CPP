#include <stdio.h>

union {
	unsigned char byte;
	struct {
		unsigned char rev:3;
		unsigned char i2c_add_slct:2;
		unsigned char vendor:3;
	} fields;
} revision;

main()
{
	revision.byte = 0x46;

	printf("byte=%x\n", revision.byte);
	printf("vendor=%x\n", revision.fields.vendor);
	printf("i2c_add_slct=%x\n", revision.fields.i2c_add_slct);
	printf("rev=%x\n", revision.fields.rev);
}
