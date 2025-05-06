#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    // Constructor to initialize the date
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Overload == operator to compare two Date objects
    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }

    // Function to display the date
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date date1(6, 5, 2025);
    Date date2(6, 5, 2025);
    Date date3(1, 1, 2023);

    cout << "Comparing date1 and date2: ";
    if (date1 == date2)
        cout << "Dates are equal." << endl;
    else
        cout << "Dates are not equal." << endl;

    cout << "Comparing date1 and date3: ";
    if (date1 == date3)
        cout << "Dates are equal." << endl;
    else
        cout << "Dates are not equal." << endl;

    return 0;
}
