#include <iostream>
using namespace std;
#include <deque>
void printdeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << ' ';
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

    // assign传地址
    deque<int> d2;
    d2.assign(d1.begin() + 1, d1.end() - 1);
    printdeque(d2);

    // operator等号赋值
    deque<int> d3;
    d3 = d2;
    printdeque(d3);
    
    // assign5个16赋值
    deque<int> d4;
    d4.assign(5, 16);
    printdeque(d4);
}
int main()
{
    f();
    return 0;
}