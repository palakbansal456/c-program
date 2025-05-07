#include <iostream>
#include <string>
using namespace std;

// Custom exception class
class InvalidAgeException {
private:
    string message;

public:
    InvalidAgeException(const string& msg) : message(msg) {}

    string what() const {
        return message;
    }
};

// Function to check age
void checkAge(int age) {
    if (age < 0 || age > 120) {
        throw InvalidAgeException("Invalid age entered. Age must be between 0 and 120.");
    } else {
        cout << "Valid age: " << age << endl;
    }
}

int main() {
    int age;
    cout << "Enter age: ";
    cin >> age;

    try {
        checkAge(age);
    } 
    catch (const InvalidAgeException& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    return 0;
}
