
#include <bits/stdc++.h>
using namespace std;
#include "personal.h"
void Student::set_roll(int r)
{
    this->roll_no = r;
    return;
}
void Student::set_gender(string gd)
{
    this->gender = gd;
    return;
}
void Student::set_name(string n)
{
    this->name = n;
    return;
}
void Student::set_age(int ag)
{
    this->age = ag;
    return;
}
void Student::set_f_name(string nam)
{
    this->father_name = nam;
    return;
}
void Student::set_m_name(string nam)
{
    this->mother_name = nam;
    return;
}
void Student::set_address(string addr)
{
    this->address = addr;
    return;
}
void Student::set_numb(long int mo)
{
    this->contect_no = mo;
    return;
}
int Student::get_roll() const
{
    return this->roll_no;
}
string Student::get_name() const
{
    return this->name;
}
int Student::get_age() const
{
    return this->age;
}
string Student::get_gender() const
{
    return this->gender;
}
string Student::get_f_name() const
{
    return this->father_name;
}
string Student::get_m_name() const
{
    return this->mother_name;
}
long int Student::get_numb() const
{
    return this->contect_no;
}
string Student::get_address() const
{
    return this->address;
}