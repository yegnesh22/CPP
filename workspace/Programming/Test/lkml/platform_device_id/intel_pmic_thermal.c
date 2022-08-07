#include <linux/module.h>
#include <linux/platform_device.h>

struct pmic_thermal_data {
	int num_trips;
};

static struct pmic_thermal_data bxtwc_thermal_data = {
	.num_trips = 3
};

static struct pmic_thermal_data chtwc_thermal_data = {
	.num_trips = 2
};

static int pmic_thermal_probe(struct platform_device *pdev)
{
	struct pmic_thermal_data *thermal_data;

	thermal_data = (struct pmic_thermal_data *)
		platform_get_device_id(pdev)->driver_data;
	if (thermal_data == NULL) {
		dev_err(&pdev->dev, "No thermal data initialized!!\n");
		return -ENODEV;
	}

	printk(KERN_ERR "[pmic_thermal_probe]: device %s with %d trips added!!\n",
		pdev->name, thermal_data->num_trips);

	return 0;
}

static int pmic_thermal_remove(struct platform_device *pdev)
{
	return 0;
}

static struct platform_device_id pmic_thermal_id_table[] = {
	{
		.name = "whiskey_cove_thermal",
		.driver_data = (kernel_ulong_t)&chtwc_thermal_data,
	},
	{
		.name = "bxt_wcove_thermal",
		.driver_data = (kernel_ulong_t)&bxtwc_thermal_data,
	},
	{},
};

static struct platform_driver pmic_thermal_driver = {
	.probe = pmic_thermal_probe,
	.remove = pmic_thermal_remove,
	.driver = {
		.name = "intel_pmic_thermal",
	},
	.id_table = pmic_thermal_id_table,
};

MODULE_DEVICE_TABLE(platform, pmic_thermal_id_table);
module_platform_driver(pmic_thermal_driver);
MODULE_AUTHOR("Yegnesh S Iyer <yegnesh.s.iyer@intel.com>");
MODULE_DESCRIPTION("PMIC thermal Driver");
MODULE_LICENSE("GPL");
