#include <iostream>
using namespace std;

class animal
{
public:
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};
class cat : public animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;//当子类重写了父类的虚函数时，会覆盖父类的函数，
        //包括函数地址即animal::speak->cat::speak
    }
};
class dog : public animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};
void dospeak(animal &a)//父类指针或引用指向子类对象时，发生多态（多个子类）
{
    a.speak();
}
void f()
{
    cat c;
    dospeak(c);
    dog d;
    dospeak(d);
}
int main()
{
    f();
    return 0;
}