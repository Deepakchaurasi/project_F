#include <conio.h>
#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
#include "person.h"
#include "ticket.h"
void Allchoices()
{
    cout << "1. Book ticket" << endl;
    cout << "2. Cancel ticket" << endl;
    cout << "3. Print booked tickets" << endl;
    cout << "4. Print Available tickets" << endl;
    cout << "5. Exit" << endl;
}
int main()
{
    int choice = 0;
    std::deque<pair<std::string, Person>> bookticket;
    Person p;
    Ticket t;
    do
    {
        system("cls");
        Allchoices();

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.book_ticket(p, bookticket);
            break;
        case 2:
            t.cancel_ticket(bookticket);
            break;
        case 3:
            t.print_booked_tickets(bookticket);
            break;
        case 4:
            t.print_unbooked_tickets();
            break;
        case 5:
            cout << "Thanyou";
            Sleep(10);
            exit(1);

        default:
            cout << "Enter correct choice:";
            
        }
    } while (true);
    getch();
    return 0;
}
