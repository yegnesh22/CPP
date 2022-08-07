#include <linux/module.h>

void exit_helloworld()
{
	printk("Bye!!! Hello World\n");
}

int init_helloworld()
{
	printk(KERN_INFO "Hello World!!\n");
	return 0;
}

module_init(init_helloworld);
module_exit(exit_helloworld);

MODULE_AUTHOR("Yegnesh Iyer <yegnesh.s.iyer@intel.com");
MODULE_DESCRIPTION("Hello World driver");
MODULE_LICENSE("GPL v2");

