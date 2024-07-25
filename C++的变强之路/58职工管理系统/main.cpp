#include <iostream>
#include <string>
#include "class.h"
#include "Workermanager.h"
using namespace std;

int main()
{

    workermanager wm;
    int choice = 1;
    while (choice)
    {
        wm.showmenu();
        cout << "请输入你要执行的操作：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "欢迎下次使用该系统" << endl;
            system("pause");
            break;
        case 1:
            wm.addifo();
            break;
        case 2:
            wm.showifom();
            break;
        case 3:
            wm.deleteworker();
            break;
        case 4:
            wm.modify();
            break;
        case 5:
            wm.lookup();
            break;
        case 6: wm.rank();
            break;
        case 7: wm.clearall();
            break;
        default:
            cout << "您的输入有误，请重新输入" << endl;
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}