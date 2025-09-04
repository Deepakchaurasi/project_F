#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

class Choice
{
    string Username;
    string Password;
    string line;
    fstream writ;
    time_t rawtime;
    struct tm *local_time;

public:
    bool registerUser()
    {
        fstream writ;
        cout << "Enter your User Name only latter and number:" << endl;
        cin >> Username;
        cout << "Enter your passWord:" << endl;
        cin >> Password;
        writ.open("data_login.text", ios::in);
        if (!writ.is_open())
        {
            cerr << "<-----------Unable to open file-------------->" << endl;
            getch();
            exit(1);
        }
        else
        {
            while (getline(writ, line))
            {
                if (line.find("User Name:" + Username) != string::npos && line.find("Password:" + Password) != string::npos)
                {
                    writ.close();
                    cout << "<-----------------One user persent with same name:----------------->" << endl;
                    getch();
                    return false;
                }
            }
        }
        if (writ.is_open())
        {
            writ.close();
            writ.open("data_login.text", ios ::app);
            time(&rawtime);
            writ << "User Name:" << Username << "  ";
            writ << "Password:" << Password << "  ";
            writ << "Rgistration_Timestamp:" << ctime(&rawtime);
            writ.close();
            cout << "<-------------Register Successful-------------->" << endl;
        }
        getch();
        return true;
    }

    bool login()
    {
        fstream writ;
        cout << "Enter your User Name only latter and number:" << endl;
        cin >> Username;
        cout << "Enter your passWord:" << endl;
        cin >> Password;
        writ.open("data_login.text", ios::in);
        if (!writ.is_open())
        {
            cerr << "<--------------file not open:------------->" << endl;
            getch();
            exit(1);
        }
        while (getline(writ, line))
        {
            if (line.find("User Name:" + Username) != string::npos && line.find("Password:" + Password) != string::npos)
            {

                writ.close();
                writ.open("data_login.text", ios ::app);
                time(&rawtime);
                writ << "User Name:" << Username << "  ";
                writ << "Password:" << Password << "  ";
                writ << "Login_Timestamp:" << ctime(&rawtime);
                writ.close();
                cout << "<------------Login Successful----------------->" << endl;
                getch();
                return true;
            }
        }
        cout << "<----------------first register your self prass Enter:------------------>" << endl;
        getch();
        return false;
    }
};
class Yourportal : public Choice
{

public:
    bool loginportal()
    {
    log1:
        system("cls");
        cout << "\n<-----------prass Enter for login in portal:--------->" << endl;
        getch();
        if (login())
        {
            cout << "\n<--------------Welcome in the portal----------->" << endl;
            return true;
        }
        else
        {
        re_enter:
            cout << "\n<----------------Prass Enter for Registration:----------->" << endl;
            getch();
            if (registerUser())
            {
                goto log1;
            }
            else
            {
                goto re_enter;
            }
        }
        return true;
    }
};

int main()
{
    Yourportal p;
    p.loginportal();
    return 0;
}
