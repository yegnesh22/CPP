#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define set_bit(byte, bit)      (byte | (1 << bit))
#define reset_bit(byte, bit)    (byte & ~(1 << bit))
#define toggle_bit(byte, bit)   ~(byte ^ ~(1 << bit))
#define test_bit(byte, bit)     ((byte & (1 << bit)) >> bit)
#define mul(x, y)	((x) * (y))
#define max(x, y)	((x) > (y) ? (x) : (y))
#define abs(x)		((x) > 0 ? (x) : -(x))
#define is_str_equal(x, y)	((strcmp(x,y) ? "not same" : "same"))

enum bit_ops {
	eSET_BIT = 1,
	eRESET_BIT,
	eTOGGLE_BIT,
	eTEST_BIT
};

enum math_op {
	eMULTIPLY = 1,
	eMAX,
	eABS
};

enum str_op {
	eSTR_COMPARE = 1
};

enum main_ops {
	eBIT_OP = 1,
	eMATH_OP,
	eSTR_OP,
	eEXIT
};

void bit_op_menu()
{
	int option;
	unsigned char val, bit;
	
	printf("Choose your option:\n%d:set bit\n%d:reset bit\n%d:toggle bit\n%d:test bit\n: ", eSET_BIT, eRESET_BIT, eTOGGLE_BIT, eTEST_BIT);
	scanf("%d", &option);
	printf("Number (hex): ");
	scanf("%x", &val);
	printf("Bit(0-7) : ");
	scanf("%d", &bit);
	if (bit > 7) {
		printf("Invalid bit position!!\n");
		return;
	}

	switch(option) {
		case eSET_BIT:
			printf("set_bit(%x, %d) = %x\n", val, bit, set_bit(val, bit));
			break;
		case eRESET_BIT:
			printf("reset_bit(%x, %d) = %x\n", val, bit, reset_bit(val, bit));
			break;
		case eTOGGLE_BIT:
			printf("toggle_bit(%x, %d) = %x\n", val, bit, toggle_bit(val, bit));
			break;
		case eTEST_BIT:
			printf("test_bit(%x, %d) = %x\n", val, bit, test_bit(val, bit));
			break;
		default:
			printf("Invalid option\n");
			break;
	}

	return;
}

void math_op_menu()
{
	int option;
	int num1, num2;
	
	printf("Choose your option:\n%d: Multiply\n%d: Max\n%d:Abs\n: ", eMULTIPLY, eMAX, eABS);
	scanf("%d", &option);

	switch(option) {
		case eMULTIPLY:
			printf("Enter the numbers: ");
			scanf("%d %d", &num1, &num2);
			printf("mul(%d, %d): %d\n", num1, num2, mul(num1, num2));
			break;
		case eMAX:
			printf("Enter the numbers: ");
			scanf("%d %d", &num1, &num2);
			printf("max(%d, %d): %d\n", num1, num2, max(num1, num2));
			break;
		case eABS:
			printf("Enter the number: ");
			scanf("%d", &num1);
			printf("abs(%d) = %d\n", num1, abs(num1));
			break;
		default:
			printf("Invalid option!!\n");
			break;
	}
}

void str_op_menu()
{
	char str1[128] = {0};
	char str2[128] = {0};
	
	printf("String comparison\nEnter string 1:\n");
	scanf("%s", str1);
	printf("Enter string 2:\n");
	scanf("%s", str2);
	printf("%s and %s are %s!!\n",str1, str2, is_str_equal(str1,str2));
	return;
}

int main_menu()
{
	int option;
	printf("Main Menu\n%d. bit operations\n%d. math operations\n%d. string operation\n%d. Exit\n: ", eBIT_OP, eMATH_OP, eSTR_OP, eEXIT);
	scanf("%d", &option);
	return option;
}

main()
{
	int option;
	
	while (1) {
		option = main_menu();
		switch(option) {
			case eBIT_OP:
				bit_op_menu();
				break;
			case eMATH_OP:
				math_op_menu();
				break;
			case eSTR_OP:
				str_op_menu();
				break;
			case eEXIT:
				exit(0);
			default:
				printf("Invalid option\n");
				break;
		}
	}
}
