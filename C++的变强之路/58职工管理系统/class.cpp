#include "class.h"

boss::boss(int a, string b, int c)
{
    num = a;
    name = b;
    job = c;
}
void boss::showifo()
{
    cout << "序号:" << num << "\t姓名:" << name << "\t岗位:" << getduty() << "\t职责:发工资" << endl;
}
string boss::getduty()
{
    return string("老板");
}

manager::manager(int a, string b, int c)
{
    num = a;
    name = b;
    job = c;
}
void manager::showifo()
{
    cout << "序号:" << num << "\t姓名:" << name << "\t岗位:" << getduty() << "\t职责:管理" << endl;
}
string manager::getduty()
{
    return string("经理");
}

employee::employee(int a, string b, int c)
{
    employee::num = a;
    employee::name = b;
    employee::job = c;
}
void employee::showifo()
{
    cout << "序号:" << num << "\t姓名:" << name << "\t岗位:" << getduty() << "\t职责:干活" << endl;
}
string employee::getduty()
{
    return string("打工人");
}