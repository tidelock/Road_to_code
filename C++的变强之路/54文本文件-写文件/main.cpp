#include <iostream>
#include <fstream>
using namespace std;

void f()
{
    fstream ofs;
    int a = 100;
    string s = "dfjkaj";
    ofs.open("text.txt", ios::out);
    ofs << a << endl;
    ofs << s << endl;
    ofs << "他穿过冷漠人群" << endl;
    ofs << "像光斑落在阴暗的舞台上" << endl;
    ofs << "像明辉陷入阴影" << endl;
    ofs << "像努力寻求真理的精灵" << endl;
    ofs << "像那传道者，也未能找到它的踪影" << endl;
    ofs.close();
}

int main()
{
    f();
    return 0;
}