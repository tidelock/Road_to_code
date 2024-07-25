#include <iostream>
#include <conio.h>
using namespace std;

class base1
{
public:
    int a;
};
class base2
{
public:
    int b;
};
class son : public base1, public base2 // 继承多个类在开发中不太常用，但还是要掌握
{
public:
    int c;
};

int main()
{
    son s;
    s.a = s.b = 18;
    cout << s.a << s.b << endl;
    return 0;
}