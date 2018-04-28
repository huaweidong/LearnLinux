#include <stdio.h>
int main()
{
    union {
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;
    printf("hwd:%d %d\n", un.c[0], un.c[1]);
    if(un.c[0] == 1 && un.c[1] == 2)
    {
        printf("hwd:: Big Endian\n");
    } else if (un.c[0] == 2 && un.c[1] == 1) 
    {
        printf("hwd: Little Endian\n");
    }

    return 0;
}
