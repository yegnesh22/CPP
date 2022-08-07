#include <stdio.h>
#include <string.h>

#define REG_DEF(x)	#x

main()
{
	char name [20] = {0};

	strcpy (name, REG_DEF(pmic->chgrirq0));
	printf("%s\n", name);
}

