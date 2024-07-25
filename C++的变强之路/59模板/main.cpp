#include <iostream>
using namespace std;

template <typename T>   // 记住关键字template和typename，T是约定俗成的
void myswap(T &a, T &b) // 可以减少不同数据类型，但逻辑关系一样的代码量
{
    T temp = a;
    a = b;
    b = temp;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}
void test()
{
    int a = 10, b = 20;
    myswap(a, b); // 隐式，让编译器去猜你的数据类型
    float c = 1.1, d = 2.3;
    myswap<float>(c, d); // 显式，直接告诉数据类型
}
int main()
{
    test();
    return 0;
}

// 注意事项1
// 函数模板的T必须一致，比如myswap(int a,char b)就不能使用函数模板myswap(T &a, T &b)

// 注意事项2
// 写了函数模板必须要知道T的数据类型，如：

// template<typename T>
// void func()
//  {
// cout <<"我是神里绫华的狗"<<endl;
//  }

//如果主函数中用func()就会报错，因为编译器不知道T的数据类型，模板中也没用到，
//但如果是func<int>()就可以，因为虽然没用到，但起码知道T是什么类型了