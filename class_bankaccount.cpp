#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(int accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
        } else {
            cout << "Insufficient balance for withdrawal." << endl;
        }
    }

    // Method to display account details
    void displayAccountDetails() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    // Create a BankAccount object
    BankAccount account1(12345, 1000.00);

    // Display initial account details
    account1.displayAccountDetails();

    // Deposit and withdraw money
    account1.deposit(500);
    account1.withdraw(200);

    // Display updated account details
    account1.displayAccountDetails();

    return 0;
}
