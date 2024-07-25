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
    for (int i = 5; i < 10; i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    d1.push_back(100);//尾插
    d1.push_front(200);//头插
    printdeque(d1);
    d1.pop_back();//尾删
    d1.pop_front();//头删
    printdeque(d1);

    // 插入
    deque<int> d2;
    d2.assign(5, 16);

    d1.insert(d1.begin() + 1, 888); // 第一二位置中间插入888
    printdeque(d1);
    d1.insert(d1.begin() + 1, d2.begin(), d2.end() - 1); // 在d1的begin+1位置插入d2的begin到end-1位置的数
    printdeque(d1);

    d1.erase(d1.begin(), d1.end());
    d1.clear(); // 这两个相当于同一个函数
    printdeque(d1);
}
int main()
{
    f();
    return 0;
}