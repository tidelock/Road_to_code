#include <iostream>
using namespace std;

class animal
{
public:
   virtual void speak()//如果没有虚函数，那么下面的f()的animal与speak()的地址已经早绑定，在编译阶段就可以确定地址
   //不管传什么动物，都会执行“动物在说话”，加virtual后，地址晚绑定
   // 这个函数称为虚函数
    {
        cout << "动物在说话" << endl;
    }
};
class cat : public animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
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
void dospeak(animal &a)//父类引用接受子类对象，这是允许的
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