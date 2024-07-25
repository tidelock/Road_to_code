#include <iostream>
#include "speechmanager.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    manager sm;
    int choice = 1;
    sm.createspeecher();
    while (choice)
    {
        sm.showmenu();
        cout << "请输入你要执行的操作" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // 开始演讲比赛
        {
            sm.begin();
            break;
        }
        case 2: // 查看往届记录
        {
            sm.prematch();
            break;
        }
        case 3: // 清空比赛记录
        {
            sm.clearall();
            break;
        }
        case 4: // 退出比赛程序
        {
            sm.exitmanager();
            break;
        }
        default:
            system("cls");
        }
        system("pause");
        system("cls");
    }
    system("pause");
}