#include <string.h>
#include <stdio.h>

#define MAX_LEN 10
char str[MAX_LEN];

main()
{
	int len;

	strcpy(str,"rcc");
	len = strnlen(str, MAX_LEN);
	printf("len1=%d\n",len);
	str[0]=0x00;
	len = strnlen(str, MAX_LEN);
	printf("len2=%d\n",len);
}

