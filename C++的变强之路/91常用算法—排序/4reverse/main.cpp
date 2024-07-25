#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include<ctime>

void myprint(int val)
{
    cout << val << " ";
}
void f()
{
    vector<int> v;
    srand((unsigned int)time(NULL));
    int i = 10;
    while (i--)
    {
        v.push_back(rand() % 5);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    // 反转序列
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
}
int main()
{
    f();
    return 0;
}