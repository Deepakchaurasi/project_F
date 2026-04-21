#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    char name[50];
    float balance;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void showAccount() const {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nName: " << name;
        cout << "\nBalance: " << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount Deposited Successfully.\n";
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
        } else {
            balance -= amount;
            cout << "Withdrawal Successful.\n";
        }
    }

    float getBalance() const {
        return balance;
    }
};

// Function to write account to file
void writeAccount() {
    BankAccount acc;
    ofstream outFile("bank.dat", ios::binary | ios::app);

    acc.createAccount();
    outFile.write(reinterpret_cast<char*>(&acc), sizeof(acc));

    outFile.close();
    cout << "Account Created Successfully!\n";
}

// Function to display account
void displayAccount(int accNo) {
    BankAccount acc;
    ifstream inFile("bank.dat", ios::binary);

    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            acc.showAccount();
            found = true;
            break;
        }
    }

    inFile.close();

    if (!found)
        cout << "Account Not Found!\n";
}

// Deposit/Withdraw
void modifyAccount(int accNo, int option) {
    BankAccount acc;
    fstream file("bank.dat", ios::binary | ios::in | ios::out);

    bool found = false;
    while (!file.eof() && file.read(reinterpret_cast<char*>(&acc), sizeof(acc))) {
        if (acc.getAccountNumber() == accNo) {
            acc.showAccount();

            float amt;
            cout << "\nEnter Amount: ";
            cin >> amt;

            if (option == 1)
                acc.deposit(amt);
            else
                acc.withdraw(amt);

            int pos = (-1) * static_cast<int>(sizeof(acc));
            file.seekp(pos, ios::cur);
            file.write(reinterpret_cast<char*>(&acc), sizeof(acc));

            cout << "Record Updated!\n";
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Account Not Found!\n";
}

// Main Menu
int main() {
    int choice, accNo;

    do {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Balance Inquiry\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) { 
        case 1:
            writeAccount();
            break;

        case 2:
            cout << "Enter Account Number: ";
            cin >> accNo;
            modifyAccount(accNo, 1);
            break;

        case 3:
            cout << "Enter Account Number: ";
            cin >> accNo;
            modifyAccount(accNo, 2);
            break;

        case 4:
            cout << "Enter Account Number: ";
            cin >> accNo;
            displayAccount(accNo);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}