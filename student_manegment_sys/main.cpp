#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <string>
using namespace std;
#include "personal.h"
#include "caricul.h"
#include "office.h"
deque<pair<int, pair<Student, School>>> data;
class System
{

public:
   void print_list()
   {

      cout << "enter student detale:" << endl;
      cout << "1.inter student detale :" << endl;
      // cout << "2.inter student school detale :" << endl;
      cout << "2. print student detal :" << endl;
      cout << "3.update student detale:" << endl;
      cout << "4.update student school detale:" << endl;
      cout << "5.delete student detale:" << endl;
      cout << "6.exit:" << endl;
      cout << "**********************************instruction*******************************" << endl;
      cout << "string valu alwase inter wit concatinat with - " << endl;
      cout << "infint runtime happen then stop by ctrl+c press:" << endl;
      return;
   }
};
int main()
{
   Office of;
   System s;
   int chooic = 0;
   while (true)
   {

      system("cls");
      s.print_list();
      cout << "enter choice:" << endl;
      cin >> chooic;
      switch (chooic)
      {
      case 1:
         of.set_student_detale(data);
         cout << "student detale intered successfully:" << "\n";
         getch();
         break;
      case 2:
         int roll;
         cout << "enter student roll_no:" << endl;
         cin >> roll;
         of.print_student_detale(roll, data);
         of.print_student_school(roll, data);
         getch();

         break;
      case 3:
         cout << "update student detale:" << "\n";
         of.set_update_detale(data);
         getch();
         break;
      case 4:
         cout << "update school detale:" << "\n";
         of.set_update_school(data);
         cout << "student detale update successfully:" << "\n";
         getch();
         break;
      case 5:
         cout << "delete student detale:" << "\n";
         cout << "enter student roll_no for delete detale:" << "\n";
         getch();
         of.delete_student_detale(data);
         cout << "student detale delete successfully:" << "\n";
         getch();
         break;
      case 6:
         exit(0);
      default:
         cout << "pleces enter correct choice:" << endl;
         break;
      }
   }
   getch();
   return 0;
}