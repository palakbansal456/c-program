#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// A simple class representing a resource
class Resource {
public:
    Resource() { cout << "Resource acquired!" << endl; }
    ~Resource() { cout << "Resource released!" << endl; }

    void display() const {
        cout << "Resource is being used!" << endl;
    }
};

// Function using unique_ptr (ownership of the resource is transferred)
void uniquePointerDemo() {
    cout << "\nDemonstrating unique_ptr:\n";
    unique_ptr<Resource> resource1 = make_unique<Resource>();  // Create resource using unique_ptr
    resource1->display();

    // Resource ownership is transferred when we move it
    unique_ptr<Resource> resource2 = move(resource1); // transfer ownership
    if (!resource1) {
        cout << "resource1 is null after transfer.\n";
    }
    resource2->display();  // resource2 now owns the resource
}

// Function using shared_ptr (multiple pointers can share ownership)
void sharedPointerDemo() {
    cout << "\nDemonstrating shared_ptr:\n";
    shared_ptr<Resource> resource1 = make_shared<Resource>();  // Create resource using shared_ptr
    resource1->display();

    {
        shared_ptr<Resource> resource2 = resource1;  // Now both resource1 and resource2 share ownership
        cout << "Inside block, shared_ptr count: " << resource2.use_count() << endl;
        resource2->display();
    }

    // Outside the block, resource2 is destroyed, but resource1 still holds it
    cout << "Outside block, shared_ptr count: " << resource1.use_count() << endl;
    resource1->display();
}

// Function using weak_ptr (does not affect reference count, prevents circular references)
void weakPointerDemo() {
    cout << "\nDemonstrating weak_ptr:\n";
    shared_ptr<Resource> resource1 = make_shared<Resource>();  // Create resource using shared_ptr
    weak_ptr<Resource> weakResource = resource1; // weak_ptr does not affect the reference count

    cout << "Before use, shared_ptr count: " << resource1.use_count() << endl;
    if (auto lockedResource = weakResource.lock()) {
        lockedResource->display();
    } else {
        cout << "Resource has expired.\n";
    }

    resource1.reset(); // Now, the resource is no longer held by any shared_ptr
    cout << "After reset, shared_ptr count: " << resource1.use_count() << endl;

    if (auto lockedResource = weakResource.lock()) {
        lockedResource->display();
    } else {
        cout << "Resource has expired.\n";
    }
}

int main() {
    // Demonstrating unique_ptr
    uniquePointerDemo();

    // Demonstrating shared_ptr
    sharedPointerDemo();

    // Demonstrating weak_ptr
    weakPointerDemo();

    return 0;
}
