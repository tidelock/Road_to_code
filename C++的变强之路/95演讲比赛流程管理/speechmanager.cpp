#include "speechmanager.h"
#include <algorithm>
#include<fstream>
manager::manager()
{
}
manager::~manager()
{
}
bool aaa::operator()(speecher sp1, speecher sp2)
{
    return sp1.score > sp2.score;
}
void manager::showmenu()
{
    cout << "----------------------------------" << endl;
    cout << "--------- 欢迎参加演讲比赛 --------" << endl;
    cout << "--------- 1、开始演讲比赛 ---------" << endl;
    cout << "--------- 2、查看往届记录 ---------" << endl;
    cout << "--------- 3、清空比赛记录 ---------" << endl;
    cout << "--------- 4、退出比赛程序 ---------" << endl;
    cout << "----------------------------------" << endl;
}

void manager::begin_detail(int num)
{
    int i;
    map<int, string> m;
    m.insert(make_pair(1, "一"));
    m.insert(make_pair(2, "二"));
    cout << "第" << m.at(num) << "轮比赛正式开始" << endl;
    for (i = 0; i < 12 / num; i++)
    {
        v1.at(i).score = rand() % 100;
    }
    sort(v1.begin(), v1.end(), aaa());
    for (i = 0; i < 12 / num; i++)
    {
        cout << "姓名：" << v1.at(i).name << "   成绩：" << v1.at(i).score << endl;
    }
    cout << "前" << 6 / num << "名将晋级" << endl;
}
void manager::begin()
{
    int i;
    v1.resize(12);
    v1.clear();
    victory.clear();
    m.clear();
    for (i = 0; i < 12; i++)
    {
        v1.push_back(sp[i]);
    }
    begin_detail(1);//第一轮
    v1.resize(6);
    system("pause");
    begin_detail(2);//第二轮
    system("pause");
    cout << "获胜名单是" << endl;
    for (i = 0; i < 3; i++)
    {
        cout << "姓名：" << v1.at(i).name << "   成绩：" << v1.at(i).score << endl;
    }
    ofstream ofs;//将前三名记录在文本中
    ofs.open("record.txt", ios::app);
    for(int i=0;i<3;i++)
    {
        ofs<<v1.at(i).name<<" "<<v1.at(i).score<<endl;
    }
     ofs<<"-----------------------"<<endl;
     ofs.close();
}

void manager::exitmanager()
{
    cout << "欢迎下次使用本系统" << endl;
   system("pause");
   exit(0);
}

void manager::createspeecher()
{

    string s = "ABCDEFGHIJKL";
    for (int i = 0; i < 12; i++)
    {
        sp[i].name = "选手";
        sp[i].name += s[i];
    }
}

void manager::prematch()
{
    fstream ifs;
    ifs.open("record.txt", ios::in);
    string s;
   while(getline(ifs,s))
   {
    cout <<s<<endl;
   }
}

void manager::clearall()
{
    fstream ofs;
    ofs.open("record.txt",ios::out);
    ofs.close();
    cout <<"比赛记录已经清空"<<endl;
}