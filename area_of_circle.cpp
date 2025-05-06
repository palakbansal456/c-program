#include <iostream>
using namespace std;

double areaOfCircle(double radius);

int main() {
    double r;

    cout << "Enter the radius of the circle: ";
    cin >> r;

    double area = areaOfCircle(r);
    cout << "Area of the circle is: " << area << endl;

    return 0;
}

double areaOfCircle(double radius) {
    const double PI = 3.14159;
    return PI * radius * radius;
}
