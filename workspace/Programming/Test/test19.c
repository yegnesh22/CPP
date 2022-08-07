#include <stdio.h>
#include <stdbool.h>

#define ENABLE_CE (1 << 1)
#define ENABLE_CE_MASK (1 << 1)

typedef unsigned char u8;

u8 val = 0x00;

void charge_enable(bool enable)
{
	u8 data;
	u8 mask;

	data = enable ? 0 : ENABLE_CE;
	mask = ENABLE_CE_MASK;

	val = (val & ~mask) | data;
	printf("val=%x data=%x, mask=%x\n", val, data, mask);
}

main()
{
	charge_enable(true);
	charge_enable(false);
}
