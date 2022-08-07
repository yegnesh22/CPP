#define MODULE_GENERIC_TABLE(gtype,name)                        \
	extern const struct gtype##_id __mod_##gtype##_table            \
	__attribute__ ((unused, alias(__stringify(name))))

#define MODULE_DEVICE_TABLE(type,name)          \
	MODULE_GENERIC_TABLE(type##_device,name)

MODULE_DEVICE_TABLE(rpmsg, intel_thermal_id_table);

