#define ASSIGN_READ_MMIO_VFUNCS(x) \
	readl = x##_read32

main()
{
	int (*readl)(int);

	ASSIGN_READ_MMIO_VFUNCS(vgpu);
	ASSIGN_READ_MMIO_VFUNCS(gen2);
}
