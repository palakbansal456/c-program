#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;

public:
    // Constructor to initialize the car's attributes
    Car(string m, string mod, int y) {
        make = m;
        model = mod;
        year = y;
    }

    // Method to display car details
    void displayDetails() {
        cout << "Car Details:" << endl;
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create a car object with specific details
    Car car1("Toyota", "Corolla", 2020);

    // Display the car details
    car1.displayDetails();

    return 0;
}
