#include <stdio.h>

#define LOCK_NAME(x) #x

struct structure {
	int lock;
};

main()
{
	struct structure str;
	printf("%s",LOCK_NAME(&str->lock));
}
