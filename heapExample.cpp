#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp1(int &v1, int &v2)
{
    return v1 > v2;     // cmp省略时默认参数为<,创建的是大顶堆，这里设置为>,创建的则是小顶堆
}
 
int main()
{
    std::vector<int> v { 3, 1, 4, 1, 5, 9 };
 
    std::cout << "initially, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::make_heap(v.begin(), v.end(), cmp1);
 
    std::cout << "after make_heap, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::pop_heap(v.begin(), v.end(), cmp1);
    std::cout << "after pop_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    auto largest = v.back();
    v.pop_back();
    std::cout << "largest element: " << largest << '\n';
 
    std::cout << "after removing the largest element, v: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    v.push_back(6);

    std::cout << "before push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
 
    std::push_heap(v.begin(), v.end(), cmp1);
 
    std::cout << "after push_heap: ";
    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';

    std::sort_heap(v.begin(), v.end(), cmp1);
 
    std::cout << "sorted:\t";
    for (const auto &i : v) std::cout << i << ' ';
    std::cout << '\n';
}