#include <stdio.h>

#define ARRAY_SIZE(x)	((sizeof(x) / sizeof(x[0])))

#define CELCIUS_TO_DECI_KELVIN(x) \
	((x * 10) + 2732)

#define clamp_t(type, val, min, max) ({         \
        type __val = (val);                     \
        type __min = (min);                     \
        type __max = (max);                     \
        __val = __val < __min ? __min: __val;   \
        __val > __max ? __max: __val; })


static inline int fls(int x)
{
	int i = 0;

	while (x) {
		x >>= 1;
		i++;
	}

	return i;
}

long lpat[] = {
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
	0x5FB5, 
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

static int intel_wc_pmic_update_aux(unsigned int resi_val)
{
	int ret;
	unsigned short raw;
	unsigned int bsr_num;
	unsigned short count = 0;
	unsigned short thrsh = 0;
	unsigned char cursel = 0;

	printf("resi_val:%x\n", resi_val);
	bsr_num = resi_val;
	bsr_num /= (1 << 5);

	while (bsr_num >>= 1)
		count++;
	//count = fls(bsr_num) - 1;

	cursel = clamp_t(int, (count-7), 0, 7);
	thrsh = resi_val / (1 << (4+cursel));

	raw = ((cursel << 9) | thrsh);

	printf("alert_h:%x alert_l:%x\n", (raw >> 8), (unsigned char)raw);

	return 0;
}

/* Return raw value from temperature through LPAT table */
static int temp_to_raw(int temp)
{
	int i, delta_temp, delta_raw, raw;

	printf("Looking up temp:%x\n", temp);

	for (i = 0; i < ARRAY_SIZE(lpat); i+=2) {
		if (temp >= lpat[i] && temp <= lpat[i+2])
			break;
	}

	delta_temp = lpat[i+2] - lpat[i];
	delta_raw = lpat[i+3] - lpat[i+1];
	raw = lpat[i+1] + (temp - lpat[i]) * delta_raw / delta_temp;

	return raw;
}

main()
{
	int temp;
	unsigned int t;
	unsigned int resi_val;

	printf("Enter the temp:\n");
	scanf("%d", &temp);

	t = CELCIUS_TO_DECI_KELVIN(temp);
	resi_val = temp_to_raw(t);
	intel_wc_pmic_update_aux(resi_val);
}
