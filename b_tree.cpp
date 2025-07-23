#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node *left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    // Insert in BST
    Node* insert(Node* root, int val) {
        if (!root) return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    // Delete node from BST
    Node* remove(Node* root, int val) {
        if (!root) return nullptr;
        if (val < root->data) root->left = remove(root->left, val);
        else if (val > root->data) root->right = remove(root->right, val);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // Find inorder successor
            Node* temp = root->right;
            while (temp && temp->left) temp = temp->left;
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
        return root;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

class ArrayOps {
public:
    // Insert at beginning
    void insertBeginning(vector<int> &a, int val) {
        a.insert(a.begin(), val);
    }

    // Insert at end
    void insertEnd(vector<int> &a, int val) {
        a.push_back(val);
    }

    // Insert at position p (0-indexed)
    void insertAtPosition(vector<int> &a, int p, int val) {
        if (p >= 0 && p <= (int)a.size())
            a.insert(a.begin() + p, val);
    }

    // Delete from beginning
    void deleteBeginning(vector<int> &a) {
        if (!a.empty())
            a.erase(a.begin());
    }

    // Delete from end
    void deleteEnd(vector<int> &a) {
        if (!a.empty())
            a.pop_back();
    }

    // Delete at position p
    void deleteAtPosition(vector<int> &a, int p) {
        if (p >= 0 && p < (int)a.size())
            a.erase(a.begin() + p);
    }

    // Print array
    void printArray(const vector<int> &a) {
        for (int x : a) cout << x << " ";
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    Node* root = nullptr;

    // Example usage: insert nodes into BST
    int n, val;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = bt.insert(root, val);
    }

    // Print inorder traversal
    bt.inorder(root);
    cout << endl;

    // Delete a node
    cin >> val;
    root = bt.remove(root, val);
    bt.inorder(root);
    cout << endl;

    // Array operations
    ArrayOps ao;
    vector<int> arr;

    int q; // number of operations
    cin >> q;
    while (q--) {
        int op; // 1: insertBeginning, 2: insertEnd, 3: insertAtPos, 4: delBeg, 5: delEnd, 6: delAtPos
        cin >> op;
        if (op == 1) {
            cin >> val;
            ao.insertBeginning(arr, val);
        } else if (op == 2) {
            cin >> val;
            ao.insertEnd(arr, val);
        } else if (op == 3) {
            int pos;
            cin >> pos >> val;
            ao.insertAtPosition(arr, pos, val);
        } else if (op == 4) {
            ao.deleteBeginning(arr);
        } else if (op == 5) {
            ao.deleteEnd(arr);
        } else if (op == 6) {
            int pos;
            cin >> pos;
            ao.deleteAtPosition(arr, pos);
        }
    }

    ao.printArray(arr);

    return 0;
}
