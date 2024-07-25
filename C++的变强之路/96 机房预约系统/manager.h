#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include<string>
#include "student.h"
#include "teacher.h"

using namespace std;

class manager
{
public:
    void domanager();
    void signin();
    void manu();

    void add();
    void lookup();
    void lookupappo();
    void deleteappo();

    private:


   // map<int, student> m;
};