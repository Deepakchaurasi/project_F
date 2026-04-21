#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
private:
    int bookID;
    char title[50];
    char author[50];
    bool issued;

public:
    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Title: ";
        cin.getline(title, 50);

        cout << "Enter Author: ";
        cin.getline(author, 50);

        issued = false;
    }

    void display() const {
        cout << "\nBook ID: " << bookID;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (issued ? "Issued" : "Available") << endl;
    }

    int getID() const { return bookID; }
    const char* getTitle() const { return title; }
    const char* getAuthor() const { return author; }
    bool isIssued() const { return issued; }

    void issueBook() { issued = true; }
    void returnBook() { issued = false; }
};

// Add Book
void addBook() {
    Book b;
    ofstream out("library.dat", ios::binary | ios::app);

    b.addBook();
    out.write(reinterpret_cast<char*>(&b), sizeof(b));

    out.close();
    cout << "Book added successfully!\n";
}

// Display All Books
void displayAll() {
    Book b;
    ifstream in("library.dat", ios::binary);

    while (in.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        b.display();
    }

    in.close();
}

// Search Book
void searchBook() {
    Book b;
    ifstream in("library.dat", ios::binary);

    char keyword[50];
    cin.ignore();
    cout << "Enter Title or Author to search: ";
    cin.getline(keyword, 50);

    bool found = false;

    while (in.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        if (strstr(b.getTitle(), keyword) || strstr(b.getAuthor(), keyword)) {
            b.display();
            found = true;
        }
    }

    if (!found)
        cout << "No matching book found!\n";

    in.close();
}

// Issue Book
void issueBook(int id) {
    Book b;
    fstream file("library.dat", ios::binary | ios::in | ios::out);

    bool found = false;

    while (file.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        if (b.getID() == id) {
            if (b.isIssued()) {
                cout << "Book already issued!\n";
            } else {
                b.issueBook();
                int pos = -1 * sizeof(b);
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char*>(&b), sizeof(b));
                cout << "Book issued successfully!\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";

    file.close();
}

// Return Book
void returnBook(int id) {
    Book b;
    fstream file("library.dat", ios::binary | ios::in | ios::out);

    bool found = false;

    while (file.read(reinterpret_cast<char*>(&b), sizeof(b))) {
        if (b.getID() == id) {
            if (!b.isIssued()) {
                cout << "Book was not issued!\n";
            } else {
                b.returnBook();
                int pos = -1 * sizeof(b);
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<char*>(&b), sizeof(b));
                cout << "Book returned successfully!\n";
            }
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Book not found!\n";

    file.close();
}

// Main Menu
int main() {
    int choice, id;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook();
            break;

        case 2:
            displayAll();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            cout << "Enter Book ID to issue: ";
            cin >> id;
            issueBook(id);
            break;

        case 5:
            cout << "Enter Book ID to return: ";
            cin >> id;
            returnBook(id);
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}