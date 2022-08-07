#ifndef __CURVE_FIT_H__

#define __CURVE_FIT_H__

extern int find_linear_fit(struct co_ordinate_pairs *data, int num_samples,
			double *m, double *c, double *r2);

#endif
