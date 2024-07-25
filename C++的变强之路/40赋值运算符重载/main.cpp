#include <iostream>
using namespace std;

class person
{
public:
    person(int a)
    {
        age = new int(a);
    }
    ~person()
    {
        if (age != NULL)
        {
            delete age;
            age = NULL;
        }
    }
    person &operator=(person &p)//返回引用才是返回自身，否则是返回副本
    {
        if (age != NULL)
        {
            delete age;
            age = NULL;
        }
        age = new int(*p.age);
        return *this; // 为了解决p1=p2=p3这样链式编程的操作
    }
    int *age;
};

void f()
{
    person p1(18);
    person p2(20);
    p2 = p1; // 浅拷贝
    cout << *p1.age << endl;
    cout << *p2.age << endl;
}

int main()
{
    f();
    return 0;
}