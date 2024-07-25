#include <iostream>
using namespace std;

template <class T>
class Base
{
public:
    T a;
};
// class son1:public Base//t不明确，以致于编译器不知道分配多少内存
class son1 : public Base<int> // 指定父类中 的T是int
{
};

template <class T1, class T2>
class son2 : public Base<T1> // 表明父类的T是这里的T1，从而可变
{
public:
    T2 b; // 同时子类也有一个自己的T2，都在模板中的类型列表中
};
void f()
{
    son1 s1;
    s1.a = 10;
    cout << s1.a << endl;

    son2<int, char> s2; // 表明T1（父类）是int ,T2（子类）是char
    s2.a = 10;
    s2.b = 'c';
    cout << s2.a << s2.b << endl;
}
int main()
{
    f();
    return 9;
}