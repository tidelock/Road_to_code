#include <iostream>
#include <string>
using namespace std;

class person
{
public:
bool operator==(person &p)//同样也可以做一个不等于的运算符重载
{
    if(p.age==age&&p.name==name)
    return true;
    else return false;
}
    string name;
    int age;
};

void f()
{
    person p1, p2;
    p1.name = p2.name = "LiHua";
    p1.age = p2.age = 18;
    if(p1==p2) cout<<"这两个是相等的"<<endl;
    else cout<<"这两个是不相等的"<<endl;
}

int main()
{
    f();
    return 0;
}