#include <iostream>
using namespace std;

class person
{
public:
    person()
    {
    }
    void f1() const // 常函数有在函数体内部的变量不可修改，除非变量名前加关键字mutable
    // const修饰this，使this指向的值也不可以修改
    {
        // a=18;

        b = 18;
        // this==NULL;
        // this指针的本质是指针常量，指向不可更改，指向p的this就不能指向NULL
    }

    void f2()
    {

    }
    int a;
    mutable int b;
};

void f()
{
    person p;
    p.f1();

    const person p1;
    //p1.a=18;
    //常对象里面的值也不可以更改，mutable除外
     p1.b=18;

   // p1.f2();
   //常对象只能调用常函数
}

int main()
{

    return 0;
}