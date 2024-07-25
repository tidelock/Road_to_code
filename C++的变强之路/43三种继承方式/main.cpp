#include <iostream>
using namespace std;

class base
{
public://可继承，可访问
    int a;

protected://可继承，不可访问
    int b;

private://不可继承，不可访问
    int c;
};

class son1 : public base//将base里能访问的成员变成公有
{
public:
    int z;
};
class son2 : protected base//将base里能访问的成员变成保护
{
public:
    int z;
};
class son3 : private base//将base里能访问的成员变成私有
{
public:
    int z;
    
};
void f()
{
    son1 s1;
    cout << s1.a << endl;
    son2 s2;
    // cout << s2.a << endl;
    son3 s3;
    // cout << s3.a << endl;
}
int main()
{
    f();
    return 0;
}