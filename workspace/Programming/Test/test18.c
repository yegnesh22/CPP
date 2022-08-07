#include <stdio.h>

#define I2C_FUNC_I2C 0x0001
#define I2C_SMBUS_FUNC 0x0002

int find_func(void)
{
	return I2C_FUNC_I2C | I2C_SMBUS_FUNC;
}

main()
{
	printf("retval = 0x%x\n", find_func());
}
