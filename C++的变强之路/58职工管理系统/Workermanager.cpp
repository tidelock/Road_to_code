#include "Workermanager.h"
#include "class.h"

workermanager::workermanager()
{

    ifstream ifs;
    ifs.open("infomation.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        workernum = 0;
        m_worker = NULL;
        fileisempty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {

        cout << "文件打开成功，但里面没有数据" << endl;
        workernum = 0;
        m_worker = NULL;
        fileisempty = true;
        ifs.close();
        return;
    }

    cout << "文件共存在" << get_workernum() << "个人的数据" << endl;
    workernum = get_workernum();

    m_worker = new worker *[this->workernum];
    this->initworker();
    // for (int i = 0; i < workernum; i++)
    // {
    //     cout << this->m_worker[i]->num << " "
    //          << this->m_worker[i]->name << " "
    //          << this->m_worker[i]->job << endl;
    // }
}

workermanager::~workermanager()
{
    if (m_worker != NULL)
    {
        for (int i = 0; i < workernum; i++)
        {
            delete m_worker[i];
            m_worker[i] = NULL;
        }
        delete[] this->m_worker;
    }
}

int workermanager::get_workernum() // 获知文件里都有几个人
{
    ifstream ifs("infomation.txt", ios::in);
    int num = 0;

    int id;
    string name;
    int job;
    while (ifs >> id && ifs >> name && ifs >> job)
    {
        num++;
    }
    return num;
}

void workermanager::showmenu()
{
    cout << "---------------------------------------" << endl;
    cout << "---------欢迎使用职工管理系统----------" << endl;
    cout << "-----------0、退出管理程序-------------" << endl;
    cout << "-----------1、增加职工信息-------------" << endl;
    cout << "-----------2、显示职工信息-------------" << endl;
    cout << "-----------3、删除离职职工-------------" << endl;
    cout << "-----------4、修改职工信息-------------" << endl;
    cout << "-----------5、查找职工信息-------------" << endl;
    cout << "-----------6、按照编号排序-------------" << endl;
    cout << "-----------7、清空所有文档-------------" << endl;
    cout << "---------------------------------------" << endl
         << endl;
}

void workermanager::save()
{
    ofstream ofs("infomation.txt", ios::out);

    for (int i = 0; i < workernum; i++)
    {
        ofs << this->m_worker[i]->num << " "
            << this->m_worker[i]->name << " "
            << this->m_worker[i]->job << endl;
    }
    ofs.close();
}

void workermanager::addifo()
{
    int addnum;
    cout << "请输入你要添加的人数" << endl;
    cin >> addnum;
    if (addnum > 0)
    {
        int newsize = this->workernum + addnum;
        worker **newspace = new worker *[newsize];
        if (m_worker != NULL)
        {
            for (int i = 0; i < workernum; i++)
            {
                newspace[i] = m_worker[i];
            }
        }
        for (int i = 0; i < addnum; i++)
        {
            int id;
            string name;
            int dselect;

            cout << "请输入第" << i + 1 << "个职工的编号" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
            cin >> name;
            cout << "请输入第" << i + 1 << "个职工的部门" << endl;
            cout << "1、老板" << endl;
            cout << "2、经理" << endl;
            cout << "3、打工人" << endl;
            cin >> dselect;

            worker *w = NULL;
            switch (dselect)
            {
            case 1:
                w = new boss(id, name, 1);
                break;
            case 2:
                w = new manager(id, name, 2);
                break;
            case 3:
                w = new employee(id, name, 3);
                break;
            }
            newspace[this->workernum + i] = w;
        }
        delete[] m_worker;
        m_worker = newspace;
        workernum = newsize;
        cout << "成功添加" << addnum << "名员工" << endl;
        save();
        this->fileisempty = false;
    }
    else
        cout << "输入有误，请重新输入" << endl;
}

void workermanager::initworker()
{
    ifstream ifs("infomation.txt", ios::in);
    int num = 0;
    int id;
    string name;
    int job;
    while (ifs >> id && ifs >> name && ifs >> job)
    {
        worker *w = NULL;
        if (job == 1)
            w = new boss(id, name, job);
        else if (job == 2)
            w = new manager(id, name, job);
        else if (job == 3)
            w = new employee(id, name, job);
        m_worker[num] = w;
        num++;
    }
    ifs.close();
}

void workermanager::showifom()
{
    if (fileisempty)
        cout << "文件不存在或为空" << endl;
    else
        for (int i = 0; i < workernum; i++)
            this->m_worker[i]->showifo();
}

int workermanager::exist(int i)
{
    for (int a = 0; a < workernum; a++)
        if (m_worker[a]->num == i)
            return a;
    return -1;
}

void workermanager::deleteworker()
{
    if (fileisempty == true)
        cout << "文件不存在或文件为空" << endl;
    else
    {
        cout << "请输入你要删除的编号" << endl;
        int a;
        cin >> a;
        if (exist(a) != -1)
        {
            for (int i = a; i < workernum - 1; i++)
            {
                m_worker[i] = m_worker[i + 1];
            }
            workernum--;
            save();
            cout << "删除成功" << endl;
        }
        else
            cout << "该编号不存在" << endl;
    }
}

void workermanager::modify()
{
    if (this->fileisempty == true)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        cout << "请输入你要更改的员工编号" << endl;
        int a;
        cin >> a;
        int ret = exist(a);
        if (ret != -1)
        {
            delete m_worker[ret];

            int newid;
            string newname;
            int newjob;

            cout << "请输入更改后的员工编号" << endl;
            cin >> newid;
            cout << "请输入更改后的员工姓名" << endl;
            cin >> newname;
            cout << "请输入更改后的员工岗位" << endl;
            cout << "1、老板" << endl;
            cout << "2、经理" << endl;
            cout << "3、工人" << endl;
            cin >> newjob;

            worker *p = NULL;
            switch (newjob)
            {
            case 1:
                p = new boss(newid, newname, newjob);
                break;
            case 2:
                p = new manager(newid, newname, newjob);
                break;
            case 3:
                p = new employee(newid, newname, newjob);
                break;
            }
            m_worker[ret] = p;
            cout << "已修改成功" << endl;
            this->save();
        }
        else
            cout << "该编号不存在 " << endl;
    }
}

void workermanager::lookup()
{
    if (fileisempty == true)
        cout << "文件为空或不存在" << endl;
    else
    {
        cout << "请输入你要查找的类型" << endl;
        cout << "1、按编号查找" << endl;
        cout << "2、按名字查找" << endl;
        int a = 0, i = 0;
        cin >> a;
        if (a == 1)
        {
            cout << "请输入你要查找的编号" << endl;
            cin >> a;
            while (m_worker[i]->num != a)
            {
                i++;
                if (i == workernum)
                {
                    cout << "编号不存在，请重新输入" << endl;
                    cin >> a;
                    i = 0;
                }
            }
        }
        else if (a == 2)
        {
            cout << "请输入你要查找的姓名" << endl;
            string tempname;
            cin >> tempname;
            while (m_worker[i]->name != tempname)
            {
                i++;
                if (i == workernum)
                {
                    cout << "名字不存在，请重新输入" << endl;
                    cin >> tempname;
                    i = 0;
                }
            }
        }
        m_worker[i]->showifo();
    }
}

void workermanager::rank()
{
    if (fileisempty == true)
    {
        cout << "文件为空或不存在" << endl;
        return;
    }
    int choice, i;

    cout << "请选择排序类型" << endl;
    cout << "1、升序" << endl;
    cout << "2、降序" << endl;
    cin >> choice;
    if (choice == 1)
    {
        for (i = 0; i < workernum - 1; i++)
        {
            if (m_worker[i]->num >= m_worker[i + 1]->num)
            {
                worker *p = NULL;
                p = m_worker[i];
                m_worker[i] = m_worker[i + 1];
                m_worker[i + 1] = p;
                i = -1;
            }
        }
    }
    else if (choice == 2)
    {
        for (i = 0; i < workernum - 1; i++)
        {
            if (m_worker[i]->num <= m_worker[i + 1]->num)
            {
                worker *p = NULL;
                p = m_worker[i];
                m_worker[i] = m_worker[i + 1];
                m_worker[i + 1] = p;
                i = -1;
            }
        }
    }
    else
        cout << "输入错误，请重新输入" << endl;

    this->save();
    cout << "排序已完成" << endl;
}

void workermanager::clearall()
{
    ofstream ofs("infomation.txt", ios::trunc);
    ofs.close();
    if (m_worker != NULL)
    {
        for (int i = 0; i < workernum; i++)
        {
            delete m_worker[i];
            m_worker[i] = NULL;
        }
        delete[] this->m_worker;
        m_worker = NULL;
        this->workernum = 0;
        this->fileisempty = true;
    }
    cout<<"清空完成！"<<endl;
}