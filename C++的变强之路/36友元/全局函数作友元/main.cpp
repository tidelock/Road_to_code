#include <iostream>
using namespace std;

class home
{
    friend void guy(home *p); // 在类里面用friend关键字说明这个函数是友元，可以访问私有对象

public:
    string livingroom = "客厅";

private:
    string bedroom = "卧室";
};

void guy(home *p)
{
    cout << "朋友正在访问" << p->livingroom << endl;
    cout << "朋友正在访问" << p->bedroom << endl;
}

int main()
{
    home p;
    guy(&p);
    return 0;
}