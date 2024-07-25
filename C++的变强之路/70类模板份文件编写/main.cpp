#include <iostream>
using namespace std;
#include "class.hpp"//如果包含.h文件，由于类模板成员函数在调用时才创建，所以它不知道函数是怎样的（雾？），解决
//方法有两个：
//一，直接包含源码.cpp，但一般都不用这方法，直接放源码不太好
//二，将声明与定义放在一起，约定俗成为.hpp文件

int main()
{
    person<string, int> p("xiaogong", 18);
    p.show();
    return 9;
}