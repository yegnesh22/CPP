#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int print_index = 0;

int dummy(char* s, ...)
{
	return 0;
}

int (*func_ptr[]) (char *, ...) = {
	dummy,
	printf,
};

main()
{
	int i=0;
	int fd;
	char c[2]={0};


	while (i < 10) {
		fd = open("test_sysfs", O_RDONLY);
		if (fd == -1) {
			printf("Exiting the app!!\n");
			exit(1);
		}
		read(fd, &c, sizeof(char));
		close(fd);
		c[1] = '\0';
		printf("%s\n", c);
		print_index = atoi(&c);
		printf("print_index=%d\n", print_index);
		if (print_index > 1)
			print_index = 1;
		(func_ptr[print_index])("iteration %d print_index=%d\n", i, print_index);
		i ++;
		sleep(1);
	}
}
