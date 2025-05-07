#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    T* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) : front(0), rear(0), size(0), capacity(cap) {
        arr = new T[capacity];
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation (add element to the rear)
    void enqueue(T value) {
        if (size == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity; // Circular increment
        size++;
    }

    // Dequeue operation (remove element from the front)
    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity; // Circular increment
        size--;
    }

    // Display the queue elements
    void display() const {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int count = 0; count < size; ++count) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity; // Circular increment
        }
        cout << endl;
    }

    // Get the current size of the queue
    int getSize() const {
        return size;
    }
};

int main() {
    // Create a Queue of integers with a capacity of 5
    Queue<int> intQueue(5);

    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.enqueue(40);
    intQueue.enqueue(50);
    intQueue.display();

    intQueue.enqueue(60);  // Queue overflow
    intQueue.dequeue();
    intQueue.display();

    cout << "\n";

    // Create a Queue of strings with a capacity of 3
    Queue<string> strQueue(3);
    strQueue.enqueue("Apple");
    strQueue.enqueue("Banana");
    strQueue.enqueue("Cherry");
    strQueue.display();

    strQueue.dequeue();
    strQueue.display();

    return 0;
}
