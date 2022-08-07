#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *fp, *fpf;
	char basePath[] = "/sys/class/thermal";
	char idFilePath[] = "type";
	char command[128]={0};
	char idCommand[128]={0};
	char checkFilePath[128]={0};
	char SensorName[] = "SYSTHERM0";
	char dirName[128]={0};
	char readName[30] = {0};
	
	sprintf(command, "adb shell ls %s", basePath);
	fp = popen(command, "r");
	if (fp == NULL) {
		printf("Unable to open process 1!!\n");
		exit(-1);
	}

	while (fscanf(fp, "%s", dirName)) {
		sprintf(checkFilePath, "%s/%s/%s", basePath, dirName, idFilePath);
		sprintf(idCommand, "adb shell cat %s", checkFilePath);
		printf("ic=%s\n", idCommand);
		fpf = popen(idCommand, "r");
		if (fpf == NULL) {
			printf("Unable to open process 2!!\n");
			exit(-2);
		}
		fscanf(fpf, "%s", readName);
		if(strcmp(readName, SensorName) == 0) {
			printf("Match found in %s\n", checkFilePath);
			break;
		}
		fclose(fpf);
		printf("No match found!!\n");
	}
	fclose(fp);
	exit(0);
}
