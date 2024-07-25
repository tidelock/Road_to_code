#include <iostream>
using namespace std;
#include <numeric>//注意是新的头文件了
#include <vector>
void f()
{
    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        v.push_back(i);
    }
    cout << accumulate(v.begin(), v.end(), 0) << endl;//0的意思就是加完后再加个0

    vector<char> v2;
    v2.push_back('p');
    v2.push_back('d');
    cout <<(char)( accumulate(v2.begin(), v2.end(), 0)-'a') << endl;
}
int main()
{
    f();
    return 0;
}