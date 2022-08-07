#include <stdio.h>

#define MAX_CUR_VOLT_SAMPLES 3

enum psy_algo_stat {
        PSY_ALGO_STAT_UNKNOWN,
        PSY_ALGO_STAT_NOT_CHARGE,
        PSY_ALGO_STAT_CHARGE,
        PSY_ALGO_STAT_FULL,
        PSY_ALGO_STAT_MAINT,
};

struct batt_props {
        const char *name;
        long voltage_now;
        long voltage_now_cache[MAX_CUR_VOLT_SAMPLES];
        long current_now;
        long current_now_cache[MAX_CUR_VOLT_SAMPLES];
        int temperature;
        long status;
        unsigned long tstamp;
        enum psy_algo_stat algo_stat;
        int health;
        int throttle_state;
};       

#define time_after64(x, y) 1
#define PROP_TTL	10

#define IS_BAT_PROP_CHANGED(bat_prop, bat_cache)\
        ((bat_cache.voltage_now != bat_prop.voltage_now) || \
        (time_after64(bat_prop.tstamp, (bat_cache.tstamp + PROP_TTL)) &&\
        ((bat_cache.current_now != bat_prop.current_now) || \
        (bat_cache.voltage_now != bat_prop.voltage_now))) || \
        (bat_cache.temperature != bat_prop.temperature) || \
        (bat_cache.health != bat_prop.health) || \
        (bat_cache.throttle_state != bat_prop.throttle_state))


main()
{
	struct batt_props bat_prop_cache, bat_prop;
	if (!IS_BAT_PROP_CHANGED(bat_prop, bat_prop_cache))
		return -1;
}

