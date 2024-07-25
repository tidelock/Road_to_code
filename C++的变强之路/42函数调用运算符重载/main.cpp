#include <iostream>
using namespace std;

class myprint
{
public:
    void operator()(string s) // 因为与函数很类似，所以也叫仿函数
    {
        cout << s << endl;
    }
};

void f()
{
    myprint ak47;
    ak47("我是神里绫华的狗");
    myprint()("我是尼露的狗"); // 这就是一个匿名函数
}
int main()
{
    f();
    return 0;
}