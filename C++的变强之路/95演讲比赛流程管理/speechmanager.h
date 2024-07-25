#pragma once
#include <iostream>
#include<vector>
#include<map>
using namespace std;

class speecher
{
public:
    string name;
    double score;
};

class aaa
{
    public:
    bool operator()(speecher sp1,speecher sp2);
};

class manager
{
public:
    manager();
    ~manager();

  speecher sp[12];


vector<speecher>v1;//第一轮12个人
map<int,speecher>m;//存放选手及编号

    void showmenu();
    void begin();
    void begin_detail(int num);
    void prematch();
    void clearall();
    void exitmanager();

    void createspeecher();
};