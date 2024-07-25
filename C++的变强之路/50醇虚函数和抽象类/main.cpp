#include <iostream>
using namespace std;

class base
{
public:
    virtual void func() = 0; // 通常包含虚函数的函数没什么用，所以令他等于0，招惹而就是唇虚函数
    // 包含醇虚函数有的类称为抽象类
};
class son : public base
{
public:
    void func() // 子类要重写父类的虚函数,否则子类也部门能实例化
    {
        cout << "我是神里绫华的狗" << endl;
    }
};
void f()
{
    // base a;
    // 抽象类不能实例化
    son s;
    s.func();
}
int main()
{
    f();
    return 0;
}