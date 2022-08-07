#include <stdio.h>
#include <data.h>
#include <log.h>

#define ARRAY_SIZE(x)	((sizeof(x)/sizeof(x[0])))

#define LOG_TAG "Curve fit: "

int find_linear_fit(struct co_ordinate_pairs *data, int num_samples,
			double *m, double *c, double *r2)
{
	int i;
	double sigma_x2, sigma_xy, sigma_x, sigma_y;
	double  fi, ss_tot, ss_res;
	double y_bar;

	sigma_x2 = sigma_xy = sigma_x = sigma_y = 0;
	ss_tot = ss_res = 0;

	for (i = 0; i < num_samples; i++) {
		LOGD("x[%d]=%f y[%d]=%f\n", i, data[i].x, i, data[i].y);
		sigma_x += data[i].x;
		sigma_y += data[i].y;
		sigma_xy += data[i].x * data[i].y;
		sigma_x2 += data[i].x * data[i].x;
	}

	y_bar = sigma_y / num_samples;

	LOGD("sigma_x = %f sigma_y = %f sigma_xy = %f sigma_x2=%f, count = %d\n",
		sigma_x, sigma_y, sigma_xy, sigma_x2, num_samples);

	*m = (((sigma_x * sigma_y) - (num_samples * sigma_xy)) /
		((sigma_x * sigma_x) - (sigma_x2 *  num_samples)));

	*c = (((sigma_x2 * sigma_y) - (sigma_xy * sigma_x)) /
		((sigma_x2 * num_samples) - (sigma_x * sigma_x)));

	LOGD("m = %f, c = %f\n", *m ,*c);

	for (i = 0; i < num_samples; i++) {
		fi = *m * data[i].x + *c;
		ss_tot += ((data[i].y - y_bar) * (data[i].y - y_bar));
		ss_res += ((data[i].y - fi) * (data[i].y - fi));
	}
	*r2 = 1 - (ss_res/ss_tot);
	LOGD("r2 = %f\n", *r2);

}
