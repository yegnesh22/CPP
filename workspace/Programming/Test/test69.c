#include <stdio.h>

struct regmap_irq {
	int reg_offset;
	int mask;
};

#define INIT_REGMAP_IRQ(_variant, _irq, _off, _mask)                    \
        [_variant##_IRQ_##_irq] = { .reg_offset = (_off), .mask = BIT(_mask) }

static const struct regmap_irq irq[] = {
	INIT_REGMAP_IRQ(AXP20X, ACIN_OVER_V,            0, 7),
	INIT_REGMAP_IRQ(AXP20X, ACIN_PLUGIN,            0, 6),
	INIT_REGMAP_IRQ(AXP20X, ACIN_REMOVAL,           0, 5),
};

