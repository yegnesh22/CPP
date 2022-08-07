#include <linux/module.h>
#include <linux/platform_device.h>

static struct platform_device *pdev1;
static struct platform_device *pdev2;

static int thermal_device_add_init(void)
{
	pdev1 = platform_device_alloc("whiskey_cove_thermal", 0);
	if (pdev1) {
		platform_device_add(pdev1);
		printk(KERN_INFO "Device whiskey_cove_thermal added successfully!!\n");
	} else {
		printk(KERN_ERR "Error adding device whiskey_cove_thermal!!\n");
		return -1;
	}

	pdev2 = platform_device_alloc("bxt_wcove_thermal", 0);
	if (pdev2) {
		platform_device_add(pdev2);
		printk(KERN_INFO "Device bxt_wcove_thermal added successfully!!\n");
	} else {
		printk(KERN_ERR "Error adding device bxt_wcove_thermal!!\n");
		return -1;
	}

	return 0;
}

static void thermal_device_del_exit(void)
{
	printk(KERN_INFO "Removing device whiskey_cove_thermal\n");
	platform_device_del(pdev1);
	printk(KERN_INFO "Removing device bxt_wcove_thermal\n");
	platform_device_del(pdev2);
}

module_init(thermal_device_add_init);
module_exit(thermal_device_del_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yegnesh S Iyer <yegnesh.s.iyer@intel.com>");
MODULE_DESCRIPTION("PMIC thermal Device add");

