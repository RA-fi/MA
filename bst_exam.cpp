#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

class BST {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int stepCount;

    BST() : root(nullptr), stepCount(0) {}

    Node* insert(Node* node, int val) {
        stepCount++;
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    void insert(int val) {
        root = insert(root, val);
    }

    int getSteps() const { return stepCount; }
};

int insertToArray(vector<int>& arr, int val) {
    int steps = 0;
    int i = arr.size() - 1;
    while (i >= 0 && arr[i] > val) {
        steps++;
        i--;
    }
    arr.insert(arr.begin() + i + 1, val);
    return steps;
}

int main() {
    srand(time(0));
    vector<int> sortedData;
    for (int i = 0; i < 50; ++i)
        sortedData.push_back(rand() % 100);

    sort(sortedData.begin(), sortedData.end());

    // Insert into array
    vector<int> arr;
    int arraySteps = 0;
    for (int val : sortedData) {
        arraySteps += insertToArray(arr, val);
    }

    // Insert into BST
    BST tree;
    for (int val : sortedData) {
        tree.insert(val);
    }

    cout << "Total steps for array insertion: " << arraySteps << endl;
    cout << "Total steps for BST insertion: " << tree.getSteps() << endl;

    return 0;
}
