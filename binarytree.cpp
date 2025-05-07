#include <iostream>
using namespace std;

// Template for Tree Node
template <typename T>
class Node {
public:
    T data;          // Data of the node
    Node* left;      // Pointer to left child
    Node* right;     // Pointer to right child

    // Constructor to create a new node
    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

// Template for BinaryTree
template <typename T>
class BinaryTree {
private:
    Node<T>* root;  // Root of the tree

    // Helper function for in-order traversal
    void inorderTraversal(Node<T>* node) const {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);         // Traverse left subtree
        cout << node->data << " ";            // Visit root
        inorderTraversal(node->right);        // Traverse right subtree
    }

    // Helper function to insert data into the tree
    Node<T>* insert(Node<T>* node, T value) {
        if (node == nullptr) {
            return new Node<T>(value);  // Create a new node if tree is empty
        }
        if (value < node->data) {
            node->left = insert(node->left, value);  // Insert in the left subtree
        } else {
            node->right = insert(node->right, value);  // Insert in the right subtree
        }
        return node;
    }

    // Helper function to delete nodes and free memory
    void deleteTree(Node<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);    // Delete left subtree
            deleteTree(node->right);   // Delete right subtree
            delete node;               // Delete current node
        }
    }

public:
    // Constructor to initialize an empty tree
    BinaryTree() : root(nullptr) {}

    // Destructor to clean up memory
    ~BinaryTree() {
        deleteTree(root);
    }

    // Function to insert data into the tree
    void insert(T value) {
        root = insert(root, value);
    }

    // Function to perform in-order traversal
    void inorderTraversal() const {
        inorderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    // Create a binary tree of integers
    BinaryTree<int> intTree;

    // Insert elements into the tree
    intTree.insert(5);
    intTree.insert(3);
    intTree.insert(7);
    intTree.insert(2);
    intTree.insert(4);
    intTree.insert(6);
    intTree.insert(8);

    // Display elements in in-order traversal
    cout << "In-order traversal of integer tree: ";
    intTree.inorderTraversal();

    // Create a binary tree of strings
    BinaryTree<string> stringTree;

    // Insert elements into the string tree
    stringTree.insert("apple");
    stringTree.insert("banana");
    stringTree.insert("cherry");
    stringTree.insert("date");

    // Display elements in in-order traversal
    cout << "In-order traversal of string tree: ";
    stringTree.inorderTraversal();

    return 0;
}
