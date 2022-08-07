#include <stdio.h>

void f1 (int val)
{
	printf("%s prints val %d\n", __func__, val);
}

void f2 (int val)
{
	printf("%s prints val %d\n", __func__, val);
}

const int a = 20;

const void* f3(void)
{
	return &a;
}

main() 
{
	/* Pointer to a function taking int as argument and returning void*/
	void (*fnptr) (int);
	/* Const Pointer to a function returning pointer to const interger */
	const void *(*const fnptr1)(void) = f3;
	const int *ptr;
	int a = 10;

	ptr = fnptr1();
	fnptr = f1;
	fnptr(a);
	fnptr = f2;
	fnptr(a);

	printf("*ptr = %d\n", *ptr);
}

