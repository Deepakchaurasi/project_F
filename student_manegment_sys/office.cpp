#include <bits/stdc++.h>
#include <conio.h>
#include <string>
using namespace std;
#include "personal.h"
#include "office.h"
#include "caricul.h"
Student st;
School sc;
bool is_persent(int r, deque<pair<int, pair<Student, School>>> &data)
{
    for (auto temp : data)
    {
        if (r == temp.first)
        {
            return false;
        }
    }
    return true;
}
void set_student_school(int roll_no, deque<pair<int, pair<Student, School>>> &data)
{
    string sted;
    int temp_h, temp_e, temp_m, temp_p, temp_c, temp_a;
    cout << "enter student stander:" << endl;
    cin >> sted;
    sc.set_stander(sted);
    cout << "enter hindi marks:" << endl;
    cin >> temp_h;
    cout << "enter englis marks:" << endl;
    cin >> temp_e;
    cout << "enter maths marks:" << endl;
    cin >> temp_m;
    cout << "enter physice m...." << endl;
    cin >> temp_p;
    cout << "enter chymistry m....." << endl;
    cin >> temp_c;
    cout << "enter art m..." << endl;
    cin >> temp_a;
    sc.set_marks(temp_h, temp_e, temp_m, temp_p, temp_c, temp_a);
    bool flag = false;
    for (pair<int, pair<Student, School>> &g : data)
    {
        if (roll_no == g.first)
        {
            flag = true;
            g.second.second = sc;
            break;
        }
    }
    if (!flag)
    {
        cout << "pleces fill student persnol detale:" << endl;
    }
    getch();
    return;
}
void Office::set_student_detale(deque<pair<int, pair<Student, School>>> &data)
{
    int num1, num2, roll_no;
    string str;
    long int lo;
    cout << "inter student detale:" << "\n";
    getch();
    cout << "enter student roll_no" << endl;
    cin >> roll_no;
    if (is_persent(roll_no, data) && data.size() > 0)
    {
        cout << "wrong roll_no:";
        return;
    }
    st.set_roll(roll_no);
    cout << "enter student name:" << endl;
    cin >> str;
    st.set_name(str);
    cout << "enter student age:" << endl;
    cin >> num1;
    st.set_age(num1);
    cout << "enter student gender:" << endl;
    cin >> str;
    st.set_gender(str);
    cout << "enter student father name:" << endl;
    cin >> str;
    st.set_f_name(str);
    cout << "enter student mother name:" << endl;
    cin >> str;
    st.set_m_name(str);
    cout << "enter student address with connect -:" << endl;
    cin >> str;
    st.set_address(str);
    cout << "enter student contect number:" << endl;
    cin >> lo;
    st.set_numb(lo);
    data.push_back({roll_no, {st, sc}});
    set_student_school(roll_no, data);
    return;
}

void Office::print_student_detale(int roll_no, deque<pair<int, pair<Student, School>>> &data)
{
    if (is_persent(roll_no, data) && data.size() > 0)
    {
        cout << "wrong roll_no: student not persent :" << "\n";
        getch();
        return;
    }
    else if (data.size() == 0)
    {
        cout << "no student data persent:" << endl;
        getch();
        return;
    }
    for (pair<int, pair<Student, School>> &g : data)
    {
        if (roll_no == g.first)
        {
            cout << "student roll_no:     " << g.first << endl;
            cout << "student name:        " << g.second.first.get_name() << endl;
            cout << "student age:          " << g.second.first.get_age() << endl;
            cout << "student gender:      " << g.second.first.get_gender() << endl;
            cout << "student father name:  " << g.second.first.get_f_name() << endl;
            cout << "student mother name:   " << g.second.first.get_m_name() << endl;
            cout << "student address:       " << g.second.first.get_address() << endl;
            cout << "student contact number: " << g.second.first.get_numb() << endl;
            break;
        }
    }
}
void Office::print_student_school(int roll_no, deque<pair<int, pair<Student, School>>> &data)
{
    if (is_persent(roll_no, data) && data.size() > 0)
    {
        cout << "wrong roll_no: student not persent :" << "\n";
        getch();
        return;
    }
    for (pair<int, pair<Student, School>> &g : data)
    {
        if (roll_no == g.first)
        {
            cout << "student stander: " << g.second.second.get_stander() << endl;
            cout << "student hindi marks: " << g.second.second.get_marks_hindi() << endl;
            cout << "student english marks: " << g.second.second.get_marks_english() << endl;
            cout << "student maths marks: " << g.second.second.get_marks_maths() << endl;
            cout << "student physics marks: " << g.second.second.get_marks_physics() << endl;
            cout << "student chymistry marks: " << g.second.second.get_marks_chymistry() << endl;
            cout << "student art marks: " << g.second.second.get_marks_art() << endl;
            cout << "student total marks: " << g.second.second.get_marks_hindi() + g.second.second.get_marks_english() + g.second.second.get_marks_maths() + g.second.second.get_marks_physics() + g.second.second.get_marks_chymistry() + g.second.second.get_marks_art() << endl;
            cout << "student percentage: " << (g.second.second.get_marks_hindi() + g.second.second.get_marks_english() + g.second.second.get_marks_maths() + g.second.second.get_marks_physics() + g.second.second.get_marks_chymistry() + g.second.second.get_marks_art()) / 6.0 << "%" << endl;
            break;
        }
    }
}
void Office::set_update_detale(deque<pair<int, pair<Student, School>>> &data)
{
rein:
    int roll_no = -1;
    cout << "enter student roll_no for update detale:" << endl;
    cin >> roll_no;
    if (roll_no < 0)
    {
        goto rein;
    }
    if (is_persent(roll_no, data) && data.size() > 0)
    {
        cout << "wrong roll_no: student not persent :" << "\n";
        getch();
        goto rein;
    }
    for (pair<int, pair<Student, School>> &g : data)
    {
        if (roll_no == g.first)
        {
            cout << "enter student name:" << endl;
            string str;
            cin >> str;
            g.second.first.set_name(str);
            cout << "enter student age:" << endl;
            int num1;
            cin >> num1;
            g.second.first.set_age(num1);
            cout << " enter student gender:" << endl;
            cin >> str;
            g.second.first.set_gender(str);
            cout << "enter student father name:" << endl;
            cin >> str;
            g.second.first.set_f_name(str);
            cout << "enter student mother name:" << endl;
            cin >> str;
            g.second.first.set_m_name(str);
            cout << "enter student address with connect -:" << endl;
            cin >> str;
            g.second.first.set_address(str);
            cout << "enter student contect number:" << endl;
            long int lo;
            cin >> lo;
            g.second.first.set_numb(lo);
            break;
        }
    }
    cout << "update succesfully:" << endl;
    return;
}
void Office::set_update_school(deque<pair<int, pair<Student, School>>> &data)
{
rein:
    int roll_no = -1;
    cout << "enter student roll_no for update school detale:" << endl;
    cin >> roll_no;
    if (roll_no < 0)
    {
        goto rein;
    }
    if (is_persent(roll_no, data) && data.size() > 0)
    {
        cout << "wrong roll_no: student not persent :" << "\n";
        getch();
        return;
    }
    for (pair<int, pair<Student, School>> &g : data)
    {
        if (roll_no == g.first)
        {
            cout << "enter student stander:" << endl;
            string sted;
            cin >> sted;
            g.second.second.set_stander(sted);
            cout << "enter hindi marks:" << endl;
            int temp_h;
            cin >> temp_h;
            cout << "enter englis marks:" << endl;
            int temp_e;
            cin >> temp_e;
            cout << "enter maths marks:" << endl;
            int temp_m;
            cin >> temp_m;
            cout << "enter physice m...." << endl;
            int temp_p;
            cin >> temp_p;
            cout << "enter chymistry m....." << endl;
            int temp_c;
            cin >> temp_c;
            cout << "enter art m..." << endl;
            int temp_a;
            cin >> temp_a;
            g.second.second.set_marks(temp_h, temp_e, temp_m, temp_p, temp_c, temp_a);
            break;
        }
    }
    return;
}
void Office::delete_student_detale(deque<pair<int, pair<Student, School>>> &data)
{
    int roll_no;
    cout << "enter student roll_no for delete detale:" << endl;
    cin >> roll_no;
    bool flag = false;

    for (auto it = data.begin(); it != data.end(); it++)
    {
        if (roll_no == it->first)
        {
            flag = true;
            data.erase(it);
            cout << "student detale delete successfully:" << endl;
            break;
        }
    }
    if (!flag)
    {
        cout << "wrong roll_no: student not present :" << "\n";
        getch();
    }

    return;
}