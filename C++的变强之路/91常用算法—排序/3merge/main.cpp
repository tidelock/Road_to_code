#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void myprint(int val)
{
    cout << val << " ";
}
void f()
{
    vector<int> v1, v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i * 2);
    }
    vector<int> vtarget;
    //注意一定要提前分配好空间
    vtarget.resize(v1.size() + v2.size());
    //把两个有序（且是同一种序）合并到另外一个容器中（也是有序）
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
    for_each(vtarget.begin(), vtarget.end(), myprint);
    cout << endl;
}
int main()
{
    f();
    return 0;
}