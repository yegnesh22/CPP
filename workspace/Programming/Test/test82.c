#include <stdio.h>
#include <stddef.h>

#define XPWR_FG_DATA_SIZE       36
#define XPWR_BAT_CURVE_SIZE     32 
#define ACPI_FG_CONF_NAME_LEN   8 
#define BATTID_STR_LEN   8 

typedef unsigned char u8;
typedef unsigned short u16;

struct __attribute__((__packed__))dc_xpwr_fg_config_data {
	char fg_name[ACPI_FG_CONF_NAME_LEN];
	char battid[BATTID_STR_LEN];
	u16 size; /* config size */
	u8 fco; /* FG config options */
	u16 checksum; /* Primary data checksum */
	u8 cap1;
	u8 cap0;
	u8 rdc1;
	u8 rdc0;
	u8 bat_curve[XPWR_BAT_CURVE_SIZE]; 
}; 


/* Test data for cht-t3-mrd battery with 3.5V as the low batt threshold
   and with 4300 mAh as the battery capacity */
static struct dc_xpwr_fg_config_data cht_t3_mrd_bcfg_data = {
	.fg_name = {'X', 'P', 'O', 'W', 'E', 'R', '-', '0' },
	.battid = {'I', 'N', 'T', 'N', '0', '0', '0', '1'},
	.size = 0x24,
	.fco = 1,
	.checksum = 0xF7D0,
	.cap1 = 0x8B,
	.cap0 = 0x89,
	.rdc1 = 0xC0,
	.rdc0 = 0x67,
	.bat_curve = {
		0, 0, 0, 0, 0, 1, 2, 3,
		4, 6, 10, 16, 25, 39, 48, 52,
		56, 59, 62, 68, 73, 78, 82, 86,
		91, 95, 98, 100, 100, 100, 100, 100,
	}
};


main()
{
	int i;
	unsigned char *p = (unsigned char*)&cht_t3_mrd_bcfg_data;

	for(i = 0; i < sizeof(cht_t3_mrd_bcfg_data); i++) {
		printf("[%d] = %x\n", i, p[i], p[i]);
	}
}
