#include <stdio.h>

struct A{
    int i;
    double d;
    char c;    
};

int main()
{
    printf("%ld", sizeof(struct A));
    return 0;
}