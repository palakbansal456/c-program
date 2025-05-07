#include <iostream>
#include <string>
using namespace std;

int main() {
    // Declare variables to store user input
    string name;
    int age;

    // Asking user for input
    cout << "Enter your name: ";
    cin >> name;  // Taking input for the name

    cout << "Enter your age: ";
    cin >> age;  // Taking input for the age

    // Displaying the user input
    cout << "Hello, " << name << "!" << endl;
    cout << "You are " << age << " years old." << endl;

    return 0;
}
