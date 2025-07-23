#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void print() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void reverseIterative() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }

    Node* reverseRecursive(Node* node) {
        if (!node || !node->next) return node;
        Node* rest = reverseRecursive(node->next);
        node->next->next = node;
        node->next = nullptr;
        return rest;
    }

    void reverseRecursiveWrapper() {
        head = reverseRecursive(head);
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(4);
    list.insert(3);
    list.insert(2);
    list.insert(1);

    cout << "Original List: ";
    list.print();

    list.reverseIterative();
    cout << "Reversed Iteratively: ";
    list.print();

    list.reverseRecursiveWrapper();
    cout << "Reversed Recursively: ";
    list.print();

    return 0;
}
