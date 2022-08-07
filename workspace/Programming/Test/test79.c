#include <stdio.h>
#include <string.h>

main()
{
	char *name = "INT3404:00";
	int ret;

	ret = strncmp(name, "PNP0C0B", strlen("PNP0C0B"));
	if (ret != 0)
		printf("Not same\n");
	else
		printf("Same\n");
}
