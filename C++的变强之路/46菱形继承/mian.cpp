#include <iostream>
using namespace std;

class animal // 动物
{
public:
    int age;
};
// class sheep : public animal // 羊
// {
// public:
// };
// class tuo : public animal // 驼
// {
// public:
// };

//利用虚继承，关键字virtual，可以解决这个问题
//父类animal称为虚基类
//虚继承本质是继承指针，再通过偏移量找到数据
class sheep : virtual public animal // 羊
{
public:
};
class tuo : virtual public animal // 驼
{
public:
};
class sheeptuo : public sheep, public tuo // 羊驼
{
public:
};

void f()
{
    sheeptuo st;
    st.sheep::age = 18;
    st.tuo::age = 28;//歧义在于羊驼的年龄是18还是28？只需要一份就可以了，导致资源浪费

    cout << st.sheep::age << endl;
    cout << st.tuo::age << endl;
    //用虚继承后，相当于这个age是共享的了,既然是共享的也就不需要作用域了
    cout << st.age << endl;
}
int main()
{
    f();
    return 0;
}