#include <iostream>
using namespace std;

class Account {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Setter methods
    void setAccountHolder(string name) {
        accountHolder = name;
    }

    void setAccountNumber(int number) {
        accountNumber = number;
    }

    void setBalance(double amount) {
        if (amount >= 0)
            balance = amount;
        else
            cout << "Balance cannot be negative!" << endl;
    }

    // Getter methods
    string getAccountHolder() {
        return accountHolder;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    // Display account details
    void displayAccount() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    Account acc;

    acc.setAccountHolder("John Doe");
    acc.setAccountNumber(123456);
    acc.setBalance(5000.75);

    acc.displayAccount();

    return 0;
}
