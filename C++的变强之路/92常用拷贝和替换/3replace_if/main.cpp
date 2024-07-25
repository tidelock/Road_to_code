#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <ctime>

void myprint(int val)
{
    cout << val << " ";
}
class aaa
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
void f()
{
    vector<int> v;
    srand((unsigned int)time(NULL));
    int i = 10;
    while (i--)
    {
        v.push_back(rand() % 10);
    }
    for_each(v.begin(), v.end(), myprint);
    cout << endl;

    replace_if(v.begin(), v.end(), aaa(), 666);//把参数的位置记住就好了
    for_each(v.begin(), v.end(), myprint);
}
int main()
{
    f();
    return 0;
}