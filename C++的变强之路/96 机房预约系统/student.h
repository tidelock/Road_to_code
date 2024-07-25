#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class student
{
public:
    student();
    void dostudent();
    void menu();
    void signin();

    void makeappo();
    void myappo();
    void allappo();
    void cancelappo();

    string name;
    string stunum;
    string stupassword;

    int allorder[5][2][3]={0};
     char myorder[5][2][3]={0};
};