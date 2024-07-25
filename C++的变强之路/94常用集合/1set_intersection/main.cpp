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
        v2.push_back(i * 2);//注意两个序列都是有序序列
    }

    vector<int> vtarget;
    vtarget.resize(min(v1.size(), v2.size()));
    vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
    //求交集运算中，返回的是指向交集数据的最后一个的迭代器，因为刚开始resize的时候是特殊情况，空间可能大了
    for_each(vtarget.begin(), itend, myprint);
    cout << endl;
}
int main()
{
    f();
    return 0;
}