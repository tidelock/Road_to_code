#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void print01(int val)
{
    cout << val << " ";
}

class print02
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }
};
void f()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), print01); // 普通函数不要括号
    cout << endl;
    for_each(v.begin(), v.end(), print02()); // 仿函数要括号
}
int main()
{
    f();
    return 0;
}