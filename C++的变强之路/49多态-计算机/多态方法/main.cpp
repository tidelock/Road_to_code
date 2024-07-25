#include <iostream>
using namespace std;
// 传统方法想要扩展功能，只能修改源码，还要在源码中找，不利于开发
class calcultor
{
public:
    int a;
    int b;
    virtual int getresult()
    {
        return 0;
    }
};
// 如果想要一个加法功能，就新建一个类
class add : public calcultor
{
public:
    int getresult()
    {
        return a + b;
    }
};
// 减法也一样
class sub : public calcultor
{
public:
    int getresult()
    {
        return a - b;
    };
};
int main()
{
    calcultor *c = new add; // 父类指针或者引用子类对象
    c->a = 10;
    c->b = 20;
    cout << c->getresult() << endl;
    c = new sub; // 父类指针或者引用子类对象
    c->a = 10;
    c->b = 20;
    cout << c->getresult() << endl;
    delete c; // 用完记得销毁
    return 0;
}
