#include <stdio.h>
#include <string.h>

#define I2C_M_RD 0x0001
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0])) 

unsigned char buffer[10];

struct i2c_msg {
	int flags;
	unsigned char *buf;
};

static inline int pmic_i2c_write_xfer(struct i2c_msg msg)
{
	printf("%s %d\n", __func__, __LINE__);
	strcpy(buffer, msg.buf);
	printf("value written %s\n",buffer);
	return 0;
}

static inline int pmic_i2c_read_xfer(struct i2c_msg msg)
{
	printf("%s %d\n", __func__, __LINE__);
	msg.buf = &buffer[0];
	printf("value read %s\n",msg.buf);
	return 0;
}

static int (*xfer_fn[]) (struct i2c_msg)= {
	pmic_i2c_write_xfer,
	pmic_i2c_read_xfer
};

main()
{
	int index;
	struct i2c_msg msgs[2] = {{0x00, "Yegnesh"}, {0x01, 0x00}};
	unsigned char i, num;

	num = ARRAY_SIZE(msgs);
	for (i = 0; i < num ; i++ ) {
		index = msgs[i].flags & I2C_M_RD;
		(xfer_fn[index])(msgs[i]);
	}
}

