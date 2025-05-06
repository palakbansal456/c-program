#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

    // Normalize the time to ensure valid hour, minute, second format
    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours >= 24) {
            hours %= 24;  // Reset hours to 24-hour format
        }
    }

public:
    // Constructor to initialize time
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Method to display time
    void display() const {
        cout << "Time: " << hours << ":" << minutes << ":" << seconds << endl;
    }

    // Add time (addition of two Time objects)
    Time add(const Time& other) const {
        int total_seconds = (hours * 3600 + minutes * 60 + seconds) +
                            (other.hours * 3600 + other.minutes * 60 + other.seconds);
        
        int new_hours = total_seconds / 3600;
        int new_minutes = (total_seconds % 3600) / 60;
        int new_seconds = total_seconds % 60;

        return Time(new_hours, new_minutes, new_seconds);
    }

    // Subtract time (subtract one Time object from another)
    Time subtract(const Time& other) const {
        int this_total_seconds = hours * 3600 + minutes * 60 + seconds;
        int other_total_seconds = other.hours * 3600 + other.minutes * 60 + other.seconds;

        // Ensure we don't get negative time
        int total_seconds = this_total_seconds - other_total_seconds;
        if (total_seconds < 0) {
            total_seconds = 0;  // Don't allow negative time
        }

        int new_hours = total_seconds / 3600;
        int new_minutes = (total_seconds % 3600) / 60;
        int new_seconds = total_seconds % 60;

        return Time(new_hours, new_minutes, new_seconds);
    }

    // Compare two Time objects
    bool isEqual(const Time& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }

    // Overload the == operator to compare Time objects
    bool operator==(const Time& other) const {
        return isEqual(other);
    }

    // Overload the < operator to compare Time objects (for example, for sorting)
    bool operator<(const Time& other) const {
        if (hours != other.hours)
            return hours < other.hours;
        if (minutes != other.minutes)
            return minutes < other.minutes;
        return seconds < other.seconds;
    }
};

int main() {
    Time t1(2, 30, 45);  // 2 hours, 30 minutes, 45 seconds
    Time t2(1, 15, 30);  // 1 hour, 15 minutes, 30 seconds

    cout << "Time 1: ";
    t1.display();
    cout << "Time 2: ";
    t2.display();

    // Add time
    Time sum = t1.add(t2);
    cout << "Sum of Time 1 and Time 2: ";
    sum.display();

    // Subtract time
    Time difference = t1.subtract(t2);
    cout << "Difference of Time 1 and Time 2: ";
    difference.display();

    // Compare times
    if (t1 == t2) {
        cout << "Time 1 is equal to Time 2." << endl;
    } else {
        cout << "Time 1 is not equal to Time 2." << endl;
    }

    // Compare using overloaded '<' operator
    if (t1 < t2) {
        cout << "Time 1 is earlier than Time 2." << endl;
    } else {
        cout << "Time 1 is later than Time 2." << endl;
    }

    return 0;
}
