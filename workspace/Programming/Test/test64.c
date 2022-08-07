#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

int lpat [] = {
	0x09E3, 
	0x00076272, 
	0x0A15, 
	0x00058192, 
	0x0A47, 
	0x00042551, 
	0x0A79, 
	0x0003267F, 
	0x0AAB, 
	0x00026A06, 
	0x0ADD, 
	0x0001DD93, 
	0x0B0F, 
	0x000173FB, 
	0x0B41, 
	0x000123EA, 
	0x0B73, 
	0xE6B9, 
	0x0BA5, 
	0xB798, 
	0x0BD7, 
	0x930B, 
	0x0C09, 
	0x767E, 
	0x0C3B, 
	0x600F, 
	0x0C6D, 
	0x4E50, 
	0x0C9F, 
	0x4031, 
	0x0CD1, 
	0x34E3, 
	0x0D03, 
	0x2BC9, 
	0x0D35, 
	0x2470, 
	0x0D67, 
	0x1E76, 
	0x0D99, 
	0x1990, 
	0x0DCB, 
	0x158E, 
	0x0DFD, 
	0x1242, 
	0x0E2F, 
	0x0F84, 
	0x0E61, 
	0x0D3C, 
	0x0E93, 
	0x0B56, 
	0x0EC5, 
	0x09BE, 
	0x0EF7, 
	0x0866, 
	0x0F29, 
	0x0744, 
	0x0F5B, 
	0x064F, 
	0x0F8D, 
	0x057E
};

int lookup_adcval(int value)
{
	int temp = value / 100 + 2732 ;
	int delta_raw;
	int delta_temp;
	int adc_val;
	int i;

	printf("temp:%d\n",temp);
	for (i = 2; i < ARRAY_SIZE(lpat); i += 2) {
		if ((lpat[i] > temp) && (lpat[i-2] < temp)) {
			printf("i:%d lpat_1_temp:%d lpat_1_raw:%x lpat_2_temp:%d lapt_2_raw:%x\n",
				i, lpat[i-2], lpat[i-1], lpat[i], lpat[i+1]);
			delta_temp = lpat[i] - lpat[i-2];
			delta_raw = lpat[i+1] - lpat[i-1];
			adc_val = lpat[i+1] + (temp - lpat[i]) * delta_raw / delta_temp;
			return adc_val;
		}
	}
}

main()
{
	int adc_val;
	int value = 0;
	long bsr_num;
	long bsr_num_store;
	long count = 0;
	unsigned short raw, thrsh, cur_sel;

	scanf ("%d", &value);
	adc_val = lookup_adcval(value);
	printf("temp = %d adc_val=%x\n", value, adc_val);
	bsr_num = adc_val;
	bsr_num /= (1 << 5);
	bsr_num_store = bsr_num;

	while (bsr_num >>= 1)
		count ++;

	cur_sel = ((count - 7) > 0) ? (((count - 7) > 7) ? 7 : (count - 7)) : 0;
	thrsh = adc_val / (1 << (4 + cur_sel));

	raw = (cur_sel << 9) | thrsh;

	printf("bsr_num:%x count:%d cur_sel:%x thrsh:%x raw:%x\n", bsr_num_store, count, cur_sel, thrsh, raw);
}
