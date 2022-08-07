#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

void fn1(void (*fn)(void))
{
	printf("executing %s address:%p\n", __func__, fn);
}

void fn2(void (*fn)(void))
{
	printf("executing %s address:%p\n", __func__, fn);
}

void fn3(void (*fn)(void))
{
	printf("executing %s address:%p\n", __func__, fn);
}

void (*fns[]) (void (*fn)(void)) = {
	fn1,
	fn2,
	fn3
};

main()
{
	int n = ARRAY_SIZE(fns);
	int i;

	for (i = 0; i < n; i++)
		fns[i](fns[i]);
}
