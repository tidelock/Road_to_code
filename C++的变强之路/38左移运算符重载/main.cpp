#include <iostream>
using namespace std;

class person
{
    friend ostream & operator<<(ostream &c_out, person &p);//operstor 也可以作为友元

private:
    int age=18;
};
// void operator<<(cout)
// {

// }最后的结果是p<<cout 一般不会实现cout 在右侧的重载，p.operator(cout)->p<<cout

ostream & operator<<(ostream &c_out, person &p) // 不能改人家的cout于是用引用的方式
{
    c_out << p.age << endl; // 由于链式编程，返回值必须是ostream类型
    return c_out;
    
}

void f()
{
    person p;
    cout << p << endl;
}

int main()
{
    f();
    return 0;
}