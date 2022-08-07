#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[1]))

struct intel_mid_sensor {
	char *name;
	int trips;
	int trips_rw;
	int direct;
	int trip_temp[2];
	int trip_hyst[2];
};

struct intel_mid_sensor sensor_list[] = {
	{
		.name = "SYSTHERM0",
		.trips = 2,
		.trips_rw = 3,
		.trip_temp = {0, 85000},
		.trip_hyst = {0, 0},
	},
	{
		.name = "SYSTHERM1",
		.trips = 2,
		.trips_rw = 3,
		.trip_temp = {0, 85000},
		.trip_hyst = {0, 0},
	},
	{
		.name = "PMICDIE",
		.trips = 1,
		.trips_rw = 1,
		.trip_temp = {0},
		.trip_hyst = {0},
		.direct = 0,
	},
};

main()
{
	int i, j;

	for(i = 0; i < ARRAY_SIZE(sensor_list); i++) {
		printf("name:%s\ntrips:%d\ntrips_rw:%d\n", sensor_list[i].name,
					sensor_list[i].trips,
					sensor_list[i].trips_rw);
		for(j = 0; j < sensor_list[i].trips; j++) {
			printf("trip_temp[%d]=%d\n", j, sensor_list[i].trip_temp[j]);
			printf("trip_hyst[%d]=%d\n", j, sensor_list[i].trip_hyst[j]);
		}
	}
}

