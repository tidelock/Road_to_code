#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class person
{
public:
    person(T1 name, T2 age);
    T1 name;
    T2 age;
    void show();
};

template <class T1, class T2> /*2、编译器不认识T1,T2因此做一个函数模板*/
person<T1, T2> /*3、这里说明这不是一个普通函数而是一个模板函数 的类外实现*/ ::person(T1 name, T2 age)
/*1、这是构造函数或者成员函数必须要有的参数*/
{
    this->name = name;
    this->age = age;
}

// 成员函数也如此
template <class T1, class T2>
void person<T1, T2>::show()
{
    cout << "名字：" << this->name << "     年龄：" << this->age << endl;
}
void f()
{
    person<string, int> p1("神里绫华", 18);
    p1.show();
}
int main()
{
    f();
    return 0;
}