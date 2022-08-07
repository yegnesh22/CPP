#include <stdio.h>

#define Rlsb	1017
#define max(a,b) ((a > b) ? a : b)

struct NTC {
	long Rntc;
	long dRntc;
};

static struct NTC ntc_values[] = {
	{ 26809, 1154 },
	{ 25683, 1097 },
	{ 24612, 1044 },
	{ 23593, 993 },
	{ 22623, 946 },
	{ 21700, 901 },
	{ 20820, 858 },
	{ 19982, 817 },
	{ 19184, 779 },
	{ 18422, 743 },
	{ 17696, 709 },
	{ 17004, 676 },
	{ 16343, 645 },
	{ 15712, 616 },
	{ 15109, 588 },
	{ 14534, 562 },
	{ 13984, 537 },
	{ 13459, 513 },
	{ 12957, 491 },
	{ 12476, 469 },
	{ 12017, 449 },
	{ 11577, 429 },
	{ 11157, 411 },
	{ 10754, 393 },
	{ 10369, 377 },
	{ 10000, 361 },
	{ 9646, 346 },
	{ 9307, 331 },
	{ 8982, 318 },
	{ 8670, 305 },
	{ 8371, 292 },
	{ 8085, 280 },
	{ 7810, 269 },
	{ 7546, 258 },
	{ 7292, 248 },
	{ 7049, 238 },
	{ 6815, 229 },
	{ 6590, 220 },
	{ 6375, 211 },
	{ 6167, 203 },
	{ 5968, 195 },
	{ 5776, 188 },
	{ 5592, 180 },
	{ 5414, 174 },
	{ 5243, 167 },
	{ 5079, 161 },
	{ 4921, 155 },
	{ 4769, 149 },
	{ 4622, 143 },
	{ 4481, 138 },
	{ 4344, 133 },
	{ 4213, 128 },
	{ 4087, 124 },
	{ 3965, 119 },
	{ 3847, 115 },
	{ 3734, 111 },
	{ 3624, 107 },
	{ 3519, 103 },
	{ 3417, 100 },
	{ 3318, 96 },
	{ 3223, 93 },
	{ 3132, 90 },
	{ 3043, 87 },
	{ 2958, 84 },
	{ 2875, 81 },
	{ 2795, 78 },
	{ 2718, 75 },
	{ 2643, 73 },
	{ 2571, 70 },
	{ 2501, 68 },
	{ 2434, 66 },
	{ 2368, 64 },
	{ 2305, 62 },
	{ 2244, 60 },
	{ 2185, 58 },
	{ 2127, 56 },
	{ 2072, 54 },
	{ 2018, 52 },
	{ 1966, 51 },
	{ 1916, 49 },
	{ 1867, 48 }
}; 

void usage(char *app_name, int argc)
{
	printf("Usage: %s [temp] [hyst]\n", app_name);
	printf("argc=%d\n", argc);
}

int main(int argc, char **argv)
{
	long ADCnorm, dADCnorm; 
	long cur_val, cur_log, cur_sel;
	long hyst_val, hyst_bit, thrsh;
	int temp, hyst;
	int i = 0;
	unsigned short reg_val;
	unsigned char alert_val_h, alert_val_l;

	if (argc != 3) {
		usage(argv[0], argc);
		return -1;
	}

	sscanf(argv[1], "%d", &temp);
	sscanf(argv[2], "%d", &hyst);

	printf("temp=%d hyst=%d\n", temp, hyst);

	ADCnorm = ntc_values[temp].Rntc * 1000 / Rlsb;
	dADCnorm = ntc_values[temp].dRntc * hyst * 1000 / Rlsb;

	cur_val = ADCnorm / (1 << 5);
#ifdef DEBUG
	printf("cur_val=%lx\n", cur_val);
#endif
	while (cur_val) {
		cur_val >>= 1;
		i ++;
	}
	cur_log = i - 8;
#ifdef DEBUG
	printf("i=%d\n", i);
#endif
	cur_sel =  max(cur_log, 0);
	thrsh = ADCnorm / (1 << (4 + cur_sel));
#ifdef DEBUG
	printf("cur_sel=%lx cur_log=%lx cur_val=%lx\n", cur_sel, cur_log, cur_val);
#endif
	if (dADCnorm  > 0) {
		hyst_val = dADCnorm / ( 1 << (7 + cur_sel));
		hyst_bit = max(hyst_val, 1);
	} else {
		hyst_bit = 0;
	}

#ifdef DEBUG
	printf("ADCnorm=%lx dADCnorm=%lx\n", ADCnorm, dADCnorm);
	printf("hyst_bit=%lx cur_sel=%lx thrsh=%lx\n", hyst_bit, cur_sel, thrsh);
#endif
	reg_val = (((hyst_bit & 0x0f) << 12) | ((cur_sel & 0x07) << 9) | (thrsh & 0x1FF));
	alert_val_h = (reg_val >> 8);
	alert_val_l = (reg_val & 0x00FF);

	printf("reg_val = %x\n", reg_val);
	printf("aler_val_h=%x alert_val_l=%x\n", alert_val_h, alert_val_l);
}
