#include <iostream>
using namespace std;
#include <deque>
void f()
{
    deque<int>d;
    int i;
    for (i = 0; i < 10; i++)
    {
        d.push_back(i); // assign(1,i)会报错，为什么？
    }
    for ( i = 0; i < 10; i++)
    {
        cout << d[i] << endl;
    }
    for ( i = 0; i < 10; i++)
    {
        cout << d.at(i) << endl;
    }
    cout << "d的第一个数据为  " << d.front() << endl;
    cout << "d的最后一个数据为  " << d.back() << endl;
}
int main()
{
    f();
    return 0;
}