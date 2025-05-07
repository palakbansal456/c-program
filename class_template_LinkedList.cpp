#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert at end
    void insert(T value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    // Delete by value
    void remove(T value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "Deleted: " << value << endl;
            return;
        }

        Node* current = head;
        while (current->next && current->next->data != value)
            current = current->next;

        if (current->next) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            cout << "Deleted: " << value << endl;
        } else {
            cout << "Value not found.\n";
        }
    }

    // Display list
    void display() const {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Test the LinkedList template
int main() {
    LinkedList<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.display();

    intList.remove(20);
    intList.display();

    LinkedList<string> strList;
    strList.insert("Alice");
    strList.insert("Bob");
    strList.display();

    strList.remove("Alice");
    strList.display();

    return 0;
}
