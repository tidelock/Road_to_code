#pragma once
#include <iostream>

template <class T1, class T2>
class person
{
public:
    person(T1 name, T2 age);
    T1 name;
    T2 age;
    void show();
};

template <class T1, class T2>
person<T1, T2>::person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template <class T1, class T2>
void person<T1, T2>::show()
{
    cout << "名字：" << this->name << "     年龄：" << this->age << endl;
}