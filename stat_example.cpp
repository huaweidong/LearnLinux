#include <sys/stat.h>
#include <stdio.h>
int main()
{
    struct stat st;
    printf("%d", stat("/media/huaweidong/MyData/tempda", &st));
    return 0;
}
