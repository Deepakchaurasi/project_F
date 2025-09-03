#ifndef TICKET_H
#define TICKET_H
#include <bits/stdc++.h>
#pragma once
#include <conio.h>
#include "person.h"

using namespace std;
#define ticket_no 7
#define conferm_tickets 5
#define lower_class 2
#define upper_class 2
#define middel_class 1
#define rack_ticket 1
#define waiting_ticket 1
class Ticket
{
    int conferm_ticket, upper_bearth, lower_bearth, middle_ticket, waited_ticket, racke_ticket;

public:
    Ticket() : conferm_ticket(0), upper_bearth(0), lower_bearth(0), racke_ticket(0), waited_ticket(0), middle_ticket(0) {}
    void book_ticket(Person &p, std::deque<std::pair<std::string, Person>> &bookticbket);
    bool abilabal_ticket();
    void Allocate_tickets(Person &p, char &bearth);
    void cancel_ticket(std::deque<std::pair<std::string, Person>> &temp);
    void print_booked_tickets(std::deque<std::pair<std::string, Person>> &bookticket);
    void print_unbooked_tickets();
    void decrement(char &b);
    void reorder_rack_ticket(std::deque<std::pair<std::string, Person>> &temp, char h);
    void reorder_weated_ticket(std::deque<std::pair<std::string, Person>> &temp, char h);
};
#endif
