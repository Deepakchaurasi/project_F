#ifndef PERSON_H
#define PERSON_H
#include <bits/stdc++.h>
#pragma once
using namespace std;

class Person
{
private:
    string pid;
    string name;
    char gender;
    int age;
    char bearth;

public:
    Person() : name(""), age(0), pid(""), gender(' '), bearth(' ') {}

    void setpid(int p);
    void setName(std::string n);
    void setGender(char g);
    void setAge(int a);
    void setBearth(char b);

    std::string getpid();
    int getAge();
    std::string getName();
    char getGender();
    char getBearth();
};
#endif