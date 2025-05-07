#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// Base template class that defines a generic algorithm interface
template <typename T>
class Algorithm {
public:
    virtual void execute(vector<T>& data) = 0;  // Pure virtual function to execute the algorithm
    virtual ~Algorithm() {}  // Virtual destructor
};

// Derived class implementing a sorting algorithm (e.g., Bubble Sort)
template <typename T>
class SortAlgorithm : public Algorithm<T> {
public:
    void execute(vector<T>& data) override {
        // Simple Bubble Sort implementation
        bool swapped;
        for (size_t i = 0; i < data.size() - 1; ++i) {
            swapped = false;
            for (size_t j = 0; j < data.size() - 1 - i; ++j) {
                if (data[j] > data[j + 1]) {
                    swap(data[j], data[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;  // Exit early if the array is already sorted
        }
        cout << "Sorted data: ";
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }
};

// Derived class implementing a searching algorithm (e.g., Linear Search)
template <typename T>
class SearchAlgorithm : public Algorithm<T> {
public:
    void execute(vector<T>& data) override {
        T target;
        cout << "Enter the value to search: ";
        cin >> target;
        
        auto it = find(data.begin(), data.end(), target);
        if (it != data.end()) {
            cout << "Element " << target << " found at index " << distance(data.begin(), it) << endl;
        } else {
            cout << "Element " << target << " not found.\n";
        }
    }
};

// Function to demonstrate the use of algorithms with templates
template <typename T>
void executeAlgorithm(Algorithm<T>* algorithm, vector<T>& data) {
    algorithm->execute(data);  // Call the execute function polymorphically
}

int main() {
    // Example 1: Sorting integers
    vector<int> intData = { 10, 3, 5, 8, 6, 1, 9 };
    SortAlgorithm<int> intSort;
    cout << "Executing Sort Algorithm (on integers):\n";
    executeAlgorithm(&intSort, intData);  // Using the sorting algorithm for integers
    
    // Example 2: Searching for an integer
    vector<int> searchData = { 10, 3, 5, 8, 6, 1, 9 };
    SearchAlgorithm<int> intSearch;
    cout << "\nExecuting Search Algorithm (on integers):\n";
    executeAlgorithm(&intSearch, searchData);  // Using the search algorithm for integers

    // Example 3: Sorting floats
    vector<float> floatData = { 2.5f, 3.1f, 1.4f, 5.7f, 4.3f };
    SortAlgorithm<float> floatSort;
    cout << "\nExecuting Sort Algorithm (on floats):\n";
    executeAlgorithm(&floatSort, floatData);  // Using the sorting algorithm for floats

    return 0;
}
