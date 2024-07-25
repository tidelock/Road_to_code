#include <iostream>
using namespace std;

class myintegar
{
    friend ostream &operator<<(ostream &cout, myintegar myint);

public:
    // 重置前置++运算符
    myintegar &operator++() // 返回引用是为了对同一个数进行操作
    {
        a++;
        return *this; // 把它自身作返回，这里是myint
    }
    // 重置后置++运算符
    myintegar operator++(int) // int用于占位函数重载//注意这里不用引用
    {
        myintegar temp = *this;
        a++;
        return temp;
    }

private:
    int a = 18;
};

ostream &operator<<(ostream &cout, myintegar myint) // 配合友元重置 <<运算符
{
    cout << myint.a << endl;
    return cout;
}

void f()
{
    myintegar myint;
    cout << myint << endl;
    cout << myint++ << endl;
    cout << ++myint << endl;
}
int main()
{
    f();
    return 0;
}