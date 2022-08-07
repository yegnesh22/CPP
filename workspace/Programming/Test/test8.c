#include <stdio.h>

#define DISCHRG_CURVE_MAX_SAMPLES 17
#define DISCHRG_CURVE_MAX_COLOMNS 2
/*
 * This array represents the sample discharge curve
 * of the battery. Can used to voltage Vs capacity mapping.
 *  Column 0 represents Voltage in mV and column 1 represent
 * charge in capacity in %.
 */
static short int dischargeCurve[DISCHRG_CURVE_MAX_SAMPLES]
[DISCHRG_CURVE_MAX_COLOMNS] = {
	/* in mV , in % */
	{4200, 100},
	{4150, 95},
	{4100, 90},
	{4050, 85},
	{4000, 80},
	{3950, 75},
	{3900, 65},
	{3850, 55},
	{3800, 45},
	{3750, 30},
	{3700, 20},
	{3650, 15},
	{3600, 10},
	{3550, 8},
	{3500, 5},
	{3450, 3},
	{3400, 0},
};


/* Discharge curve lookup function to get
 * capacity value against voltage */
static unsigned int dischrg_curve_lookup(unsigned int val)
{
        int val_diff, val_total_diff, total_diff, i;
        unsigned int lookup_val;

        /* Find the index of most nearest sample value */
        for (i = 0; i < DISCHRG_CURVE_MAX_SAMPLES; i++) {
                if (val < dischargeCurve[i][0])
                        continue;
		 else 
                        break;
        }

        if (i >= DISCHRG_CURVE_MAX_SAMPLES) {
                printf("max17042_battery: charge out of range\n");
                return 0;
        }

        if (i == 0)
                return dischargeCurve[i][1];

        /* Linear approximation of the discharge curve */
        val_diff = val - dischargeCurve[i][0];
        val_total_diff = dischargeCurve[i - 1][0] - dischargeCurve[i][0];
        total_diff = dischargeCurve[i - 1][1] - dischargeCurve[i][1];

        lookup_val = dischargeCurve[i][1] +
                (total_diff * val_diff) / val_total_diff;

        return lookup_val;
}

short dischargeLookup(unsigned int voltage)
{
	unsigned int min = dischargeCurve[DISCHRG_CURVE_MAX_SAMPLES-1][0];
	unsigned int max = dischargeCurve[0][0];
	unsigned int capacity;
	int total_diff;
	int diff;

	total_diff = max - min;
	diff = max - voltage;
	printf("diff=%d total_diff=%d\n",diff, total_diff);
	capacity = (total_diff - diff) * 100 / total_diff;
	return capacity;
}

main()
{
	unsigned int vocv;
	unsigned int val;

	printf("Enter the vocv value:(3400-4200)\n");
	scanf("%d",&vocv);
	printf("Capacity=%d\n",dischrg_curve_lookup(vocv));
	printf("Capacity1=%d\n",dischargeLookup(vocv));
}
