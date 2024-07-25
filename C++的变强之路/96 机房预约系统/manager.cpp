#include "manager.h"

void manager::signin()
{
    cout << "\t\t--------------------------------" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|       欢迎使用机房预约系统   |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|         1、学生登陆          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|         2、老师登陆          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|         3、管理员登陆        |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t--------------------------------" << endl;
    cout << "请输入您要执行的选项" << endl;
}

void manager::manu()
{
    cout << "1、添加账号" << endl;
    cout << "2、查看账号" << endl;
    cout << "3、查看机房" << endl;
    cout << "4、清空预约" << endl;
    cout << "5、注销登陆" << endl;

    cout << "请输入您要执行的选项" << endl;
}

void manager::domanager()
{

    int choice = 1;

    while (1)
    {
        manu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            lookup();
            break;
        case 3:
            lookupappo();
            break;
        case 4:
            deleteappo();
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

void manager::add()
{
    int a;
    student stu;
    teacher tea;
    fstream ofs;

    cout << "请输入你要添加的成员" << endl;
    cout << "1、老师" << endl;
    cout << "2、学生" << endl;
    cin >> a;
    if (a == 1)
    {
        cout << "请输入老师的职工号：" << endl;
        cin >> tea.teanum;
        cout << "请输入老师的姓名：" << endl;
        cin >> tea.name;
        cout << "请输入老师的密码：" << endl;
        cin >> tea.teapassword;
        ofs.open("teacherifo.txt", ios::app);
        ofs << "职工号：" << tea.teanum << "\t姓名："
            << tea.name << "\t密码：" << tea.teapassword << endl;
        ofs.close();
    }
    else if (a == 2)
    {
        cout << "请输入学生的学号：" << endl;
        cin >> stu.stunum;
        cout << "请输入学生的姓名：" << endl;
        cin >> stu.name;
        cout << "请输入学生的密码：" << endl;
        cin >> stu.stupassword;
        ofs.open("studentifo.txt", ios::app);
        ofs << stu.stunum << " " << stu.name << " " << stu.stupassword << endl;
        ofs.close();
    }
    else
    {
        cout << "输入错误，请重新输入" << endl;
    }
    cout << "信息录入完毕" << endl;
}

void manager::lookup()
{
    int choice;
    ifstream ifs;

    cout << "请输入你要查看的成员" << endl;
    cout << "1、老师" << endl;
    cout << "2、学生" << endl;
    cin >> choice;
    if (choice == 1)
    {
        ifs.open("teacherifo.txt", ios::in);
        string s;
        while (getline(ifs, s))
        {
            cout << s;
        }
        ifs.close();
    }
    else if (choice == 2)
    {
        ifs.open("studentifo.txt", ios::in);
        string s;
        while (getline(ifs, s))
        {
            cout << s << endl;
        }
        ifs.close();
    }
    else
        cout << "输入错误，请重新输入" << endl;
}

void manager::lookupappo()
{
    fstream ifs;
    ifs.open("appointment.txt", ios::in);
    string s;
    while (getline(ifs, s))
    {
        cout << s << endl;
    }
}

void manager::deleteappo()
{
    fstream ifs;
    ifs.open("appointment.txt", ios::out);
    ifs.close();
}
