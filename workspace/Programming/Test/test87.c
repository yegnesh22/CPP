#include <stdio.h>

struct mfd_cell {
	const char* name;
	int id;
	int num_resources;
	void *resources;
};

static struct mfd_cell dollar_cove_dev[] = {
	{
		.name = "dollar_cove_adc",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dollar_cove_gpio",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
#ifdef PMIC_DC_PWR_BTN_EN
	{
		.name = "dollar_cove_power_button",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
#endif
	{
		.name = "dollar_cove_pwrsrc",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dollar_cove_charger",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dollar_cove_battery",
		.id = 0,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dollar_cove_region",
	},
	{
		.name = "dcovex_regulator",
		.id = 1,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dcovex_regulator",
		.id = 2,
		.num_resources = 0,
		.resources = NULL,
	},
	{
		.name = "dcovex_regulator",
		.id = 3,
		.num_resources = 0,
		.resources = NULL,
	},
	{NULL, },
};


