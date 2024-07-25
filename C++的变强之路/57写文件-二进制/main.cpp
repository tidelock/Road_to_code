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
    ifstream ifp("text.txt", ios::in | ios::binary);
    person p;
    ifp.read((char *)&p, sizeof(p));
    cout << p.name << p.age << endl;
    ifp.close();
}
int main()
{
    f();
    return 0;
}