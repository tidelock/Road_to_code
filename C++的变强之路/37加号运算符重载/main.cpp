#include <iostream>
using namespace std;

class person
{
public:
    // person operator+(person &p)        //通过成员函数实现重载
    // {
    //     person temp;
    //     temp.age = this->age + p.age;
    //     return temp;
    // }
    int age;
};

person operator+(person &p1, person &p2)
{
    person temp;
    temp.age = p1.age + p2.age;
    return temp;
}

/*/**
 * @brief 重载加法运算符，用于两个 person 对象的相加
 *
 * 将两个 person 对象的年龄相加，并返回一个新的 person 对象，其年龄为两个输入对象的年龄之和。
 *
 * @param p1 第一个 person 对象，用于加法运算的左操作数
 * @param p2 第二个 person 对象，用于加法运算的右操作数
 *
 * @return 返回一个 person 对象，其年龄为 p1 和 p2 的年龄之和
 */
void f()
{
    person p1, p2;
    p1.age = p2.age = 18;
    person p = p1 + p2; // 原型是person p=p1.operator+(p2); 或者person operator(p3,p4);
    cout << p.age << endl;
}

int main()
{
    f();
    return 0;
}