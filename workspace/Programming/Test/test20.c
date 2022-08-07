#include <stdio.h>
#include <string.h>

#define BATTID_LEN 8

main()
{
	char battid[BATTID_LEN+1];
	char *mrfl_batt_str = "INTN0001";

	snprintf(battid, BATTID_LEN+1, "%s", mrfl_batt_str);
	printf("battid = %d", strlen(battid));
}
