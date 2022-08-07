#include <stdio.h>

unsigned short le_to_be_16(unsigned short le_value)
{
	unsigned short be_value = 0;

	be_value = (le_value & 0xFF) << 8;
	be_value |= (le_value & 0xFF00) >> 8;

	return be_value;
}

unsigned int le_to_be_32(unsigned int le_value)
{
	unsigned int be_value = 0;

	be_value |= (le_value & 0x000000FF) << 24;
	be_value |= (le_value & 0x0000FF00) << 8;
	be_value |= (le_value & 0x00FF0000) >> 8;
	be_value |= (le_value & 0xFF000000) >> 24;

	return be_value;
}

void print_memory_32(unsigned int* pValue)
{
	unsigned char *p = (unsigned char*)pValue;

	printf("[%p]: %x\n", p, *p);
	p++;
	printf("[%p]: %x\n", p, *p);
	p++;
	printf("[%p]: %x\n", p, *p);
	p++;
	printf("[%p]: %x\n", p, *p);
}

void print_memory_16(unsigned short* pValue)
{
	unsigned char *p = (unsigned char*)pValue;

	printf("[%p]: %x\n", p, *p);
	p++;
	printf("[%p]: %x\n", p, *p);
}

main()
{
	unsigned int value1 = 0xDEADBEEF;
	unsigned short value2 = 0xBEEF;

	printf("Storage of 32 bit value in little endian: %x\n", value1);
	print_memory_32(&value1);
	printf("Storage of 32 bit value in big endian: %x\n", value1);
	value1 = le_to_be_32(value1);
	print_memory_32(&value1);
	printf("Storage of 16 bit value in little endian: %x\n", value2);
	print_memory_16(&value2);
	printf("Storage of 16 bit value in big endian: %x\n", value2);
	value2 = le_to_be_16(value2);
	print_memory_16(&value2);
}
