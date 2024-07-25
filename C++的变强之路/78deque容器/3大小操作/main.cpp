#include <iostream>
using namespace std;
#include <deque>
void printdeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void f()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1的大小为  " << d1.size() << endl;
        // 注意deque没有容量capacity的概念
    }
    d1.resize(16, 1);//大小变为16，默认值是1，放在后面
    printdeque(d1);
    d1.resize(4);
    printdeque(d1);
}
int main()
{
    f();
    return 0;
}