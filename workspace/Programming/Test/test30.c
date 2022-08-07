#include <stdio.h>
#include <stdlib.h>

#define EVT_STR		"BCU EVENT="
#define ACT_STR		"ACTION="

#define get_envp(x, y)		((x != ACTION) ? EVT_STR#y : ACT_STR#y)

#define EVENT		1
#define ACTION		2

enum bcu_events {
	VWARN1,
	VWARN2,
	VCRIT,
	__COUNT
};

main()
{
	char *bcu_evt[3];

	bcu_evt[0] = get_envp(EVENT, VCRIT);
	bcu_evt[1] = get_envp(ACTION, NONE);
	bcu_evt[2] = NULL;

	printf("%s %d\n", bcu_evt[0], strlen(bcu_evt[0]));
	printf("%s %d\n", bcu_evt[1], strlen(bcu_evt[1]));
}

