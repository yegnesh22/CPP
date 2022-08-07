#include <stdio.h>

void fn1(void)
{
	printf("Hello1\n");
}

void fn2(void)
{
	printf("Hello2\n");
}

void fn3(void)
{
	printf("Hello3\n");
}

void fn0(void)
{
	printf("Hello0\n");
}

void (*fn []) (void) = {
	fn0,
	fn1,
	fn2,
	fn3
};

main()
{
	int index;
	printf("Enter a number [0-3]:\n");
	scanf("%d", &index);
	if (index <= 3) {
		fn[index]();
	}
}
