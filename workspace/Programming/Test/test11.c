#include <stdio.h>

/*convert adc_val to current mA */
#define MSIC_ADC_MAX_CUR                4000    /* In milli Amph */
#define MSIC_ADC_TO_CUR(adc_val)        ((78125 * (adc_val)) / 10000)

main()
{
	int adc_val;
	int tmp;

	printf("Enter the adc_val(-511 to 512):\n");
	scanf("%d",&adc_val);
	tmp = MSIC_ADC_TO_CUR(adc_val & 0x1FF);
	/* if D9 bit is set battery is discharging */
	if (adc_val & 0x200)
		tmp = -(MSIC_ADC_MAX_CUR - tmp);

	printf("tmp=%d\n",tmp);
}
