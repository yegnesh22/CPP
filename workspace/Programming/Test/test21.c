#include <stdio.h>

int (*fn[2]) (char, char);

int fn1(char a, char b)
{
	printf("%s\n", __func__);
}
int fn2(char a, char b)
{
	printf("%s\n", __func__);
}
main()
{
	char a, b;
	fn[0] = fn1;
	fn[1] = fn2;

	fn[0](a, b);
	fn[1](a, b);
}
