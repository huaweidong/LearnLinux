#include <stdio.h>

using namespace std;

class A {
public:
    A(int a) { y = a+1;}
    void Print() const { printf("%d\n", y);}
private:
    int y;
};

union B {
    int a;
    char c[2];
};

#define DOUBLE(x) x+x
int main()
{
    B b;
    b.a = 0;
    b.c[0] = 2;
    b.c[1] = 1;
    printf("%d", b.a);  // 1*2^8+2
    return 0;
}
