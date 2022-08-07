#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DBG_BATT_PATH "/d/max170xx_battery/"
#define BUF_SIZE	6
#define PATH_LEN	128
#define LOG_FILE "/config/em/maxim_regs.csv"

inline void memclr(char* addr, int len)
{
	int i;

	for (i = 0; i <= len; i++)
		addr[i] = 0x00;
}

int main(int argc, char *argv[])
{
	int i;
	int dump_fd, fd;
	int ret = 0;
	char path[PATH_LEN];
	char dump_file_path[PATH_LEN] = LOG_FILE;
	char buf[BUF_SIZE] = {0};
	char delim = ';';
	char eol = '\n';

	dump_fd = open(dump_file_path, O_CREAT|O_APPEND|O_RDWR, 0666);
	if (dump_fd == -1)
		return -1;

	while (1) {
		for (i = 0; i <= 0xFF; i++) {
			sprintf(path, "%s%x", DBG_BATT_PATH, i);
			fd = open(path, O_RDONLY);
			if (fd == -1) {
				close(dump_fd);
				return -1;
			}
			read(fd, buf, sizeof(buf));
			close(fd);
			write(dump_fd, buf, strlen(buf)-1);
			memclr(buf, strlen(buf));
			write(dump_fd, &delim, sizeof(delim));
		}
		write(dump_fd, &eol, sizeof(eol));
		usleep(10000000);
	}
	close(dump_fd);
	return 0;
}
