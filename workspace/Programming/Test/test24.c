#include <stdio.h>

#define ARR_SIZ(x) (sizeof(x)/sizeof(x[0]))
#define min 3500
#define max 4440

#define clamp_t(type, val, min, max) ({ \
	type __val = (val); \
	type __min = (min); \
	type __max = (max); \
	__val = __val < min ? min : __val; \
	__val = __val > max ? max : __val; })
#define DIVISOR 20
#define BIT_POS 2

int lookup_val(int cv)
{
	int val;
	cv = clamp_t(int, cv, min, max);
	val = 
		(((cv - min) / DIVISOR) 
			<< BIT_POS);
	return val;
}

main()
{

	int i;
	int val;
	int cv_arr[] = { 3300, 3500, 4000, 4050, 4100, 4150, 4180, 4200, 4250, 4300, 4320, 4350, 4400, 4440, 4450};

	for (i = 0; i < ARR_SIZ(cv_arr); i++) {
		val = lookup_val(cv_arr[i]);
		printf("vol=%d, reg_val=%x %b\n", cv_arr[i], val, val);
	}
}
