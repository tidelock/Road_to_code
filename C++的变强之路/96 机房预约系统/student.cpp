#include "student.h"

student::student()
{
    int i;
    fstream ifs;
    fstream ofs;
    ifs.open("myorder.txt", ios::in);
    if (ifs.fail())
    {
        ofs.open("myorder.txt", ios::out);
        int a, b;
        for (a = 0; a < 5; a++)
            for (b = 0; b < 2; b++)
            {
                ofs << '0' << ' ' << '0' << ' ' << '0' << ' ' << endl;
            }
        ofs.close();
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
    ifs.close();

    ifs.open("allorder.txt", ios::in);
    if (ifs.fail())
    {
        ofs.open("allorder.txt", ios::out);

        int a, b;
        for (a = 0; a < 5; a++)
            for (b = 0; b < 2; b++)
            {
                ofs << 0 << ' ' << 0 << ' ' << 0 << ' ' << endl;
            }

        ofs.close();
    }
    else
    {
        int a1, a2, a3;
        for (int i1 = 0; i1 < 5; i1++)
        {
            for (int i2 = 0; i2 < 2; i2++)
            {
                if (ifs >> a1 && ifs >> a2 && ifs >> a3)
                {
                    allorder[i1][i2][0] = a1;
                    allorder[i1][i2][1] = a2;
                    allorder[i1][i2][2] = a3;
                }
            }
        }
    }
    ifs.open("checkstate.txt", ios::in);
    if (ifs.fail())
    {
        ofs.open("checkstate.txt", ios::out);
        ofs << "未审核";
        ofs.close();
    }
    ifs.close();
}

void student::signin()
{
    string num, num1, name, name1, password, password1;

    fstream ifs;
    ifs.open("studentifo.txt", ios::in);
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
                this->stunum = num;
                this->name = name;
                this->stupassword = password;
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

void student::dostudent()
{
    int choice = 1;
    signin();
    while (1)
    {
        cout << endl;
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            makeappo();
            break;
        case 2:
            myappo();
            break;
        case 3:
            allappo();
            break;
        case 4:
            cancelappo();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }
        // system("pause");
        // system("cls");
    }
}

void student::menu()
{
    cout << "1、申请预约" << endl;
    cout << "2、查看预约" << endl;
    cout << "3、所有预约" << endl;
    cout << "4、取消预约" << endl;
    cout << "5、注销登陆" << endl;
    cout << "请输入您要执行的选项" << endl;
}

void student::makeappo()
{
    int choice1, choice2, choice3;
    allappo();
    cout << "请选择预约的时段" << endl;
    cout << "1、星期一" << endl;
    cout << "2、星期二" << endl;
    cout << "3、星期三" << endl;
    cout << "4、星期四" << endl;
    cout << "5、星期五" << endl;

    while (1)
    {
        cin >> choice1;
        if (choice1 > 0 && choice1 < 6)
        {
            cout << "1、上午" << endl;
            cout << "2、下午" << endl;

            while (1)
            {
                cin >> choice2;
                if (choice2 > 0 && choice2 < 3)
                {
                    cout << "1、机房一" << endl;
                    cout << "2、机房二" << endl;
                    cout << "3、机房三" << endl;
                    cout << "请选择预约的机房" << endl;

                    while (1)
                    {
                        cin >> choice3;
                        int t = choice3 = 1 ? 150 : 50;
                        if (myorder[choice1 - 1][choice2 - 1][choice3 - 1] > t)
                        {
                            cout << "该预约机房已满，请重新输入" << endl;
                            continue;
                        }
                        if (choice3 > 0 && choice3 < 4)
                        {
                            myorder[choice1 - 1][choice2 - 1][choice3 - 1] = '1';
                            allorder[choice1 - 1][choice2 - 1][choice3 - 1]++;
                            break;
                        }
                        else
                            cout << "输入错误，请重新输入" << endl;
                    }

                    break;
                }
                else
                    cout << "输入错误，请重新输入" << endl;
            }
            break;
        }
        else
            cout << "输入错误，请重新输入" << endl;
    }

    fstream ofs;
    ofs.open("myorder.txt", ios::out);
    for (int a = 0; a < 5; a++)
        for (int b = 0; b < 2; b++)
        {
            ofs << myorder[a][b][1] << ' ' << myorder[a][b][2] << ' ' << myorder[a][b][3] << endl;
        }
    ofs.close();

    ofs.open("allorder.txt", ios::out);
    for (int i1 = 0; i1 < 5; i1++)
    {
        for (int i2 = 0; i2 < 2; i2++)
        {
            for (int i3 = 0; i3 < 3; i3++)
            {
                ofs << allorder[i1][i2][i3] << ' ';
            }
            ofs << endl;
        }
    }
    ofs.close();
    cout << "预约成功" << endl;
}

void student::myappo()
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

void student::allappo()
{
    int a = 0, b = 0;
    string day[5] =
        {
            "星期一",
            "星期二",
            "星期三",
            "星期四",
            "星期五",
        },
           halfday[2] = {"上午", "下午"};
    cout << "当前时段机房的预约人数如下" << endl;
    ifstream ifs("allorder.txt", ios::in);
    int num1, num2, num3;

    while (ifs >> num1 && ifs >> num2 && ifs >> num3)
    {

        cout << day[a] << halfday[b]
             << "  机房一: " << num1 << "/150"
             << "  机房二: " << num2 << "/50"
             << "  机房三: " << num3 << "/50" << endl;

        b++;
        if (b == 2)
        {
            a++;
            b = 0;
        }
    }
}

void student::cancelappo()
{
    int choice, i = 0, a = 0, b = 0;
    cout << "您的预约记录如下：" << endl;
    myappo();
    cout << "请选择你要取消的预约" << endl;
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
                        allorder[a][b][i]--;
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