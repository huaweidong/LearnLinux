#include <iostream>
using namespace std;

class A
{
public:
    A() {
        cout << "Con" << endl;
    }
    A(const A& a) {
        cout << "Copy" << endl;
    }
    const A& operator = (const A& a) {
        cout << "=" << endl;
    }
    ~A() {
        cout << "Des" << endl;
    }
};

int main()
{
    A a;
    A b = a;
    A c;
    c = a;
    return 0;
}