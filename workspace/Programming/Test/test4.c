#include <stdio.h>

main()
{
	char name[6]={0};
	unsigned short reg = 0x6A;

	snprintf(name,sizeof(name),"%02x",reg);
	printf("%d\n",sizeof(name));
	printf("%s\n",name);
}
