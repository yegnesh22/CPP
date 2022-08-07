#include <iostream>
#include <stdio.h>

class Singleton {
	private:
		Singleton() : obj(NULL) {
		}
	public:
		static Singleton *obj;
		static Singleton* getInstance()
		{
			if (obj == NULL)
				obj = new Singleton;
			return obj;
		}
};

//Singleton *Singleton::obj = NULL;

main()
{
	Singleton *t1=t1->getInstance();
	Singleton *t2=t2->getInstance();

	printf("t1:%p t2=%p\n", t1, t2);
	return 0;
}
