#include <iostream>
using namespace std;
#include <deque>//deque是一个双端数组，头插要比vector快很多，但访问数据要慢
void printdeque(const deque<int> &d)//注意这里也要加
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // *it=100;
        // 用const_iterator后，数据就不可写
        cout << *it << ' ';
    }
    cout << endl;
}
void f()
{
    deque<int> d1;//默认构造
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    deque<int> d2(d1.begin() + 1, d1.end() - 1);//传入地址
    printdeque(d2);
    deque<int> d3(d2);//拷贝构造
    printdeque(d3);
    deque<int> d4(5, 16);//有5个16
    printdeque(d4);
}
int main()
{
    f();
    return 0;
}