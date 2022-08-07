#include <stdio.h>

struct temp_limits {
	int low;
	int high;
	int crit;
};

struct temp_limits psv1_temp_limit = {
	.low = 90,
	.high = 105,
	.crit = 110,
};

struct temp_limits psv2_temp_limit = {
	.low = 85,
	.high = 100,
	.crit = 110,
};

main()
{
	int current_temp, current_state;
	int previous_limit, next_limit;
	int previous_temp, next_temp;

	for (current_temp = psv1_temp_limit.low; current_temp < psv1_temp_limit.crit; current_temp++) {
		if (current_temp == psv1_temp_limit.high) {
			previous_limit = 6000;
			next_limit = 3000;
		} else {
			previous_limit = 13000;
			next_limit = 6000;
		}
		current_state = previous_limit - (((current_temp - previous_temp) / (next_temp - previous_temp)) * (previous_limit - next_limit));
		printf("Passive 1:- Current Temp:%d State:%d\n", current_temp, current_state);
	}

	for (current_temp = psv2_temp_limit.low; current_temp < psv2_temp_limit.crit; current_temp++) {
		if (current_temp == psv2_temp_limit.high) {
			previous_limit = 6000;
			next_limit = 3000;
		} else {
			previous_limit = 13000;
			next_limit = 6000;
		}
		current_state = previous_limit - (((current_temp - previous_temp) / (next_temp - previous_temp)) * (previous_limit - next_limit));
		printf("Passive 2:- Current Temp:%d State:%d\n", current_temp, current_state);
	}
}
