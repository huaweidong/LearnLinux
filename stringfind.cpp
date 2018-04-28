#include <string>
#include <iostream>
using namespace std;

int main()
{
    string name = "Local, Float, Smart";
    cout << (name.find("Group")!=string::npos) << endl;
    return 0;
}
