#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int comp1(const void* p1, const void* p2)
{
	int* t1 = (int*)p1;
	int* t2 = (int*)p2;
	if(*t1 > *t2) return 1;		// 从小到大
	else if (*t1 < *t2) return -1;
	else return 0;
}

bool comp2(const int& v1, const int& v2)
{
	return v1 < v2;		// 从小到大
}

struct Student
{
	int age;
	string name;
};

struct MyComp
{
	bool operator() (const Student &s1, const Student &s2) {
		return s1.age < s2.age;
	}
};

int main()
{
	int a[] = {2, 3, 5, 9, 7, 4, 6};
	vector<int> va(a, a+7);
	//qsort(&va[0], va.size(), sizeof(int), comp1);
	sort(va.begin(), va.end(), comp2);
	for(int i = 0; i < va.size(); i++) {
		cout << va[i] << "\t";
	}
	cout << endl;

	Student s1, s2, s3, s4;
    s1.age = 3;
    s2.age = 1;
    s3.age = 2;
    s1.name = "3";
    s2.name = "1";
    s3.name = "2";
    s4.age = 100;
	s4.name = "100";
	vector<Student> vS;
	vS.push_back(s1);
	vS.push_back(s2);
	vS.push_back(s3);
	vS.push_back(s4);

	MyComp mycomp;
	sort(vS.begin(), vS.end(), mycomp);

	for(int i = 0; i < vS.size(); i++) {
		cout << vS[i].name << "\t";
	}
	cout << endl;

    return 0;
}
