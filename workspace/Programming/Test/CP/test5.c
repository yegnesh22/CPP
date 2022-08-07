#include<stdio.h>
main()
{
    struct std
    {
        int x = 3;
        char name[] = "hello";
    };
    struct std *s;
    printf("%d", s->x);
    printf("%s", s->name);
}

