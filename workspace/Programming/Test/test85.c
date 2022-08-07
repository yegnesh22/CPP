#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))
//#define EXTERNAL_CHARGER_SUPPORT

#ifdef EXTERNAL_CHARGER_SUPPORT

#define EXTERNAL_CHARGER_COEXIST 1
#define EXTERNAL_CHARGER_ONLY 2

#if 0
#define EXTERNAL_CHARGER_CONFIG EXTERNAL_CHARGER_ONLY
#else
#define EXTERNAL_CHARGER_CONFIG EXTERNAL_CHARGER_COEXIST
#endif

#endif

struct cell_dev {
	char name[20];
	unsigned int id;
};

struct cell_dev intel_soc_pmic_cell_devs [] = {
#if ((!defined(EXTERNAL_CHARGER_SUPPORT)) || (EXTERNAL_CHARGER_CONFIG == EXTERNAL_CHARGER_COEXIST))
	{
		.name = "dollar_cove_charger",
		.id = 0,
	},
	{
		.name = "dollar_cove_battery",
		.id = 0,
	},
#endif
#ifdef EXTERNAL_CHARGER_SUPPORT
	{
		.name = "TBQ24296",
		.id = 0,
	},
#endif
#if ((defined(EXTERNAL_CHARGER_SUPPORT)) && (EXTERNAL_CHARGER_CONFIG == EXTERNAL_CHARGER_ONLY))
	{
		.name = "CW2015",
		.id = 0,
	},
#endif
};

main()
{
	int i;

#ifdef EXTERNAL_CHARGER_SUPPORT
	printf("EXTERNAL_CHARGER_CONFIG:%d\n", EXTERNAL_CHARGER_CONFIG);
#endif
	for (i = 0; i < ARRAY_SIZE(intel_soc_pmic_cell_devs); i++)
		printf("device %d: %s id:%d\n", i+1,
				intel_soc_pmic_cell_devs[i].name,
				intel_soc_pmic_cell_devs[i].id);
}
