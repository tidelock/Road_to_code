#include <iostream>
using namespace std;

class person1
{
public:
    void p1show()
    {
        cout << "这是person1的成员函数调用" << endl;
    }
};
class person2
{
public:
    void p2show()
    {
        cout << "这是person2的成员函数调用" << endl;
    }
};
template <class T>
class person
{
public:
    T obj;
    void func1()
    {
        obj.p1show();
    }
    void func2() // 模板成员函数在调用的时候才实现，所以，T是person1时，
    // 即使没有p2show()，只要不调用这一段代码也不会报错
    {
        obj.p2show();
    }
};

void f()
{
    person<person1> p0;
    p0.func1();
    // p0.func2();
}
int main()
{
    f();
    return 9;
}