#include <iostream>
using namespace std;

int  add(int a, int b)
{
    return a + b;
}
template <typename T>
int add1(T a, T b)
{
    T c=a+b;
    return c;
}
void f()
{
    int a = 10, b = 20;
    char c = 'c';
    cout << add(a, b) << endl; // 这是普通函数正常的使用方法
    cout << add(a, c) << endl; // 这是法案生了隐私类型转换

   // cout << add1(a, c) << endl;      // 如果模板v函数用的是饮食类型推导，就不会发发生类型妆转换。这段代码会报错
    cout << add1<int>(a, c) << endl; // 但显式会发生类型转换
}
int main()
{
    f();
    return 0;
}