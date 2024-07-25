#include <iostream>
using namespace std;

class basepage
{
public:
    void up()
    {
        cout << " 这是页面的共有头部" << endl;
    }
    void left()
    {
        cout << " 这是页面的共有左部" << endl;
    }
    void down()
    {
        cout << " 这是页面的共有右部" << endl;
    }
};
class game_a:public basepage//用构造函数可知，先有父类，再有子类
{
public:
    void f()
    {
        cout << "这是游戏a" << endl;
    }
};
class game_b:public basepage
{
public:
    void f()
    {
        cout << "这是游戏b" << endl;
    }
};
class game_c:public basepage
{
public:
    void f()
    {
        cout << "这是游戏c" << endl;
    }
};

int main()
{
game_a a;
a.up();
a.left();
a.f();
a.down();
cout<<"----------------"<<endl;
game_b b;
b.up();
b.left();
b.f();
b.down();
cout<<"----------------"<<endl;
game_c c;
c.up();
c.left();
c.f();
c.down();
cout<<"----------------"<<endl;
    return 0;
}