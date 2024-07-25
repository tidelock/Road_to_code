#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class aaa
{
public:
    int operator()(int val)
    {
        return val + 100;
    }
};

class print
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
    vector<int> v2;
    v2.resize(v.size());//注意要提前开辟空间，，好像也可以用reserve（）
    transform(v.begin(), v.end(), v2.begin(), aaa());
    for_each(v2.begin(), v2.end(), print());
}
int main()
{
    f();
    return 0;
}