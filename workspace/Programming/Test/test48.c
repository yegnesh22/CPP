#include <stdio.h>
#include <stdlib.h>

union floater {
	struct {
		unsigned int mantissa:23;
		unsigned short exponent:8;
		unsigned char sign:1;
	} rep ;
	int hex;
	float val;
};

union word {
	short val;
	struct {
		char byte1;
		char byte2;
	} byte;
};

int main(int argc, char **argv)
{
	union floater c;
	unsigned char *ptr = (unsigned char *)&c;
	int i;
	union word w;

	w.val = 1;
	printf("w.byte1=%d w.byte2=%d\n", w.byte.byte1, w.byte.byte2);

	printf("%d\n", argc);
	c.val = atof(argv[1]);
	printf("c.val=%f, c.sign=%x c.exponent=%x c.mantissa=%x c.hex=%x\n",
		c.val, c.rep.sign, c.rep.exponent-127, c.rep.mantissa, c.hex);
	for (i = 0; i < sizeof(c); i++) {
		printf("%02x ", ptr[i]);
	}
	printf("\n");
}
