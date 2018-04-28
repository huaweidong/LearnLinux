#include <stdio.h>
int main()
{
    int a[] = {1,4};
    int* pa = a;
    //printf("%d\n", *pa++);
    printf("%d\n", *pa++); // *pa++和*(pa++)是一致的，++还没生效，取*，然后++才生效
    printf("%d\n", *pa);
    printf("%d %d\n", a[0], a[1]);
    return 0;
}