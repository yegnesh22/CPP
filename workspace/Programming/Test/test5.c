#include <stdio.h>
#include <errno.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#define is_valid_temp(tmp)\
        (!(tmp > adc_tbl[0].temp ||\
                tmp < adc_tbl[ARRAY_SIZE(adc_tbl) - 1].temp))

#define is_valid_adc_code(val)\
        (!(val < adc_tbl[0].adc_val ||\
                val > adc_tbl[ARRAY_SIZE(adc_tbl) - 1].adc_val))

#define DIV_ROUND_CLOSEST(x, divisor)(                  \
{                                                       \
        typeof(divisor) __divisor = divisor;            \
        (((x) + ((__divisor) / 2)) / (__divisor));      \
}                                                       \
)

#define ADC_TO_TEMP 1
#define TEMP_TO_ADC 0
 
#define CONVERT_ADC_TO_TEMP(adc_val, temp)\
         adc_temp_conv(adc_val, temp, ADC_TO_TEMP)
 
#define CONVERT_TEMP_TO_ADC(temp, adc_val)\
         adc_temp_conv(temp, adc_val, TEMP_TO_ADC)

struct temp_lookup {
	int adc_val;
	int temp;
	int temp_err;
};
 
static struct temp_lookup adc_tbl[] = {
	{0x24, 125, 0}, {0x28, 120, 0},
	{0x2D, 115, 0}, {0x32, 110, 0},
	{0x38, 105, 0}, {0x40, 100, 0},
	{0x48, 95, 0}, {0x51, 90, 0},
	{0x5C, 85, 0}, {0x68, 80, 0},
	{0x77, 75, 0}, {0x87, 70, 0},
	{0x99, 65, 0}, {0xAE, 60, 0},
	{0xC7, 55, 0}, {0xE2, 50, 0},
	{0x101, 45, 0}, {0x123, 40, 0},
	{0x149, 35, 0}, {0x172, 30, 0},
	{0x19F, 25, 0}, {0x1CE, 20, 0},
	{0x200, 15, 0}, {0x233, 10, 0},
	{0x266, 5, 0}, {0x299, 0, 0},
	{0x2CA, -5, 0}, {0x2F9, -10, 0},
	{0x324, -15, 0}, {0x34B, -20, 0},
	{0x36D, -25, 0}, {0x38A, -30, 0},
	{0x3A4, -35, 0}, {0x3B8, -40, 0},
};


static int interpolate_y(int dx1x0, int dy1y0, int dxx0, int y0)
{
        return y0 + DIV_ROUND_CLOSEST((dxx0 * dy1y0), dx1x0);
}

static int interpolate_x(int dy1y0, int dx1x0, int dyy0, int x0)
{
        return x0 + DIV_ROUND_CLOSEST((dyy0 * dx1x0), dy1y0);
}
 
static int adc_temp_conv(int in_val, int *out_val, int conv)
{
	int tbl_row_cnt = ARRAY_SIZE(adc_tbl), i;

	if (conv == ADC_TO_TEMP) {
		if (!is_valid_adc_code(in_val)) {
			return -ERANGE;
		}
		if (in_val == adc_tbl[tbl_row_cnt-1].adc_val) {
			printf("Entering boundary Check\n");
			i = tbl_row_cnt - 1;
		} else {
			for (i = 0; i < tbl_row_cnt; ++i)
				if (in_val < adc_tbl[i].adc_val)
					break;
		}
		printf("adc_tbl[%d]: .adc_val=%x temp=%d\n",i,adc_tbl[i].adc_val,adc_tbl[i].temp);
		printf("adc_tbl[%d]: .adc_val=%x temp=%d\n",i-1,adc_tbl[i-1].adc_val,adc_tbl[i-1].temp);

		*out_val =
			interpolate_y((adc_tbl[i].adc_val - adc_tbl[i - 1].adc_val),
					(adc_tbl[i].temp - adc_tbl[i - 1].temp),
					(in_val - adc_tbl[i - 1].adc_val),
					adc_tbl[i - 1].temp);
	} else {
		if (!is_valid_temp(in_val)) {
			return -ERANGE;
		}
		if (in_val == adc_tbl[tbl_row_cnt-1].temp) {
			printf("Entering boundary Check\n");
			i = tbl_row_cnt - 1;
		} else {
			for (i = 0; i < tbl_row_cnt; ++i)
				if (in_val > adc_tbl[i].temp)
					break;
		}
		printf("adc_tbl[%d]: .adc_val=%x temp=%d\n",i,adc_tbl[i].adc_val,adc_tbl[i].temp);
		printf("adc_tbl[%d]: .adc_val=%x temp=%d\n",i-1,adc_tbl[i-1].adc_val,adc_tbl[i-1].temp);

		*((short int*)out_val) =
			interpolate_x((adc_tbl[i].temp - adc_tbl[i - 1].temp),
					(adc_tbl[i].adc_val - adc_tbl[i - 1].adc_val),
					(in_val - adc_tbl[i - 1].temp),
					adc_tbl[i - 1].adc_val);
	}
	return 0;
}

main()
{
	int adc_val;
	int temp_val;
	int ret;
	printf("Enter the adc_val[0x24 to 0x3b8]:");
	scanf("%x",&adc_val);
	ret = adc_temp_conv(adc_val,&temp_val,ADC_TO_TEMP);
	if (ret == 0) 
		printf("[0] adc_val=%x temp_val=%d\n",adc_val,temp_val);
	else
		printf("adc_val out of range\n");

	printf("Enter the temp_val[-40 to 125]:");
	scanf("%d",&temp_val);
	ret = adc_temp_conv(temp_val,&adc_val,TEMP_TO_ADC);

	if (ret == 0)
		printf("[1] adc_val=%x temp_val=%d\n",adc_val,temp_val);
	else
		printf("temp_val out of range\n");

}
