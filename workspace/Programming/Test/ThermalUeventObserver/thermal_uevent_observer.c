#include <unistd.h>
#include <poll.h>
#include <string.h>
#ifdef ANDROID
#include <utils/Log.h>
#else
#include <stdio.h>
#define ALOGI(x) printf(LOG_TAG ": (I)/ " x "\n");
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>


#define LOG_TAG "ThermalUeventObserver"
#define LENGTH 100

int main(void)
{
	struct pollfd fds;
	int fd;
	int nr;
	char buffer[LENGTH] = {0};

	ALOGI("Starting thermal uevent observer!!");
	fd = open("/sys/devices/pci0000:00/0000:00:1a.0/usb1/1-1/1-1.2/1-1.2:1.0/input/input3/mouse0/uevent", O_RDONLY);
	fds.fd = fd;
	fds.events = POLLIN;
	fds.revents = 0;

	while (1) {
		nr = poll(&fds, 1, -1);
		if (nr > 0) {
			int count = recv(fd, buffer, LENGTH, 0);
			if (count > 0) {
				ALOGI("Uevent received!!");
			}
		}
	}

	close(fd);

	return 0;
}
