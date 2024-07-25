#include <iostream>
#include <fstream>
using namespace std;

class person
{
public:
    char name[10];
    int age;
};

void f()
{
    person p = {"张三", 19};
    ofstream ofp;
    ofp.open("text.txt", ios::out | ios::binary); // 用或运算符表示写入和二进制
    ofp.write((const char *)&p, sizeof(p));
    ofp.close();
}

int main()
{
    f();
    return 0;
}