#include <iostream>
using namespace std;

struct Node {
    int key;
    int height;
    Node* left;
    Node* right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Update height of a node
void updateHeight(Node* n) {
    if (n)
        n->height = 1 + max(height(n->left), height(n->right));
}

// Right rotate subtree rooted with y
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // new root
}

// Left rotate subtree rooted with x
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // new root
}

// Insert in BST (for building tree)
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    else return root; // no duplicates

    updateHeight(root);
    return root;
}

// In-order traversal with printing key and height
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "Key: " << root->key << ", Height: " << root->height << "\n";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    int n, key;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter node keys:\n";
    for (int i = 0; i < n; ++i) {
        cin >> key;
        root = insert(root, key);
    }

    cout << "\nInorder traversal before rotations:\n";
    inorder(root);

    cout << "\nPerforming one right rotation on root if possible.\n";
    if (root && root->left) {
        root = rightRotate(root);
    }

    cout << "\nInorder traversal after right rotation:\n";
    inorder(root);

    cout << "\nPerforming one left rotation on root if possible.\n";
    if (root && root->right) {
        root = leftRotate(root);
    }

    cout << "\nInorder traversal after left rotation:\n";
    inorder(root);

    return 0;
}
