#include <iostream>
using namespace std;

template <class nametype, class agetype = int> // 设置默认类型的该方法时价格等号
class person
{
public:
    person(nametype name, agetype age)
    {
        this->name = name;
        this->age = age;
    }
    nametype name;
    agetype age;
};

void f()
{
    // person p2("xiaogong" .16); // 类模板不能太自动类型与i到，因此需要显式类型转换
    person<string, int> p("shenli", 600);
    person<string> p2("bachong", 500); // 有了默认类型后就可以少些几个
    cout <<p2.name<<p2.age<<endl;
}

int main()
{
    f();
    return 9;
}