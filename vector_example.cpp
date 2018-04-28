#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; i++)
        v.push_back(i);
    vector<int>::iterator iter = v.begin();
    for(;iter != v.end();)
    {
        if(*iter >= 3 && *iter <= 5) {
            iter = v.erase(iter);
        } else {
            iter++;
        }
    }
    iter = v.begin();
    for(;iter != v.end(); iter++)
    {
        cout << *iter << ",";
    }

    map<int, int> M;
    map<int, int>::iterator it = M.begin();
    for(;it != M.end();)
    {
        if(it->second == 0) {       // C98的写法
            M.erase(it++);
            it = M.erase(it);       // C11的写法，C11添加了返回下一个迭代器的方法
        } else {
            it++;
        }
    }
    return 0;
}