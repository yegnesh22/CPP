#include <stdio.h>

void print_array(int (*p)[5])
{
	int i;

	printf ("[%p] -> ", p);
	for (i = 0; i < 5; i++) {
		printf("%d ", *((int*)p + i));
	}
	printf("\n");
}

main()
{
	int b[5] = {-1, -2, -3, -4, -5};
	int a[5] = {1, 2, 3, 4, 5};
	/* Pointer to an array of 5 integer elements */
	int (*ptr) [5];

	printf("address of a = %p\n", a);
	printf("address of b = %p\n", b);
	ptr = a;
	print_array(ptr);
	ptr = b;
	print_array(ptr);
	ptr = a;
	print_array(ptr);
	ptr = b;
	print_array(ptr);
	ptr = a;
	print_array(ptr);
}
