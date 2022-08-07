#include <stdio.h>
#include <stdlib.h>

void init_bc_regs(void *ptr)
{
	printf("%s\n", __func__);
}

void init_sc_regs(void *ptr)
{
	printf("%s\n", __func__);
}

void (*init_fn[])(void*) = {
	init_bc_regs,
	init_sc_regs
};

main()
{
	int i = 0;
	(init_fn[i])(NULL);
	i++;
	(init_fn[i])(NULL);
}
