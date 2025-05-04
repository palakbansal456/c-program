#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int secretNumber, guess;

    srand(time(0));
    secretNumber = rand() % 100 + 1;

    cout << "Guess the number (between 1 and 100): ";

    while (true) {
        cin >> guess;

        if (guess == secretNumber) {
            cout << "Congratulations! You guessed the correct number." << endl;
            break;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again: ";
        } else {
            cout << "Too high! Try again: ";
        }
    }

    return 0;
}
