#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

#define THRM0IRQ	0x04
#define THRM3IRQ	0xD9
#define MTHRMIRQ0	0x0D
#define MTHRMIRQ3	0xDA
#define STHRMIRQ0	0x4F19
#define STHRMIRQ3	0x4F1B

typedef unsigned short u16;
typedef unsigned char u8;

struct trip_config_map {
	u16 irq_reg;
	u16 irq_en;
	u16 evt_stat;
	u8 irq_mask;
	u8 irq_en_mask;
	u8 evt_mask;
	u8 trip_num;
};

struct thermal_irq_map {
	char handle[20];
	int num_trips;
	struct trip_config_map *trip_config;
};

static struct trip_config_map str0_trip_config [] = {
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x01,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x01,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x01,
		.trip_num = 0
	},
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x10,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x10,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x10,
		.trip_num = 1
	}
};

static struct trip_config_map str1_trip_config [] = {
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x02,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x02,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x02,
		.trip_num = 0
	},
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x20,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x20,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x20,
		.trip_num = 1
	},
};

static struct trip_config_map str2_trip_config[] = {
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x04,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x04,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x04,
		.trip_num = 0
	},
	{
		.irq_reg = THRM0IRQ,
		.irq_mask = 0x40,
		.irq_en = MTHRMIRQ0,
		.irq_en_mask = 0x40,
		.evt_stat = STHRMIRQ0,
		.evt_mask = 0x40,
		.trip_num = 1
	},
	{
		.irq_reg = THRM3IRQ,
		.irq_mask = 0x40,
		.irq_en = MTHRMIRQ3,
		.irq_en_mask = 0x40,
		.evt_stat = STHRMIRQ3,
		.evt_mask = 0x40,
		.trip_num = 1
	},
};

static struct thermal_irq_map wc_thermal_irq_map[] = {
	{
		.handle = "STR0",
		.trip_config = 	str0_trip_config,
		.num_trips = ARRAY_SIZE(str0_trip_config),
	},
	{
		.handle = "STR1",
		.trip_config = str1_trip_config,
		.num_trips = ARRAY_SIZE(str1_trip_config),
	},
	{
		.handle = "STR2",
		.trip_config = str2_trip_config,
		.num_trips = ARRAY_SIZE(str2_trip_config),
	},
};


main()
{
	int i;

	printf("array size:%d\n", ARRAY_SIZE(wc_thermal_irq_map));
	for (i = 0; i < ARRAY_SIZE(wc_thermal_irq_map); i++) {
		printf("%s num trips = %d\n", wc_thermal_irq_map[i].handle, wc_thermal_irq_map[i].num_trips);
	}
}
