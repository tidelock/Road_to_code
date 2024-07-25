#include <iostream>
using namespace std;

class absdreak
{
public:
    virtual void boil() = 0;
    virtual void add() = 0;
    virtual void attach() = 0;
    virtual void ready() = 0;
    void step()
    {
        boil();
        add();
        attach();
        ready();
    }
};
class coffee : public absdreak
{
public:
    void boil()
    {
        cout << "正在煮水" << endl;
    };
    void add()
    {
        cout << "正在加入咖啡" << endl;
    };
    void attach()
    {
        cout << "加上牛奶和糖" << endl;
    };
    void ready()
    {
        cout << "已经准备好了" << endl;
    };
};
class tea : public absdreak
{
public:
    void boil()
    {
        cout << "正在煮农夫山泉" << endl;
    };
    void add()
    {
        cout << "正在加入茶叶" << endl;
    };
    void attach()
    {
        cout << "加上一些蜂蜜" << endl;
    };
    void ready()
    {
        cout << "已经准备好了" << endl;
    }
};
void dodreak(absdreak *abs)
{
    abs->step();
    delete abs;//手动开辟,手动删除
}
int main()
{
    dodreak(new coffee);
    cout << "---------------" << endl;
    dodreak(new tea);
    return 0;
}