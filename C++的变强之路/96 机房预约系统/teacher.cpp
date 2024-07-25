#include "teacher.h"
#include "student.h"

void teacher::doteacher()
{

    int choice;
    this->signin();
    while (1)
    {
        menu();
        cout << "请输入你的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
        }
    }
}

void teacher::signin()
{
    string num, num1, name, name1, password, password1;
    fstream ifs;
    ifs.open("teacherifo.txt", ios::in);
    if (ifs.fail())
    {
        cout << "文件打开失败，请重新输入" << endl;
        return;
    }
    else
    {
        while (ifs >> num1 && ifs >> name1 && ifs >> password1)
        {
            cout << "请输入你的学号" << endl;
            cin >> num;
            cout << "请输入你的姓名" << endl;
            cin >> name;
            cout << "请输入你的密码" << endl;
            cin >> password;
            if (num == num1 && name == name1 && password == password1)
            {
                this->teanum = num;
                this->name = name;
                this->teapassword = password;
                cout << "您已成功登录" << endl;
                break;
                // system("pause");
            }
            else
            {
                cout << "输入信息有误，请重新输入" << endl;
                continue;
            }
        }
    }
}

void teacher::menu()
{
    cout << "1、查看所有预约" << endl;
    cout << "2、审核预约" << endl;
    cout << "3、注销登陆" << endl;
}
 char myorder[5][2][3];
void teacher::alloppo()
{
    int i, a, b;
   
    string day[5] =
        {
            "星期一",
            "星期二",
            "星期三",
            "星期四",
            "星期五",
        },
           halfday[2] = {"上午", "下午"},
           room[3] = {"一", "二", "三"};
    string check;
    ifstream ifs("checkstate.txt", ios::in);
    ifs >> check;
    cout << "你的预约记录如下：" << endl;
    int num = 1;

    ifs.open("myorder.txt");
    if (ifs.fail())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    else
    {
        char a1, a2, a3;
        for (int a = 0; a < 5; a++)
            for (int b = 0; b < 2; b++)
            {
                if (ifs >> a1 && ifs >> a2 && ifs >> a3)
                {
                    myorder[a][b][0] = a1;
                    myorder[a][b][1] = a2;
                    myorder[a][b][2] = a3;
                }
            }
    }

    for (a = 0; a < 5; a++)
        for (b = 0; b < 2; b++)
            for (i = 0; i < 3; i++)
                if (myorder[a][b][i] == '1')
                {
                    cout << num << "\t姓名：" << this->name
                         << "\t预约时段：" << day[a] << halfday[b]
                         << "\t预约机房：机房" << room[i]
                         << "\t审核状态：" << check << endl;
                    num++;
                }
}

void teacher::check()
{
     int choice, i = 0, a = 0, b = 0;
    cout << "需审核的情况如下" << endl;
    alloppo();
    cout << "请选择审核的编号" << endl;
    cin >> choice;
    while (1)
    {
        for (a = 0; a < 5; a++)
        {
            for (b = 0; b < 2; b++)
            {
                for (i = 0; i < 3; i++)
                    if (myorder[a][b][i] == '1' && --choice == 0)
                    {
                        myorder[a][b][i] = '0';
                        break;
                    }
                break;
            }
            break;
        }
        break;
    }
    ofstream ofs("myorder.txt", ios::out);
    for (a = 0; a < 5; a++)
        for (b = 0; b < 2; b++)
        {
            ofs << myorder[a][b][0] << ' ' << myorder[a][b][1] << ' ' << myorder[a][b][2] << ' ' << endl;
        }
    ofs.close();
    cout << "你的预约已经取消" << endl;
}