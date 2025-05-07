#include <iostream>
#include <vector>
using namespace std;

// Base class Account (Abstract class)
class Account {
protected:
    string accountHolder;
    double balance;

public:
    Account(string name, double balance) : accountHolder(name), balance(balance) {}

    // Pure virtual function for depositing
    virtual void deposit(double amount) = 0;

    // Pure virtual function for withdrawing
    virtual void withdraw(double amount) = 0;

    // Virtual function to display account info
    virtual void display() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() {}
};

// Derived class SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(string name, double balance, double rate)
        : Account(name, balance), interestRate(rate) {}

    // Deposit function
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " to Savings Account." << endl;
    }

    // Withdraw function
    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds in Savings Account!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: " << amount << " from Savings Account." << endl;
        }
    }

    // Display account info with interest rate
    void display() const override {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(string name, double balance) : Account(name, balance) {}

    // Deposit function
    void deposit(double amount) override {
        balance += amount;
        cout << "Deposited: " << amount << " to Current Account." << endl;
    }

    // Withdraw function
    void withdraw(double amount) override {
        balance -= amount;
        cout << "Withdrew: " << amount << " from Current Account." << endl;
    }

    // Display account info
    void display() const override {
        Account::display();
    }
};

// Function to display menu and handle user input
void showMenu() {
    cout << "Menu:" << endl;
    cout << "1. Create Savings Account" << endl;
    cout << "2. Create Current Account" << endl;
    cout << "3. Deposit to Account" << endl;
    cout << "4. Withdraw from Account" << endl;
    cout << "5. Display Account Info" << endl;
    cout << "6. Exit" << endl;
}

int main() {
    vector<Account*> accounts; // Store accounts in a vector
    int choice;
    string name;
    double balance, amount, interestRate;

    while (true) {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter initial balance: ";
            cin >> balance;
            cout << "Enter interest rate: ";
            cin >> interestRate;
            accounts.push_back(new SavingsAccount(name, balance, interestRate));
        }
        else if (choice == 2) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter initial balance: ";
            cin >> balance;
            accounts.push_back(new CurrentAccount(name, balance));
        }
        else if (choice == 3) {
            cout << "Enter account index to deposit: ";
            int index;
            cin >> index;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            if (index >= 0 && index < accounts.size()) {
                accounts[index]->deposit(amount);
            } else {
                cout << "Invalid account index!" << endl;
            }
        }
        else if (choice == 4) {
            cout << "Enter account index to withdraw: ";
            int index;
            cin >> index;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (index >= 0 && index < accounts.size()) {
                accounts[index]->withdraw(amount);
            } else {
                cout << "Invalid account index!" << endl;
            }
        }
        else if (choice == 5) {
            cout << "Enter account index to display: ";
            int index;
            cin >> index;

            if (index >= 0 && index < accounts.size()) {
                accounts[index]->display();
            } else {
                cout << "Invalid account index!" << endl;
            }
        }
        else if (choice == 6) {
            cout << "Exiting program..." << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    // Free dynamically allocated memory
    for (Account* account : accounts) {
        delete account;
    }

    return 0;
}
