#include <stdio.h>
#include <data.h>
#include <log.h>
#include <curve_fit.h>

#include "data.c"

#define LOG_TAG "app: "


main()
{
	int count = ARRAY_SIZE(data);
	double slope, intercept, r2;

	find_linear_fit(data, count, &slope, &intercept, &r2);
	LOGI("slope=%f intercept=%f r2=%f\n", slope, intercept, r2);
}
