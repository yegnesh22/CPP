#include <stdio.h>

union dword {
	unsigned int val;
	struct {
		unsigned char byte[4];
	} bytes;
	struct {
		unsigned short word[2];
	} words;
};

main()
{
	union dword w1;

	w1.val = 0xA5B6C7D8;

	printf("val: %x word[0]:%x word[1]:%x byte[0]:%x byte[1]:%x byte[2]:%x byte[3]:%x\n",
		w1.val, w1.words.word[0], w1.words.word[1], w1.bytes.byte[0], 
		w1.bytes.byte[1], w1.bytes.byte[2], w1.bytes.byte[3]);
}
