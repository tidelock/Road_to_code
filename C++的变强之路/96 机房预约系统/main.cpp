#include <iostream>
#include "student.h"
#include "teacher.h"
#include "manager.h"

using namespace std;

int main()
{
    manager m;
    student s;
    teacher t;
    m.signin();
    int choice = 1;

    while (choice)
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            s.dostudent();
            break;
        case 2:
            t.doteacher();
            break;
        case 3:
            m.domanager();
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
    system("pause");
    return 9;
}