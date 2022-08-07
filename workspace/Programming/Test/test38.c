#include <stdio.h>

#define disable_charging(psy, flag) \
	({ if (flag) \
		printf("flag=%d is true\n", flag); \
	else \
		printf("flag=%d is false\n", flag); })

main()
{
	int flag;
	int x;

	flag = 0;
	disable_charging(x, flag);
	flag = 1;
	disable_charging(x, flag);
	disable_charging(x, 1);
}
