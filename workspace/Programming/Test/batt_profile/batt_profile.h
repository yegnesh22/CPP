#ifndef __BATT_PROF_H__
#define __BATT_PROF_H__

#define MIN_BATT_PROF 4
#define LI_ION 2

#define BATT_STRING_MAX         8
#define BATTID_STR_LEN          8
#define BATT_PROF_MAX_TEMP_NR_RNG 6

typedef unsigned char u8;
typedef unsigned short u16;
        
/* Temperature Monitoring Table */
struct temp_mon_table {
	short int temp_up_lim;
	short int full_chrg_vol;
	short int full_chrg_cur;
	short int maint_chrg_vol_ll; 
	short int maint_chrg_vol_ul;
	short int maint_chrg_cur;
}; 

/* Charging Profile */
struct batt_charging_profile {
	char batt_id[BATTID_STR_LEN];
	u8 resvd;
	u8 battery_type;
	u16 capacity;
	u16 voltage_max;
	u16 chrg_term_mA;
	u16 low_batt_mV;
	u8 disch_tmp_ul;
	u8 disch_tmp_ll;
	u16 temp_mon_ranges;
	struct temp_mon_table temp_mon_range[BATT_PROF_MAX_TEMP_NR_RNG];
	short int temp_low_lim;
};

#endif
