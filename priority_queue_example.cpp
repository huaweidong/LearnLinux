#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
using namespace std;
void test1(){
    //默认情况下，数值大的在队首位置(降序)
    priority_queue<int> q;
    for(int i  = 0;i <= 10;i ++)
        q.push(i);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;

    //greater<int>表示数值小的优先级越大
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i  = 0;i <= 10;i ++)
        Q.push(i);
    while(!Q.empty()){
        cout<<Q.top()<<" ";
        Q.pop();
    }

}

struct student {
    int age;
    string name;
    friend bool operator < (const student& s1, const student& s2) {
        return s1.age > s2.age;
    }
};

int main()
{
    test1();
    student s1, s2, s3;
    s1.age = 1;
    s2.age = 2;
    s3.age = 3;
    s1.name = "a";
    s2.name = "b";
    s3.name = "c";
    student s4;
    s4.age = 100;
    s4.name = "d";
    priority_queue<student> P;
    P.push(s3);
    P.push(s1);
    P.push(s4);
    P.push(s2);
    while(!P.empty()) {
        student s = P.top();
        cout << s.age << s.name << endl;
        P.pop();
    }
    return 0;
}
