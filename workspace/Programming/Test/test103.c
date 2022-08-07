#include <stdio.h>

#ifdef LOG_NDEBUG
#define thd_log_debug	printf
#define thd_log_info 	printf
#else
#define thd_log_debug
#define thd_log_info
#endif

main()
{
	int index = 0;
	thd_log_debug("D:debug --> %d\n", index);
	thd_log_info("I:Info --> %d\n", index);
}
