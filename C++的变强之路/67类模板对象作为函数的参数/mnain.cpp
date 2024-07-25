#include <iostream>
using namespace std;
#include <string>

template <class T1, class T2>
class person
{
public:
    person(T1 name, T2 age)
    {
        this->name = name;
        this->age = age;
    }
    T1 name;
    T2 age;
    void show()
    {
        cout << "名字" << name << "   年龄" << age << endl;
    }
};
// 直接通过类型名   最常用，以下两个了解就好
void test01(person<string, int> &p)
{
    p.show();
}
// 参数模板化
template <typename T1, typename T2>
void test02(person<T1, T2> &p)
{
    p.show();
    cout << "T1的类型是" << typeid(T1).name() << endl;//新知识点，可以查看类型的名字
    cout << "T1的类型是" << typeid(T2).name() << endl;
}
//整个类模板化
template <class T>
void test03(T &p)
{
p.show();
}
int main()
{
    person<string, int> p("sehnli", 18);
    test01(p);
    test02(p);
    test03(p);
    return 8;
}