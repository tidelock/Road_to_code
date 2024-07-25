#pragma once
#include <iostream>
#include "class.h"
#include <fstream>
#include <string>
using namespace std;

class workermanager
{
public:
    workermanager();
    ~workermanager();

    void showmenu();
    void save();
    void addifo();
    int get_workernum();
    void initworker();
    void showifom();
    void modify();
    void lookup();
    void rank();
    void clearall();

    void deleteworker();
    int exist(int i);

    worker **m_worker;
    int workernum;
    bool fileisempty;
};