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

    vector<int> v2;
    v2.resize(v.size());//注意提前规划好空间
    copy(v.begin(), v.end(), v2.begin());//其实没什么用，了解即可
    for_each(v2.begin(), v2.end(), myprint);
}
int main()
{
    f();
    return 0;
}