#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

void myprint(int val)
{
    cout << val << " ";
}
void f()
{
    deque<int> de1, de2;
    for (int i = 0; i < 10; i++)
    {
        de1.push_back(i);
        de2.push_front(i * 10);
    }
    for_each(de1.begin(), de1.end(), myprint);
    cout << endl;
    for_each(de2.begin(), de2.end(), myprint);
    cout << endl;

    swap(de1, de2);
    for_each(de1.begin(), de1.end(), myprint);
    cout << endl;
    for_each(de2.begin(), de2.end(), myprint);
    cout << endl;
}
int main()
{
    f();
    return 0;
}