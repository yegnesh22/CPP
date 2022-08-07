#define DEBUG

#include <linux/slab.h>
#include <linux/platform_device.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/mutex.h>
#include <linux/interrupt.h>
#include <linux/completion.h>

struct dummy_i2c_bus_dev {
	struct i2c_adapter adapter;
	struct mutex i2c_rw_lock;
	struct device *dev;
};

static struct dummy_i2c_bus_dev *dummy_bus_dev;
static struct i2c_adapter* dummy_i2c_adapter;

static unsigned char dummy_i2c_dev_regs[128][256];

static inline int dummy_i2c_read_xfer(struct i2c_msg msg)
{
	unsigned short i;
	unsigned char dev_index = msg.addr;
	unsigned char reg_index = msg.buf[0];

	if ((dev_index >= 128) || (reg_index >= 256))
		return -EACCES;

	for(i = 0; i < msg.len; i++) {
		msg.buf[i] = dummy_i2c_dev_regs[dev_index][reg_index + i];
		dev_dbg(dummy_bus_dev->dev,
			"read dev[%x] reg [%x] val [%x],",
			dev_index, reg_index + i,
			dummy_i2c_dev_regs[dev_index][reg_index + i]);
	}

	return 0;
}

static inline int dummy_i2c_write_xfer(struct i2c_msg msg)
{
	unsigned short i;
	unsigned char dev_index = msg.addr;
	unsigned char reg_index = msg.buf[0];

	if ((dev_index >= 128) || (reg_index >= 256))
		return -EACCES;

	for(i = 1; i <= msg.len; i++) {
		dev_dbg(dummy_bus_dev->dev,
			"write dev[%x] reg [%x] val [%x],",
			dev_index, reg_index + i - 1,
			msg.buf[i]);
		dummy_i2c_dev_regs[dev_index][reg_index + i - 1] = msg.buf[i];
	}

	return 0;
}

static int (*xfer_fn[]) (struct i2c_msg) = {
	dummy_i2c_write_xfer,
	dummy_i2c_read_xfer,
};

static int dummy_i2c_bus_master_xfer(struct i2c_adapter *adap,
				struct i2c_msg msgs[],
				int num)
{
	int ret = 0;
	int i;
	u8 index;

	mutex_lock(&dummy_bus_dev->i2c_rw_lock);
	for (i = 0 ; i < num ; i++) {
		index = msgs[i].flags & I2C_M_RD;
		ret = (xfer_fn[index])(msgs[i]);

		if (ret == -EACCES)
			dev_info(dummy_bus_dev->dev, "Blocked Access!\n");

		/* If access is restricted, return true to
		*  avoid extra error handling in client
		*/

		if (ret != 0 && ret != -EACCES)
			goto transfer_err_exit;
	}

	ret = num;

transfer_err_exit:
	mutex_unlock(&dummy_bus_dev->i2c_rw_lock);
	return ret;
}

static u32 dummy_i2c_bus_master_func(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_BYTE_DATA;
}

static int dummy_i2c_bus_smbus_xfer(struct i2c_adapter *adap, u16 addr,
				unsigned short flags, char read_write,
				u8 command, int size,
				union i2c_smbus_data *data)
{
	struct i2c_msg msg;
	u8 buf[2];
	int ret;

	msg.addr = addr;
	msg.flags = flags & I2C_M_TEN;
	msg.buf = buf;
	msg.buf[0] = command;
	if (read_write == I2C_SMBUS_WRITE) {
		msg.len = 1;
		msg.buf[1] = data->byte;
	} else {
		msg.flags |= I2C_M_RD;
		msg.len = 1;
	}

	ret = dummy_i2c_bus_master_xfer(adap, &msg, 1);
	if (ret == 1) {
		if (read_write == I2C_SMBUS_READ)
			data->byte = msg.buf[0];
		return 0;
	}
	return ret;
}


static const struct i2c_algorithm dummy_i2c_bus_algo = {
	.master_xfer = dummy_i2c_bus_master_xfer,
	.functionality = dummy_i2c_bus_master_func,
	.smbus_xfer = dummy_i2c_bus_smbus_xfer,
};

static int dummy_i2c_bus_probe(struct platform_device *pdev)
{
	int ret;

	dummy_bus_dev = kzalloc(sizeof(struct dummy_i2c_bus_dev), GFP_KERNEL);
	if (!dummy_bus_dev)
		return -ENOMEM;

	dummy_bus_dev->dev = &pdev->dev;
	mutex_init(&dummy_bus_dev->i2c_rw_lock);
	dev_dbg(dummy_bus_dev->dev, "%s called\n", __func__);


	dummy_i2c_adapter = &dummy_bus_dev->adapter;
	dummy_i2c_adapter->owner = THIS_MODULE;
	dummy_i2c_adapter->class = I2C_CLASS_HWMON;
	dummy_i2c_adapter->algo = &dummy_i2c_bus_algo;
	dummy_i2c_adapter->nr = pdev->id;
	strcpy(dummy_i2c_adapter->name, "Dummy I2C Adapter");
	dummy_i2c_adapter->nr = pdev->id;
	ret = i2c_add_numbered_adapter(dummy_i2c_adapter);

	if (ret) {
		dev_err(&pdev->dev, "Error adding the adapter\n");
		goto err_adap_add;
	}

	return 0;

err_adap_add:
	kfree(dummy_bus_dev);
	return ret;
}

static int dummy_i2c_bus_remove(struct platform_device *pdev)
{
	kfree(dummy_bus_dev);
	return 0;
}

struct platform_driver dummy_i2c_bus_driver = {
	.probe = dummy_i2c_bus_probe,
	.remove = dummy_i2c_bus_remove,
	.driver = {
		.name = "dummy_i2c_bus",
		.owner = THIS_MODULE,
	},
};
module_platform_driver(dummy_i2c_bus_driver);

MODULE_AUTHOR("Yegnesh Iyer <yegnesh.s.iyer@intel.com");
MODULE_DESCRIPTION("Dummy I2C Master driver");
MODULE_LICENSE("GPL v2");

