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
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;
    // 把指定范围的顺序打乱
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), myprint);
}
int main()
{
    f();
    return 0;
}