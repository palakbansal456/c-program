#include <iostream>
#include <vector>
#include <stdexcept>
#include <memory>
using namespace std;

// Abstract base class for Collection
template <typename T>
class Collection {
public:
    virtual void add(const T& element) = 0;     // Add element to the collection
    virtual T remove() = 0;                      // Remove element from the collection
    virtual T get(int index) const = 0;          // Get element at index
    virtual bool isEmpty() const = 0;            // Check if collection is empty
    virtual size_t size() const = 0;             // Get collection size
    virtual ~Collection() {}                     // Virtual destructor
};

// Derived class: ArrayList (using vector for dynamic array)
template <typename T>
class ArrayList : public Collection<T> {
private:
    vector<T> elements;  // Dynamic array (vector)

public:
    void add(const T& element) override {
        elements.push_back(element);  // Add element to the end
    }

    T remove() override {
        if (isEmpty()) {
            throw out_of_range("Cannot remove from an empty collection.");
        }
        T removedElement = elements.back();
        elements.pop_back();  // Remove the last element
        return removedElement;
    }

    T get(int index) const override {
        if (index < 0 || index >= size()) {
            throw out_of_range("Index out of bounds.");
        }
        return elements[index];  // Access the element at the given index
    }

    bool isEmpty() const override {
        return elements.empty();  // Check if the collection is empty
    }

    size_t size() const override {
        return elements.size();  // Return the current size of the collection
    }
};

// Derived class: LinkedList (using basic linked list structure)
template <typename T>
class LinkedList : public Collection<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    size_t collectionSize;

public:
    LinkedList() : head(nullptr), collectionSize(0) {}

    void add(const T& element) override {
        Node* newNode = new Node(element);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        collectionSize++;
    }

    T remove() override {
        if (isEmpty()) {
            throw out_of_range("Cannot remove from an empty collection.");
        }
        Node* temp = head;
        T removedElement = head->data;
        head = head->next;
        delete temp;
        collectionSize--;
        return removedElement;
    }

    T get(int index) const override {
        if (index < 0 || index >= size()) {
            throw out_of_range("Index out of bounds.");
        }
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    bool isEmpty() const override {
        return head == nullptr;
    }

    size_t size() const override {
        return collectionSize;
    }

    ~LinkedList() {
        while (!isEmpty()) {
            remove();
        }
    }
};

// Function to test the Collection framework with exception handling
template <typename T>
void testCollection(Collection<T>* collection) {
    try {
        collection->add(10);
        collection->add(20);
        collection->add(30);
        cout << "Collection size: " << collection->size() << endl;

        cout << "Element at index 1: " << collection->get(1) << endl;

        cout << "Removing element: " << collection->remove() << endl;

        cout << "Collection size after removal: " << collection->size() << endl;

        // Accessing out-of-bounds index
        cout << "Accessing out of bounds: " << collection->get(5) << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
}

int main() {
    // Test ArrayList
    cout << "Testing ArrayList:" << endl;
    ArrayList<int> arrayList;
    testCollection(&arrayList);

    cout << "\nTesting LinkedList:" << endl;
    LinkedList<int> linkedList;
    testCollection(&linkedList);

    return 0;
}
