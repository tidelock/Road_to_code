#include <iostream>
using namespace std;
#include <vector>
void f()
{
    vector<int> v;
    v.resize(10);

    // 主要是用于后期填充的
    // 开始可以用  v.assign(10,666);
    fill(v.begin(), v.end(), 100);
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    f();
    return 0;
}