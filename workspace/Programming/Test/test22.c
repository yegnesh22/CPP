#include <stdio.h>
#include <unistd.h>

#define MAX_ERR_NO 4095
#define unlikely(x) __builtin_expect(!!(x),0)
#define IS_ERR(x) unlikely((x)>=-MAX_ERR_NO)

main()
{
	int *ptr;

	ptr = NULL;
	if (IS_ERR(ptr))
		printf("NULL true!!\n");
	else
		printf("NULL false!!\n");
}
