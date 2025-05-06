#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    double price;

public:
    // Parameterized constructor
    Book(string t, string a, double p) {
        title = t;
        author = a;
        price = p;
    }

    // Function to display book details
    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    // Creating a Book object using the parameterized constructor
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 10.99);

    // Displaying the book details
    myBook.displayDetails();

    return 0;
}
