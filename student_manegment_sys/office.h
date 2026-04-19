#ifndef OFFICE_H
#define OFFICE_H
#include <bits/stdc++.h>
using namespace std;
#include "personal.h"
#include "caricul.h"
class Office
{
public:
    void set_student_detale(deque<pair<int, pair<Student, School>>> &data);
    void print_student_detale(int rool, deque<pair<int, pair<Student, School>>> &data);
    void set_update_detale(deque<pair<int, pair<Student, School>>> &data);
    void set_update_school(deque<pair<int, pair<Student, School>>> &data);
    void delete_student_detale(deque<pair<int, pair<Student, School>>> &data);
    void print_student_school(int rool, deque<pair<int, pair<Student, School>>> &data);
};
#endif