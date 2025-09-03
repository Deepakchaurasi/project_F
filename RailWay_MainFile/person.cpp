#include <bits/stdc++.h>
#include "person.h"
#include "ticket.h"

using namespace std;

void Person::setpid(int person_count)
{
    this->pid = to_string(person_count) + this->bearth;
    return;
}
void Person::setName(std::string n)
{
    this->name = n;
    return;
}
void Person::setGender(char g)
{
    this->gender = g;
    return;
}
void Person::setAge(int a)
{
    this->age = a;
    return;
}
void Person::setBearth(char b)
{
    this->bearth = b;
    return;
}
string Person::getpid()
{
    return this->pid;
}
string Person::getName()
{
    return this->name;
}
char Person::getGender()
{
    return this->gender;
}
int Person::getAge()
{
    return this->age;
}
char Person::getBearth()
{
    return this->bearth;
}