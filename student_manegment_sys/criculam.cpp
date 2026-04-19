#include <bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <conio.h>
#include "caricul.h"
void School::set_stander(string st)
{
    this->stander = st;
    return;
}
void School::set_marks(int hindi, int engl, int maths, int phy, int chy, int art)
{
    this->subject->hindi = hindi;
    this->subject->english = engl;
    this->subject->maths = maths;
    this->subject->physics = phy;
    this->subject->chymistry = chy;
    this->subject->art = art;
    return;
}
string School::get_stander()
{
    return this->stander;
}
int School::get_marks_hindi()
{
    return this->subject->hindi;
}
int School::get_marks_english()
{
    return this->subject->english;
}
int School::get_marks_maths()
{
    return this->subject->maths;
}
int School::get_marks_physics()
{
    return this->subject->physics;
}
int School::get_marks_chymistry()
{
    return this->subject->chymistry;
}
int School::get_marks_art()
{
    return this->subject->art;
}