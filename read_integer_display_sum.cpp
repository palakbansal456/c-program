#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;
    char choice;

    // Loop to repeatedly ask for integers and sum them
    do {
        // Asking the user to input a number
        cout << "Enter an integer: ";
        cin >> num;

        // Adding the number to the sum
        sum += num;

        // Ask the user if they want to continue
        cout << "Do you want to enter another integer? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');  // Continue if the user enters 'y' or 'Y'

    // Display the total sum
    cout << "The sum of the entered integers is: " << sum << endl;

    return 0;
}
