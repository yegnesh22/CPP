#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRLEN	24

char (*new_str) [STRLEN];

char chan_name[][STRLEN] = { "chan1", "chan2", "chan3", "chan4"};

main()
{
	int num_str = 3;
	int i;

	new_str = malloc(num_str);
	for (i = 0; i < num_str; i++)
		strcpy(new_str[i], chan_name[i]);

	for (i = 0; i < num_str; i++)
		printf("new_str[%d] = %s\n", i, new_str[i]);
	
}

