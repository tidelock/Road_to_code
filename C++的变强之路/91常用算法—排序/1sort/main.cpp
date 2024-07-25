#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

void myprint(int val)
{
    cout << val << " ";
}
void f()
{
    vector<int> v;
    int i = 10;
    while (i--)
    {
        v.push_back(rand() % 5);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;

    // 升序排列
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    // 降序排列
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
}
int main()
{
    f();
    return 0;
}