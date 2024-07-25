#include <iostream>
using namespace std;

class animal
{
public:
    virtual void speak() = 0;
    animal()
    {
         cout << "这是animal的构造函数调用" << endl;
    }
//    virtual ~ animal()
//     {
//          cout << "这是animal的析构函数调用" << endl;
//     }
virtual ~ animal()=0;
};

animal::~animal()//纯虚析构类内声明,类外定义
{
     cout << "这是animal的析构函数调用" << endl;
}

class cat : public animal
{
public:
    cat(string name)
    {
        cout << "这是cat的构造函数调用" << endl;
        this->name = new string(name);
    }
    ~cat()
    {
        cout << "这是cat的析构函数调用" << endl;
        if (name != NULL)
        {
            delete name;
            name = NULL;
        }
    }
    void speak()
    {
        cout << *name << "小猫在说话" << endl;
    }
    string *name;
};
void f()
{
    animal *a = new cat("Tom");
    a->speak();
    delete a;//如果这样写,那么释放的只是animal的指针
    //子类cat的指针并没有释放(因为没有调用cat的析构函数)
    //解决方法是animal的析构函数加virtual称为虚析构/纯虚析构
    //这两种有不同的写法
}
int main()
{
    f();
    return 0;
}