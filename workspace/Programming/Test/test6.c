#include <stdio.h>
#include <errno.h>

#define TABLE_LENGTH    34
static const int adc_code[2][TABLE_LENGTH] = {
	{952, 932, 906, 877, 843, 804, 761, 714, 665, 614,
		563, 512, 462, 415, 370, 329, 291, 257, 226, 199,
		174, 153, 135, 119, 104, 92, 81, 72, 64, 56,
		50, 45, 40, 36},
	{-40, -35, -30, -25, -20, -15, -10, -5, 0, 5,
		10, 15, 20, 25, 30, 35, 40, 45, 50, 55,
		60, 65, 70, 75, 80, 85, 90, 95, 100, 105,
		110, 115, 120, 125},
};

static int find_adc_code(unsigned short val)
{
	int left = 0;
	int right = TABLE_LENGTH - 1;
	int mid;

	while (left <= right) {
		mid = (left + right)/2;
		if (val == adc_code[0][mid] ||
				(mid > 0 &&
				 val > adc_code[0][mid] && val < adc_code[0][mid-1]))
			return mid;
		else if (val > adc_code[0][mid])
			right = mid - 1;
		else if (val < adc_code[0][mid])
			left = mid + 1;
	}

	return -EINVAL;
}


main()
{
	int index;
	unsigned short adc_val;

	printf("Enter adc code [36-952]\n");
	scanf("%d",&adc_val);
	index = find_adc_code(adc_val);

	if(adc_code[0][index] == adc_val) {
		printf("adc_val=%x temp_val=%d\n",adc_code[0][index],adc_code[1][index]);
	} else {
		printf("index=%d\n",index);
		printf("x0=%d x1=%d y0=%d y1=%d\n",
			adc_code[0][index], adc_code[0][index-1],
			adc_code[1][index], adc_code[1][index-1]);
	}
}
