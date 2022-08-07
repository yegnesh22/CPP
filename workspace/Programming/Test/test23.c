#include <stdio.h>

#define ARRAY_SIZE(x) ((sizeof(x)/sizeof(x[0])))

#define PMIC_REG_DEF(x) { \
		.name = #x, \
		.reg_addr = x, \
	}


#define IRQLVL1_ADDR                    0x01
#define IRQLVL1_MASK_ADDR               0x0c
#define CHGRIRQ0_ADDR                   0x07
#define MCHGRIRQ0_ADDR                  0x12
#define SCHGRIRQ0_ADDR                  0x4E
#define LOWBATTDET0_ADDR                0x2C
#define LOWBATTDET1_ADDR                0x2D
#define BATTDETCTRL_ADDR                0x2E
#define VBUSDETCTRL_ADDR                0x50
#define VDCINDETCTRL_ADDR               0x51
#define CHRGRIRQ1_ADDR                  0x08
#define MCHGRIRQ1_ADDR                  0x13
#define SCHGRIRQ1_ADDR                  0x4F
#define CHGRCTRL0_ADDR                  0x4B
#define CHGRCTRL1_ADDR                  0x4C
#define CHGRSTATUS_ADDR                         0x4D
#define USBIDCTRL_ADDR          0x19
#define USBIDSTAT_ADDR          0x1A
#define WAKESRC_ADDR            0x24
#define THRMBATZONE_ADDR                        0xB5
#define THRMZN0H_ADDR                   0xCE
#define THRMZN0L_ADDR                   0xCF
#define THRMZN1H_ADDR                   0xD0
#define THRMZN1L_ADDR                   0xD1
#define THRMZN2H_ADDR                   0xD2
#define THRMZN2L_ADDR                   0xD3
#define THRMZN3H_ADDR                   0xD4
#define THRMZN3L_ADDR                   0xD5
#define THRMZN4H_ADDR                   0xD6
#define THRMZN4L_ADDR                   0xD7

struct pmic_reg_def {
	char name[20];
	unsigned char reg_addr;
};

static struct pmic_reg_def pmic_regs[] = {
	PMIC_REG_DEF(IRQLVL1_ADDR),
	PMIC_REG_DEF(IRQLVL1_MASK_ADDR),
	PMIC_REG_DEF(CHGRIRQ0_ADDR),
	PMIC_REG_DEF(SCHGRIRQ0_ADDR),
	PMIC_REG_DEF(MCHGRIRQ0_ADDR),
	PMIC_REG_DEF(LOWBATTDET0_ADDR),
	PMIC_REG_DEF(LOWBATTDET1_ADDR),
	PMIC_REG_DEF(BATTDETCTRL_ADDR),
	PMIC_REG_DEF(VBUSDETCTRL_ADDR),
	PMIC_REG_DEF(VDCINDETCTRL_ADDR),
	PMIC_REG_DEF(CHRGRIRQ1_ADDR),
	PMIC_REG_DEF(SCHGRIRQ1_ADDR),
	PMIC_REG_DEF(MCHGRIRQ1_ADDR),
	PMIC_REG_DEF(CHGRCTRL0_ADDR),
	PMIC_REG_DEF(CHGRCTRL1_ADDR),
	PMIC_REG_DEF(CHGRSTATUS_ADDR),
	PMIC_REG_DEF(USBIDCTRL_ADDR),
	PMIC_REG_DEF(USBIDSTAT_ADDR),
	PMIC_REG_DEF(WAKESRC_ADDR),
	PMIC_REG_DEF(THRMBATZONE_ADDR),
	PMIC_REG_DEF(THRMZN0L_ADDR),
	PMIC_REG_DEF(THRMZN0H_ADDR),
	PMIC_REG_DEF(THRMZN1L_ADDR),
	PMIC_REG_DEF(THRMZN1H_ADDR),
	PMIC_REG_DEF(THRMZN2L_ADDR),
	PMIC_REG_DEF(THRMZN2H_ADDR),
	PMIC_REG_DEF(THRMZN3L_ADDR),
	PMIC_REG_DEF(THRMZN3H_ADDR),
	PMIC_REG_DEF(THRMZN4L_ADDR),
	PMIC_REG_DEF(THRMZN4H_ADDR),
};


main()
{
	int i;
	int len = ARRAY_SIZE(pmic_regs);

	for ( i = 0; i < len; i++ ) {
		printf("[%d] name=%s addr=%x\n", i, 
			pmic_regs[i].name, pmic_regs[i].reg_addr);
	}
}
