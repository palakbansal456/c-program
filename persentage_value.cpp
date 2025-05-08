#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Sample data
    string product[] = {"Laptop", "Phone", "Tablet"};
    double price[] = {999.99, 499.49, 299.95};
    double discount[] = {0.10, 0.15, 0.20};  // 10%, 15%, 20%

    cout << left << setw(15) << "Product"
         << right << setw(12) << "Price ($)"
         << setw(15) << "Discount (%)"
         << setw(18) << "Final Price ($)" << endl;

    cout << string(60, '-') << endl;

    for (int i = 0; i < 3; ++i) {
        double finalPrice = price[i] * (1 - discount[i]);
        cout << left << setw(15) << product[i]
             << right << fixed << setprecision(2) << setw(12) << price[i]
             << setw(15) << discount[i] * 100
             << setw(18) << finalPrice << endl;
    }

    return 0;
}
