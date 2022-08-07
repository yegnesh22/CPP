#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int exit_flag = 0;

void myKillHandler(int signal)
{
	printf("exiting!!\n");
	exit_flag = 1;
}

main()
{
	signal(SIGUSR1, myKillHandler);
	while(!exit_flag) {
		printf("Executing!!\n");
		sleep(10);
	}
}
