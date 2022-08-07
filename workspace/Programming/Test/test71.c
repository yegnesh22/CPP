#include <stdio.h>

struct sensor {
	char sensor_name[10];
	int temp;
	int trip;
};

#define INT3403_DATA_INIT(name) \
	struct sensor sensor_@name = { \
		.sensor_name = name, \
		.temp = 0, \
		.trip = -1, \
	}

main()
{

	INT3403_DATA_INIT("STR0");
	INT3403_DATA_INIT("STR1");
	INT3403_DATA_INIT("STR2");
	
	printf("name:%s temp:%d trip:%d\n", sensor_STR0.sensor_name, sensor_STR0.temp, sensor_STR0.trip);
	printf("name:%s temp:%d trip:%d\n", sensor_STR1.sensor_name, sensor_STR1.temp, sensor_STR1.trip);
	printf("name:%s temp:%d trip:%d\n", sensor_STR2.sensor_name, sensor_STR2.temp, sensor_STR2.trip);
}
