#include <stdio.h>

#define BATTID_STR_LEN		8
#define BATT_TEMP_NR_RNG	6
#define BATTID_UNKNOWN		"UNKNOWNB"
#define XPWR_FG_DATA_SIZE	36
#define XPWR_BAT_CURVE_SIZE	32
#define ACPI_FG_CONF_NAME_LEN	8

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef char s8;

/* PSE Modified Algo Structure */
/* Parameters defining the charging range */
struct ps_temp_chg_table {
	/* upper temperature limit for each zone */
	short int temp_up_lim;
	/* charge current and voltage */
	short int full_chrg_vol;
	short int full_chrg_cur;
	/* maintenance thresholds */
	/* maintenance lower threshold. Once battery hits full, charging
	*  charging will be resumed when battery voltage <= this voltage
	*/
	short int maint_chrg_vol_ll;
	/* Charge current and voltage in maintenance mode */
	short int maint_chrg_vol_ul;
	short int maint_chrg_cur;
};

struct dc_xpwr_fg_config_data {
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
} ;

struct em_config_oem0_data {
	char batt_id[BATTID_STR_LEN];
	 u8 turbo;
	 u8 batt_type;
	u16 capacity;
	u16 volt_max;
	u16 chrg_term_ma;
	u16 low_batt_thr;
	u8  safe_dischrg_ul;
	u8  safe_dischrg_ll;
	u16 temp_mon_ranges;
	struct ps_temp_chg_table temp_mon_range[BATT_TEMP_NR_RNG];
	/* Temperature lower limit */
	u16 temp_low_lim;
};


/********* OEM1 Table Structures ****************/
struct em_config_oem1_data {
	u8 fpo_0;
	u8 fpo_1;
	u8 dbiin_gpio;
	u8 dbiout_gpio;
	u8 batchptyp;
	u16 ia_apps_run_volt;
	u8 batid_dbibase;
	u8 batid_anlgbase;
	u8 ia_apps_cap;
	u16 vbatt_freq_lmt;
	u8 cap_freq_idx;
	u8 rsvd_1; /* reserved bit*/
	u8 batidx;
	u8 ia_apps_to_use;
	u8 turbo_chrg;
};

/* OEM0 and OEM1 values for testing */
static struct em_config_oem0_data cht_t3_mrd_oem0_data = {
	.batt_id = {'I', 'N', 'T', 'N', '0', '0', '0', '1'},
	.turbo = 0,
	.batt_type = 2,
	.capacity = 4300,
	.volt_max = 4200,
	.chrg_term_ma = 200,
	.low_batt_thr = 3500,
	.safe_dischrg_ul = 60,
	.safe_dischrg_ll = -20,
	.temp_mon_ranges = 3,
	.temp_mon_range[0].temp_up_lim = 45,
	.temp_mon_range[0].full_chrg_vol = 4200,
	.temp_mon_range[0].full_chrg_cur = 1800,
	.temp_mon_range[0].maint_chrg_vol_ll = 4150,
	.temp_mon_range[0].maint_chrg_vol_ul = 4200,
	.temp_mon_range[0].maint_chrg_cur = 1800,
	.temp_mon_range[1].temp_up_lim = 23,
	.temp_mon_range[1].full_chrg_vol = 4200,
	.temp_mon_range[1].full_chrg_cur = 1000,
	.temp_mon_range[1].maint_chrg_vol_ll = 4150,
	.temp_mon_range[1].maint_chrg_vol_ul = 4200,
	.temp_mon_range[1].maint_chrg_cur = 1000,
	.temp_mon_range[2].temp_up_lim = 10,
	.temp_mon_range[2].full_chrg_vol = 4200,
	.temp_mon_range[2].full_chrg_cur = 500,
	.temp_mon_range[2].maint_chrg_vol_ll = 4150,
	.temp_mon_range[2].maint_chrg_vol_ul = 4200,
	.temp_mon_range[2].maint_chrg_cur = 500,
	.temp_low_lim = 0,
};

static struct em_config_oem1_data cht_t3_mrd_oem1_data = {
	.fpo_0 = 0x1C,
	.fpo_1 = 0x40,
	.dbiin_gpio = 0,
	.dbiout_gpio = 0,
	.batchptyp = 1,
	.ia_apps_run_volt = 3300,
	.batid_dbibase = 240,
	.batid_anlgbase = 19,
	.ia_apps_cap = 0,
	.vbatt_freq_lmt = 3700,
	.cap_freq_idx = 4,
	.rsvd_1 = 0,
	.batidx = 0,
	.ia_apps_to_use = 1,
	.turbo_chrg = 0,
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
	.rdc0 = 0x77,
	.bat_curve = {
		0, 0, 0, 0, 0, 1, 2, 3,
		4, 6, 10, 16, 25, 39, 48, 52,
		56, 59, 62, 68, 73, 78, 82, 86,
		91, 95, 98, 100, 100, 100, 100, 100,
	}
};

main()
{
	printf("bcfg fg_name:%s\n", cht_t3_mrd_bcfg_data.fg_name);
	printf("bcfg battid:%s\n", cht_t3_mrd_bcfg_data.battid);
	printf("oem0 batt_id:%s\n", cht_t3_mrd_oem0_data.batt_id);
}
