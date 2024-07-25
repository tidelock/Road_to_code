#include <iostream>
using namespace std;

void myprint(int a, int b)
{
    cout << "普通函数调用" << endl;
}
template <typename T>
void myprint(T a, T b)
{
    cout << "模板函数调用" << endl;
}
template <typename T>
void myprint(T a, T b, T c)
{
    cout << "重载模板函数调用" << endl;
}

void f()
{
    int a = 10, b = 20;
    myprint(a, b);      ////普通函数和模板函数都可调用的情况下，有限调用普通函数（即使普通函数只是生命没有实现）
    myprint<>(a, b);    // 如果想要调用模板函数，可以像这样做一个空模板
    myprint(a, b, 100); // 模板函数可以发生重载，这是没有空模板事项也可以调用招惹个重载的函数
    char c, d;
    myprint(c, d); //如果符合度更高就优先调用，比如这里是chat类型，普通函数hi要类型转化，所以先调用模板函数
}
int main()
{
    f();
    return 9;
}