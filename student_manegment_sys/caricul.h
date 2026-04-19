#ifndef CARICUL_H
#define CARICUL_H
#include <bits/stdc++.h>
#include "personal.h"
using namespace std;
struct Subject
{
    int hindi = 0;
    int english = 0;
    int maths = 0;
    int physics = 0;
    int chymistry = 0;
    int art = 0;
};

class School
{
    // int roll_no;
    string stander;
    struct Subject *subject = (struct Subject *)new Subject();

public:
    School() : stander("") {};
    //   void set_school_detal(deque<pair<int,pair<Student,School>>>&data);
    void set_stander(string st);
    void set_marks(int t1, int t2, int t3, int t4, int t5, int t6);
    string get_stander();
    int get_marks_hindi();
    int get_marks_english();
    int get_marks_maths();
    int get_marks_physics();
    int get_marks_chymistry();
    int get_marks_art();
};
#endif