#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <iomanip>
using namespace std;

int main() {
    // Declare variables
    vector<int> numbers;
    int num;
    string filename = "results.txt";

    // Ask the user for input
    cout << "Enter integers (enter any non-numeric value to stop):\n";

    // Read integers from user input until a non-numeric value is entered
    while (cin >> num) {
        numbers.push_back(num);
    }

    // Check if the input vector is empty
    if (numbers.empty()) {
        cout << "No numbers entered. Exiting...\n";
        return 1;
    }

    // Process: Calculate the sum and average of the numbers
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    double average = static_cast<double>(sum) / numbers.size();

    // Output results to the console
    cout << "\nSum: " << sum << endl;
    cout << "Average: " << fixed << setprecision(2) << average << endl;

    // Write results to a file
    ofstream outfile(filename, ios::out);
    if (!outfile) {
        cerr << "Error: Could not open the file for writing.\n";
        return 1;
    }

    outfile << "User Input Results:\n";
    outfile << "Sum: " << sum << endl;
    outfile << "Average: " << fixed << setprecision(2) << average << endl;

    // Close the file
    outfile.close();

    cout << "Results have been written to " << filename << endl;
    return 0;
}
