#include <bits/stdc++.h>
#include "person.h"
#include "ticket.h"
#include<strings.h>

using namespace std;
bool Ticket::abilabal_ticket()
{
    int total = this->upper_bearth + this->lower_bearth + this->middle_ticket + this->waited_ticket + this->racke_ticket;
    if (total < ticket_no)
    {
        return true;
    }
    return false;
}
void Ticket::book_ticket(Person &p, std::deque<std::pair<std::string, Person>> &bookticket)
{
    int age;
    int pid;
    string name;
    char bearth;
    char gender;
    cout << "\nEnter your name and sername with attech undesor:";
    cin>>name;
    p.setName(name);
    cout << "\nEnter your age:";
    cin >> age;
    p.setAge(age);
    cout << "\nEnter your gender : ";
    cin >> gender;
    p.setGender(gender);
    cout << "\nEnter your berth (U/L/M): ";
    cin >> bearth;
    if (!abilabal_ticket())
    {   cout << "Ticket Not abilabal_ticket" << endl;
        getch();
        return;
    }
    Allocate_tickets(p, bearth);
    bookticket.push_back(make_pair(p.getpid(), p));
    cout << "Ticket add succesfully ";
    getch();
    return;
}
void Ticket::Allocate_tickets(Person &p, char &b)
{

    if (b == 'L' && this->lower_bearth < lower_class)
    {
        p.setBearth('L');
        this->lower_bearth+=1;
        this->conferm_ticket+=1;
        p.setpid(this->lower_bearth);
    }
    else if (this->middle_ticket < middel_class)
    {
        p.setBearth('M');
        this->middle_ticket+=1;
        this->conferm_ticket+=1;
        p.setpid(this->middle_ticket);
    }
    else if (this->upper_bearth < upper_class)
    {
        p.setBearth('U');
        this->upper_bearth+=1;
        this->conferm_ticket+=1;
        p.setpid(this->upper_bearth);
    }
    else if (this->racke_ticket < rack_ticket)
    {
        p.setBearth('R');
        this->racke_ticket+=1;
        p.setpid(this->racke_ticket);
    }
    else if (this->waited_ticket < waiting_ticket)
    {
        p.setBearth('W');
        this->waited_ticket+=1;
        p.setpid(this->waited_ticket);
    }

    return;
}
void Ticket::print_booked_tickets(std::deque<std::pair<std::string, Person>> &loadTicket)
{
    for (auto it : loadTicket)
    {
        cout << "---------------------------------------------------" << endl;
        Person p = it.second;

        cout << setw(10) << left << "|personId :" << p.getpid() << "|" << setw(10) << right << endl;
        cout << setw(10) << left << "|Name     :" << p.getName() << "|" << setw(10) << right << endl;
        cout << setw(10) << left << "|Gender   :" << p.getGender() << "|" << setw(10) << right << endl;
        cout << setw(10) << left << "|Bearth   :" << p.getBearth() << "|" << setw(10) << right << endl;
        cout << setw(10) << left << "|Age      :" << p.getAge() << "|" << setw(10) << right << endl;
    }
    cout << "---------------------------------------------------" << endl;
    getch();
    return;
}
void Ticket::print_unbooked_tickets()
{
    cout << "|conferm_ticket  :" << conferm_tickets - this->conferm_ticket << endl;
    cout << "|upper_bearth    :" << upper_class - this->upper_bearth << endl;
    cout << "|lower_bearth    :" << lower_class - this->lower_bearth << endl;
    cout << "|middle_ticket   :" << middel_class - this->middle_ticket << endl;
    cout << "|waited_ticket   :" << waiting_ticket - this->waited_ticket << endl;
    cout << "|racke_ticket    :" << rack_ticket - this->racke_ticket << endl;
    getch();
    return;
}
void Ticket::decrement(char &beart)
{
    if (beart == 'L')
    {
        this->lower_bearth -= 1;
        this->conferm_ticket -= 1;
    }
    else if (beart == 'U')
    {
        this->upper_bearth -= 1;
        this->conferm_ticket -= 1;
    }
    else if (beart == 'M')
    {
        this->middle_ticket -= 1;
        this->conferm_ticket -= 1;
    }
    else if (beart == 'R')
    {
        this->racke_ticket -= 1;
    }
    else if (beart == 'W')
    {
        this->waited_ticket -= 1;
    }
    return;
}
void Ticket::reorder_rack_ticket(std::deque<std::pair<std::string, Person>> &temp, char b)
{
    Person tem, t1;
    for (auto r = temp.begin(); r != temp.end(); r++)
    {
        if (r->first[1] == 'R')
        {
            tem = r->second;
            this->racke_ticket--;
            temp.erase(r);
            break;
        }
    }
    if (b == 'L')
    {
        this->lower_bearth++;
         t1.setBearth(b);
        t1.setpid(this->lower_bearth);
    }
    else if (b == 'M')
    {
        this->middle_ticket++;
         t1.setBearth(b);
        t1.setpid(this->middle_ticket);
    }
    else
    {
        this->upper_bearth++;
         t1.setBearth(b);
        t1.setpid(this->upper_bearth);
    }
    t1.setName(tem.getName());
    t1.setAge(tem.getAge());
    t1.setGender(tem.getGender());
    this->conferm_ticket++;
    temp.push_back({t1.getpid(),t1});
    return;
}
void Ticket::reorder_weated_ticket(std::deque<std::pair<std::string, Person>> &temp, char b)
{
    Person tem, t1;
    for (auto r = temp.begin(); r != temp.end(); r++)
    {
        if (r->first[1] == 'W')
        {
            tem = r->second;
            this->waited_ticket--;
            temp.erase(r);
            break;
        }
    }
    
    this->racke_ticket++;
    t1.setBearth('R');
    t1.setpid((this->racke_ticket));
    t1.setName(tem.getName());
    t1.setAge(tem.getAge());
    t1.setGender(tem.getGender());
    temp.push_back({t1.getpid(),t1});
    return;
}
void Ticket::cancel_ticket(std::deque<std::pair<std::string, Person>> &loadticket)
{
    string id;
    bool signal = false;
    cout << "enter Pid: ";
    cin >> id;
    char beart;

    for (auto it = loadticket.begin(); it != loadticket.end(); it++)
    {
        if (it->first == id)
        {
            signal = true;
            beart = it->first[1];
            decrement(beart);
            loadticket.erase(it);
            break;
        }
    }
    if (signal)
    {
        if (this->racke_ticket > 0)
            reorder_rack_ticket(loadticket, beart);
        if (this->waited_ticket > 0 && this->racke_ticket < rack_ticket)
            reorder_weated_ticket(loadticket, beart);
    }
    cout << "Ticket cancel succesfully:" << endl;
    getch();
    return;
}