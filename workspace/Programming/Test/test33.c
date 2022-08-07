#include <stdio.h>

main()
{
	unsigned int mA = 500;
	int max_mA = -1;

	if (max_mA < (int)mA)
		printf("true!!\n");
	else
		printf("false!!\n");
}
