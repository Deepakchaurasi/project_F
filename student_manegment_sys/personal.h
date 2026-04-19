#ifndef PERSONAL_H
#define PERSONAL_H
#include <bits/stdc++.h>
#include <string>
#include "caricul.h"
using namespace std;
class Student
{
private:
    int roll_no;
    int age;
    string name;
    string gender;
    string father_name;
    string mother_name;
    string address;
    long int contect_no;

public:
    Student() : roll_no(0), age(0), name(""), gender(""), father_name(""), mother_name(""), address(""), contect_no(0) {};
    // void set_student_detale(deque<pair<int, pair<Student, School>>> &data);

    void set_roll(int r);
    void set_name(string name);
    void set_age(int num);
    void set_gender(string gd);
    void set_f_name(string fm);
    void set_m_name(string mn);
    void set_numb(long int lg);
    void set_address(string addr);
    int get_roll() const;
    string get_name() const;
    int get_age() const;
    string get_gender() const;
    string get_f_name() const;
    string get_m_name() const;
    long int get_numb() const;
    string get_address() const;
};
#endif