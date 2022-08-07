#include <stdio.h>
#include <string.h>
#include "batt_profile.h"

#define DEBUG

#ifdef DEBUG
#define DBG printf
#else
#define DBG 
#endif

#define EINVAL 11

#define true 1
#define false 0

#define min_t(type, x,y) (type)(((type)x < (type)y) ? x : y)
#define BATT_TEMP_NR_RNG 6

struct batt_charging_profile bprof = {
	.batt_id = "INTN001",
	.battery_type = 2,
	.capacity = 1500,
	.voltage_max = 4200,
	.chrg_term_mA = 50,
	.low_batt_mV = 3400,
	.disch_tmp_ul = 60,
	.disch_tmp_ll = 0,
	.temp_mon_ranges = 6,
	.temp_mon_range = {
				{ 70, 3950, 350, 3900, 3950, 350 },
				{ 60, 4100, 950, 4000, 4050, 950 },
				{ 45, 4200, 950, 4100, 4150, 950 },
				{ 10, 4100, 950, 4000, 4050, 950 },
				{ 0, 3950, 350, 3900, 3950, 350 },
				{ -10, 3900, 350, 3850, 3900, 350 },
			},
	.temp_low_lim = -20,
};

struct batt_charging_profile new_prof;

void print_batt_prof(void)
{
	int i;

	printf("batt_id = %s\n", new_prof.batt_id);
	printf("batt_type = %d\n", new_prof.battery_type);
	printf("capacity = %d\n", new_prof.capacity);
	printf("voltage_max = %d\n", new_prof.voltage_max);
	printf("chrg_term_mA = %d\n", new_prof.chrg_term_mA);
	printf("low_batt_mV = %d\n", new_prof.low_batt_mV);
	printf("disch_tmp_ul = %d\n", new_prof.disch_tmp_ul);
	printf("disch_tmp_ll = %d\n", new_prof.disch_tmp_ll);
	printf("temp_mon_ranges = %d\n", new_prof.temp_mon_ranges);

	for (i = 0; i < new_prof.temp_mon_ranges; i++) {
		printf("[%d].temp_up_lim = %d\n", 
			i, new_prof.temp_mon_range[i].temp_up_lim);
		printf("[%d].full_chrg_vol = %d\n", 
			i, new_prof.temp_mon_range[i].full_chrg_vol);
		printf("[%d].full_chrg_cur = %d\n", 
			i, new_prof.temp_mon_range[i].full_chrg_cur);
		printf("[%d].maint_chrg_vol_ul = %d\n", 
			i, new_prof.temp_mon_range[i].maint_chrg_vol_ul);
		printf("[%d].maint_chrg_vol_ll = %d\n", 
			i, new_prof.temp_mon_range[i].maint_chrg_vol_ll);
		printf("[%d].maint_chrg_cur = %d\n", 
			i, new_prof.temp_mon_range[i].maint_chrg_cur);
	}
	printf("temp_low_lim=%d\n",new_prof.temp_low_lim);

	return;
}

int find_tempzone_index(short int *interval, 
			int *num_zones, 
			short int *temp_up_lim)
{
	int up_lim_index=0, low_lim_index=-1;
	int diff = 0;
	int i;
	short int temp_interval;
	
	*num_zones = MIN_BATT_PROF - bprof.temp_mon_ranges + 1;
	if ((*num_zones) <= 0) {
		return 0;
	}

	for(i = 0 ; i < bprof.temp_mon_ranges ; i++) {
		if (bprof.temp_mon_range[i].temp_up_lim == 45) {
			up_lim_index = i;
		}
	}

	printf("up_lim_index=%d\n", up_lim_index);
	low_lim_index = up_lim_index + 1;

	if (low_lim_index == bprof.temp_mon_ranges)
		diff = bprof.temp_low_lim -
			bprof.temp_mon_range[up_lim_index].temp_up_lim;
	else 
		diff = bprof.temp_mon_range[low_lim_index].temp_up_lim - 
			bprof.temp_mon_range[up_lim_index].temp_up_lim;

	*interval = diff / (*num_zones);
	*temp_up_lim = bprof.temp_mon_range[up_lim_index].temp_up_lim;
	printf("up_lim_index=%d\n", up_lim_index);

	return up_lim_index;
}

#define NEED_ZONE_SPLIT(bprof)\
	((bprof.temp_mon_ranges < MIN_BATT_PROF))

void set_pmic_batt_prof(void)
{
	int split_index;
	int i,j;
	short int temp_up_lim;
	short int interval;
	int num_zones;

	if (!NEED_ZONE_SPLIT(bprof)) {
		memcpy(&new_prof, &bprof, 
			sizeof(struct batt_charging_profile));
		return;
	}

	strcpy(&new_prof.batt_id[0], &bprof.batt_id[0]);
	new_prof.battery_type = bprof.battery_type;
	new_prof.capacity = bprof.capacity; 
	new_prof.voltage_max =  bprof.voltage_max;
	new_prof.chrg_term_mA = bprof.chrg_term_mA;
	new_prof.low_batt_mV =  bprof.low_batt_mV;
	new_prof.disch_tmp_ul = bprof.disch_tmp_ul;
	new_prof.disch_tmp_ll = bprof.disch_tmp_ll;

	split_index = find_tempzone_index(&interval, &num_zones, &temp_up_lim);
	for(i = 0 ; i < bprof.temp_mon_ranges; i++ ) {
		if ((i == split_index) && (num_zones > 0)) {
			for(j=0; j < num_zones; j++, temp_up_lim += interval) {
				memcpy(&new_prof.temp_mon_range[i+j],
					&bprof.temp_mon_range[i],
					sizeof(bprof.temp_mon_range[i]));
				new_prof.temp_mon_range[i+j].temp_up_lim = 
					temp_up_lim;
			}
			j --;
		} else {
			memcpy(&new_prof.temp_mon_range[i+j],
				&bprof.temp_mon_range[i],
				sizeof(bprof.temp_mon_range[i]));
		}
	}

	new_prof.temp_mon_ranges = i+j;
	new_prof.temp_low_lim = bprof.temp_low_lim;

	return;
}


#if 0
static int get_tempzone(struct batt_charging_profile *pse_mod_bprof,
		int temp)
{

	int i = 0;
	int temp_range_cnt = min_t(unsigned short, pse_mod_bprof->temp_mon_ranges,
			BATT_TEMP_NR_RNG);
	int check_index;
	int index_offset;
	unsigned char sort_ascend;

	if (pse_mod_bprof->temp_mon_range[0].temp_up_lim < pse_mod_bprof->temp_mon_range[1].temp_up_lim) {
		sort_ascend = true;
		check_index = temp_range_cnt - 1;
		index_offset = 0;
	} else {
		sort_ascend = false;
		check_index = 0;
		index_offset = -1;
	}

	printf("Check_index=%d\n", check_index);

	if (temp < pse_mod_bprof->temp_low_lim
			|| temp >
			pse_mod_bprof->temp_mon_range[check_index].temp_up_lim)
		return -1;

	for (i = 0; i < temp_range_cnt; ++i)
		if (sort_ascend) {
			if (temp <= pse_mod_bprof->temp_mon_range[i].temp_up_lim)
				break;
		} else {
			if (temp > pse_mod_bprof->temp_mon_range[i].temp_up_lim)
				break;
		}
	return i + index_offset;
	int index;
	index = -1; 
	for (i=0;i<(temp_range_cnt-1);++i) {
		printf("i=%d t1=%d t=%d\n",i,
			pse_mod_bprof->temp_mon_range[i+1].temp_up_lim,
			pse_mod_bprof->temp_mon_range[i].temp_up_lim);
		if ((temp <= pse_mod_bprof->temp_mon_range[i].temp_up_lim && 
			temp >= pse_mod_bprof->temp_mon_range[i+1].temp_up_lim) ||
			(temp >= pse_mod_bprof->temp_mon_range[i].temp_up_lim  && 
			 temp <= pse_mod_bprof->temp_mon_range[i+1].temp_up_lim))
		{
			index = i;
			break;
		}
	}
	return index;
}
#endif

static int get_tempzone(struct batt_charging_profile *pse_mod_bprof,
                        int temp)
{

	int i = 0;
	int temp_range_cnt = min_t(u16, pse_mod_bprof->temp_mon_ranges,
			BATT_TEMP_NR_RNG);

	if (temp < pse_mod_bprof->temp_low_lim
			|| temp >
			pse_mod_bprof->temp_mon_range[0].temp_up_lim)
		return -EINVAL;

	for (i = 0; i < temp_range_cnt; ++i)
		if (temp > pse_mod_bprof->temp_mon_range[i].temp_up_lim)
			break;
	return i-1;
}



main()
{
	int temp;

	set_pmic_batt_prof();
	print_batt_prof();

	printf("Enter the temp:\n");
	scanf("%d", &temp);

	printf("Zone is %d\n", get_tempzone(&bprof, temp));
}
