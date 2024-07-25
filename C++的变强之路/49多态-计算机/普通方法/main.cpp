#include <iostream>
using namespace std;

class calcultor
{
public:
    int a;
    int b;
    int getsult(char oper)
    {
        if (oper == '+')
            return a + b;
        else if (oper == '-')
            return a - b;
        else if (oper == '*')
            return a * b;
        else if (oper == '/')
            return a / b;
        return 0;
    }
};
void f()
{
    calcultor c;
    c.a = 10;
    c.b = 20;
    cout << c.a << "+" << c.b << "=" << c.getsult('+') << endl;
    cout << c.a << "-" << c.b << "=" << c.getsult('-') << endl;
    cout << c.a << "*" << c.b << "=" << c.getsult('*') << endl;
    cout << c.a << "/" << c.b << "=" << c.getsult('/') << endl;
}
int main()
{
    f();
    return 0;
}