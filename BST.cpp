#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) {
        key = k;
        height = 1;  // A newly created node has height 1
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    void updateHeight(Node* node) {
        if (node)
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    }

    Node* insert(Node* node, int key) {
        if (!node)
            return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        updateHeight(node);
        return node;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Rotation
        y->left = x;
        x->right = T2;

        // Update heights
        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Rotation
        x->right = y;
        y->left = T2;

        // Update heights
        updateHeight(y);
        updateHeight(x);

        return x;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << "Key: " << node->key << ", Height: " << node->height << endl;
        inOrder(node->right);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void leftRotateAtRoot() {
        if (root && root->right)
            root = leftRotate(root);
    }

    void rightRotateAtRoot() {
        if (root && root->left)
            root = rightRotate(root);
    }

    void displayInOrder() {
        cout << "\nIn-order traversal (Key, Height):" << endl;
        inOrder(root);
    }
};

// ------------------- MAIN --------------------
int main() {
    BST tree;

    // Insert nodes
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(10);

    cout << "Before Rotation:";
    tree.displayInOrder();

    // Perform Right Rotation
    cout << "\nPerforming Right Rotation at root...\n";
    tree.rightRotateAtRoot();
    tree.displayInOrder();

    // Perform Left Rotation
    cout << "\nPerforming Left Rotation at root...\n";
    tree.leftRotateAtRoot();
    tree.displayInOrder();

    return 0;
}
