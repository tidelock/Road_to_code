#pragma once
#include <iostream>
#include <string>
using namespace std;

class worker
{
public:
    int num;     // 序号
    string name; // 名字
    int job;     // 工作
    virtual void showifo() = 0;
    virtual string getduty() = 0;
};

class boss : public worker
{
public:
    boss(int a, string b, int c);
    void showifo();
    string getduty();
};

class manager : public worker
{
public:
    manager(int a, string b, int c);
    void showifo();
    string getduty();
};

class employee : public worker
{
public:
    employee(int a, string b, int c);
    void showifo();
    string getduty();
};