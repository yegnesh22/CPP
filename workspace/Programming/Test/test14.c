#include <stdio.h>

#ifdef CONFIG_PM
#define SET_PM_OPS(suspend_fn, resume_fn) \
		.suspend = suspend_fn, \
		.resume = resume_fn, \
		.freeze = suspend_fn, \
		.thaw = resume_fn,
#else
#define SET_PM_OPS(suspend_fn, resume_fn)
#endif

struct pm_ops {
	int (*suspend) (void);
	int (*resume) (void);
	int (*freeze) (void);
	int (*thaw) (void);
};

#ifdef CONFIG_PM
int my_suspend(void)
{
	return 0;
}

int my_resume(void)
{
	return 0;
}
#endif

struct pm_ops my_pm_ops = {
	SET_PM_OPS(my_suspend, my_resume)
};

main()
{
	if(my_pm_ops.suspend)
		printf("suspend=%p\n",my_pm_ops.suspend);
	if(my_pm_ops.resume)
		printf("resume=%p\n",my_pm_ops.resume);
	if(my_pm_ops.freeze)
		printf("freeze=%p\n",my_pm_ops.freeze);
	if(my_pm_ops.thaw)
		printf("thaw=%p\n",my_pm_ops.thaw);
}
