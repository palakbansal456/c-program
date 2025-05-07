#include <iostream>
using namespace std;

// Abstract base class
class Account {
protected:
    double balance;

public:
    Account(double b) : balance(b) {}

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
public:
    SavingsAccount(double b) : Account(b) {}

    double calculateInterest() const override {
        // 4% interest
        return balance * 0.04;
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public Account {
public:
    CurrentAccount(double b) : Account(b) {}

    double calculateInterest() const override {
        // No interest for current accounts
        return 0.0;
    }
};

int main() {
    // Create pointers to base class
    Account* acc1 = new SavingsAccount(1000.0);
    Account* acc2 = new CurrentAccount(2000.0);

    // Display interest and balance
    cout << "Savings Account:\n";
    acc1->display();
    cout << "Interest: $" << acc1->calculateInterest() << "\n\n";

    cout << "Current Account:\n";
    acc2->display();
    cout << "Interest: $" << acc2->calculateInterest() << "\n";

    // Cleanup
    delete acc1;
    delete acc2;

    return 0;
}
