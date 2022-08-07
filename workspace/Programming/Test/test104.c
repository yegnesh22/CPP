#include <stdio.h>

main()
{
	char str[200];
	char fn[] = "/usr/local/temp/t";
	char fntemp[] = "/usr/local/temp/t1";
	sprintf(str, "Cannot rename checkpoint file %s -> %s; maybe you are out of disk space?", fntemp, fn);
	printf("str=%s\n", str);
}

