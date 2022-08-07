#include <stdio.h>
#include <string.h>

void print_ascii(char *str)
{
	int i;
	int len = 8;
	for (i=0; i < len;  i++)
		printf("%x ", str[i]);
	printf("\n");
}

main()
{
	char bat1[] = "PG000001";
	char bat2[8] = {0};

	bat2[0]='I';
	bat2[1]='2';
	bat2[7]=0x11;
	print_ascii(bat1);
	printf("%c",bat2[0]);
	print_ascii(bat2);
}
