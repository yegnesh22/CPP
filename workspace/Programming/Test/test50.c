#include <stdio.h>
#include <malloc.h>

#define NUM_SENSORS 3


enum numTrips {
	LOW_TRIP,
	HIGH_TRIP,
	NUM_TRIPS,
};

struct trip_data {
	int temp;
	int hyst;
};

struct trip_data (*trip_points) [NUM_TRIPS];

main()
{
	int num_sensors = NUM_SENSORS;
	int i = 0;
	int j = 0;

	trip_points = malloc (num_sensors * sizeof(*trip_points));
	
	for (i = 0; i < num_sensors; i++) {
		for (j = 0; j < NUM_TRIPS; j++) {
			printf("[%d] trip_point_%d_temp: %d trip_point_%d_hyst:%d\n",
				i, j,
				trip_points[i][LOW_TRIP].temp, j,
				trip_points[i][LOW_TRIP].hyst);
		}
	}
}
