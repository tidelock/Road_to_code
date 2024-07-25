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
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(40);
    for_each(v.begin(), v.end(), myprint);
    cout << endl;

    replace(v.begin(), v.end(), 30, 666); // 把范围内所有的30改为666
    for_each(v.begin(), v.end(), myprint);
}
int main()
{
    f();
    return 0;
}