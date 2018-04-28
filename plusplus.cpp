#include <stdio.h>
int main()
{
    int i = 0; 
    printf("%d %d\n", ++i, ++i);    // 2, 2
    printf("%d %d\n", ++i, i++);    // 4, 2
    printf("%d %d\n", i++, i++);    // 5, 4
    printf("%d %d\n", i++, ++i);    // 7, 8 先执行++i，i变成7,然后执行i++,i变成8,但是i++之前i=7,所以第一个数是7, 第二个输出i的当前值

    int j = 0;
    printf("%d %d\n", j++, ++(++j));    // 2, 3

    int k = 0;
    printf("%d %d\n", ++k, k++);    // 2, 0
    return 0;
}

// ++i返回的更新后的i值，i++返回的是i之前的临时值
