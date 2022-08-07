#include <stdio.h>

main()
{
	unsigned char byte[] = {0x21, 0x03, 0xC7, 0x01};
	unsigned short vadc_val;
	unsigned short cadc_val;
	unsigned int voltage;
	unsigned int current;
	
	//voltage = (( byte[0] << 2 ) | byte[1] );
	vadc_val =0x321;
	cadc_val = 0x3F2;
	//current = (( byte[2] << 2 ) | byte[3] );

	voltage = (vadc_val * 4692) / 1000;
	voltage = voltage + 65 * 150 / 1000;
	current = (cadc_val * 7813) / 1000;
	printf("%d\n",voltage);
	printf("%d\n",current);
}
