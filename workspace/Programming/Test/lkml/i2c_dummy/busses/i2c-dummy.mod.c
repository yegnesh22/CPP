#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x49ce6154, "module_layout" },
	{ 0x51f6704e, "platform_driver_unregister" },
	{ 0x9d129024, "platform_driver_register" },
	{ 0xe962aa96, "dev_err" },
	{ 0xe02d776, "i2c_add_numbered_adapter" },
	{ 0xded69622, "__mutex_init" },
	{  0xb5494, "kmem_cache_alloc_trace" },
	{ 0x882990b9, "kmalloc_caches" },
	{ 0x4dbf39e0, "mutex_unlock" },
	{ 0xcad1fd6c, "_dev_info" },
	{ 0x6c4f69e9, "mutex_lock" },
	{ 0xea34a5c, "dev_printk" },
	{ 0x37a0cba, "kfree" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7D5F1CE26D09FED42111496");
