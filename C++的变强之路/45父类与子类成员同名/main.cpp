#include <iostream>
using namespace std;

class base
{
public:
    int a = 18;
    static int b;
    void f(int x)
    {
        cout << "我是神里绫华的狗" << endl;
    }
};
class son : public base
// 只要子类出现了同名成员，就默认用子类的，，父类的全部忽视，重载函数也忽视，想要用父类的就要加作用域
{
public:
    int a = 20;
    static int b;
    void f()
    {
        cout << "我是尼露的狗" << endl;
    }
};
int b = 100;
int base::b = 200;

int main()
{
    son s;
    cout << s.a << endl;
    cout << s.base::a << endl;
    //   cout << s.b << endl;
    //  cout << s.base::b << endl;

    // s.f(4) ;
    s.f();
    s.base::f(4);
    return 0;
}