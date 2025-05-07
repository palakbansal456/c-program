#include <iostream>
using namespace std;

// Abstract base class
class Payment {
public:
    // Pure virtual function
    virtual void processPayment(double amount) = 0;

    virtual ~Payment() {}
};

// Derived class: CreditCardPayment
class CreditCardPayment : public Payment {
private:
    string cardNumber;
    string cardHolder;

public:
    CreditCardPayment(string number, string holder)
        : cardNumber(number), cardHolder(holder) {}

    void processPayment(double amount) override {
        cout << "Processing credit card payment of $" << amount << " for " << cardHolder
             << " (Card: " << cardNumber << ")" << endl;
    }
};

// Derived class: DebitCardPayment
class DebitCardPayment : public Payment {
private:
    string cardNumber;
    string accountHolder;

public:
    DebitCardPayment(string number, string holder)
        : cardNumber(number), accountHolder(holder) {}

    void processPayment(double amount) override {
        cout << "Processing debit card payment of $" << amount << " for " << accountHolder
             << " (Card:
