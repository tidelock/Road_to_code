#include <iostream>
using namespace std;

class person
{

public:
    void f1()
    {
        cout << "我是神里绫华的狗" << endl;
    }
    void f2()
    {
        if (this == NULL)
        {
            return;
        }
        // 为了防止不崩，通常加入以上代码
        cout << "我是妮露的狗" << this->age << endl;
    }
    int age = 18;
};

void f()
{
    person *p = NULL;
    p->f1();
    //  p->f2();
    // 这句代码会出错，因为类里面的age实际上是this->age, this是一个对象，而p是一个空指针，里面没有成员
}

int main()
{
    f();
    return 0;
}