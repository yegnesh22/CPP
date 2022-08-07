#include <stdio.h>

main(int argc, char *argv[])
{
	int i, br;

	if (argc == 1)
		br = 5;
	else
		br = atoi(argv[1]);

	printf("br:%d\n", br);

	printf("Entering while loop!!\n");
	while ((i < 5) && (i < br)) {
		printf("i=%d\n", i);
		i ++;
	}

	printf("Entering do-while loop!!\n");
	do {
		printf("i=%d\n", (i - 1));
		i --;
	} while (i);
}
