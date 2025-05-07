#include <iostream>
using namespace std;

// Define the Book class
class Book {
public:
    string title;
    string author;
    int year;

    void getDetails() {
        cout << "Enter book title: ";
        getline(cin, title);
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter year of publication: ";
        cin >> year;
        cin.ignore();  // To clear newline from the input buffer
    }

    void displayDetails() const {
        cout << "Title: " << title << ", Author: " << author << ", Year: " << year << endl;
    }
};

int main() {
    int count;

    cout << "Enter number of books: ";
    cin >> count;
    cin.ignore(); // Clear newline character

    // Dynamically allocate array of Book objects
    Book* books = new Book[count];

    // Input details
    for (int i = 0; i < count; ++i) {
        cout << "\nBook " << i + 1 << " details:\n";
        books[i].getDetails();
    }

    // Display details
    cout << "\nDisplaying Book Details:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Book " << i + 1 << ": ";
        books[i].displayDetails();
    }

    // Free memory
    delete[] books;

    return 0;
}
