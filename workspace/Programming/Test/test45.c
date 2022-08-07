#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

main()
{
	int fd, ret;
	char string[] = "Yegnesh";

	fd = open("myfile.txt", O_WRONLY);

	if (fd < 0) {
		perror(sys_errlist[errno]);
		printf("Error no:%d\n", errno);
		exit(-1);
	}

	ret = write(fd, string, sizeof(string));
	if(ret < 0) {
		perror(sys_errlist[errno]);
		printf("Error no:%d\n", errno);
		close(fd);
		exit(-1);
	}

	close(fd);
	exit(0);
}

