#include <stdio.h>

#define THERM_CURVE_MAX_SAMPLES 18
#define THERM_CURVE_MAX_VALUES  4

#define true 1
#define false 0

#define ERANGE	20

static int const therm_curve_data[THERM_CURVE_MAX_SAMPLES]
[THERM_CURVE_MAX_VALUES] = {
	/* {temp_max, temp_min, adc_max, adc_min} */
	{-15, -20, 682, 536},
	{-10, -15, 536, 425},
	{-5, -10, 425, 338},
	{0, -5, 338, 272},
	{5, 0, 272, 220},
	{10, 5, 220, 179},
	{15, 10, 179, 146},
	{20, 15, 146, 120},
	{25, 20, 120, 100},
	{30, 25, 100, 83},
	{35, 30, 83, 69},
	{40, 35, 69, 58},
	{45, 40, 58, 49},
	{50, 45, 49, 41},
	{55, 50, 41, 35},
	{60, 55, 35, 30},
	{65, 60, 30, 25},
	{70, 65, 25, 22},
};
static int conv_adc_temp(int adc_val, int adc_max, int adc_diff, int temp_diff)
{
	int ret;

	ret = (adc_max - adc_val) * temp_diff;
	return ret / adc_diff;
}

static int conv_adc_millitemp(int adc_val, int adc_max, int adc_diff, int temp_diff)
{
	int ret;

	ret = (adc_max - adc_val) * temp_diff * 1000;
	return ret / adc_diff;
}

static unsigned char is_valid_temp_adc_range(int val, int min, int max)
{
	if (val > min && val <= max)
		return true;
	else
		return false;
}

static int dc_xpwr_get_batt_temp(int adc_val, int *temp, unsigned char milliDeg)
{
	int i;
	if (milliDeg) {
		for (i = 0; i < THERM_CURVE_MAX_SAMPLES; i++) {
			/* linear approximation for systherm temperature */
			if (is_valid_temp_adc_range(adc_val, therm_curve_data[i][3],
						therm_curve_data[i][2])) {

				*temp = conv_adc_millitemp(adc_val, therm_curve_data[i][2],
						therm_curve_data[i][2] -
						therm_curve_data[i][3],
						therm_curve_data[i][0] -
						therm_curve_data[i][1]);

				*temp += (therm_curve_data[i][1] * 1000);
				break;
			}
		}

	} else {
		for (i = 0; i < THERM_CURVE_MAX_SAMPLES; i++) {
			/* linear approximation for battery pack temperature */
			if (is_valid_temp_adc_range(adc_val, therm_curve_data[i][3],
						therm_curve_data[i][2])) {

				*temp = conv_adc_temp(adc_val, therm_curve_data[i][2],
						therm_curve_data[i][2] -
						therm_curve_data[i][3],
						therm_curve_data[i][0] -
						therm_curve_data[i][1]);

				*temp += (therm_curve_data[i][1]);
				break;
			}
		}
	}

	if (i >= THERM_CURVE_MAX_SAMPLES)
		return -ERANGE;

	return 0;

}


main()
{
	int temp;
	dc_xpwr_get_batt_temp(512, &temp, true);
	printf("temp:%d\n", temp);
	dc_xpwr_get_batt_temp(512/10, &temp, true);
	printf("temp:%d\n", temp);
}

