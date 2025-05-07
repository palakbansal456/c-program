#include <iostream>
using namespace std;

// Base class: Media
class Media {
public:
    // Virtual function to be overridden
    virtual void display() const {
        cout << "Displaying media info." << endl;
    }

    // Virtual destructor for proper cleanup
    virtual ~Media() {}
};

// Derived class: Book
class Book : public Media {
private:
    string title;
    string author;

public:
    Book(string t, string a) : title(t), author(a) {}

    void display() const override {
        cout << "Book Title: " << title << ", Author: " << author << endl;
    }
};

// Derived class: DVD
class DVD : public Media {
private:
    string title;
    double duration; // in minutes

public:
    DVD(string t, double d) : title(t), duration(d) {}

    void display() const override {
        cout << "DVD Title: " << title << ", Duration: " << duration << " minutes" << endl;
    }
};

int main() {
    // Create base class pointers to derived objects
    Media* media1 = new Book("The Alchemist", "Paulo Coelho");
    Media* media2 = new DVD("Inception", 148.0);

    // Call display through base class pointer (polymorphism)
    media1->display();
    media2->display();

    // Clean up memory
    delete media1;
    delete media2;

    return 0;
}
