#include <stdio.h>
#include <math.h>

#define min(a,b) ((a < b) ? a : b)

main()
{
	float TakeHome = 92610;
	float OtherEMI = 0;
	float E = (TakeHome * 0.6) - OtherEMI;
	float I = 10.25;
	float r = I/1200;
	float n = 12 * 20;
	float factor = pow((1+r), n);
	float PE;
	float P;
	float EA;

	float PC = 6000000;
	float EPC = 0.8 * PC;
	float Area = 1378;
	float RC = ((1378 * 2200) + 100000) * 0.09;
	float TC = PC + RC;
	float OC;
	float CIH = 700000 + 238000;

	PE = E * (factor- 1) / (factor * r);
	P = min(EPC, PE);
	EA = P * factor * r / (factor - 1);
	OC = TC - P;

	printf("EMI as per eligibility (E) = %.2f\n", E);
	printf("Actual EMI (EA) = %.2f\n", EA);
	printf("Monthly Rate(r) = %.5f\n", r);
	printf("Loan Tenure in months (n) = %.2f\n", n);
	printf("Loan eligibility (P) = %.2f\n", P);
	printf("Registration Charges (RC) = %.2f\n", RC);
	printf("Total Cost (TC) = %.2f\n", TC);
	printf("Own Contribution (OC = TC - P) = %.2f\n", OC);

	printf("Amount to be raised = %.2f\n", OC - CIH);
}

