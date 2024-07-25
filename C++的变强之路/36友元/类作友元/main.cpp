#include <iostream>
#include <string>
using namespace std;

class home
{
    friend class guy;//其实和全局函数作友元差不多

public:
    home();
    string livingroom;

private:
    string bedroom;
};

class guy
{
public:
    guy();
    void visit();
    home *h;
};
// 类外定义构造函数，构造函数里是变量的初始化
home::home()
{
    livingroom = "客厅";
    bedroom = "卧室";
}
guy::guy()
{
    h = new home;
}
void guy::visit()
{
    cout << "好朋友正在访问" << h->bedroom << endl;
}

int main()
{
    guy a;
    a.visit();
    return 0;
}