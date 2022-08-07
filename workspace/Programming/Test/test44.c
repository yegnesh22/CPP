#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

main()
{
	int fd;
	char buf[] = "Anand";
	char eol = '\n';

	fd = open("myfile.txt", O_CREAT|O_APPEND|O_RDWR, 0666);
	write(fd, buf, strlen(buf));
	write(fd, &eol, sizeof(eol));
	close(fd);
}

