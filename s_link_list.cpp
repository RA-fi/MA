#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void deleteValue(int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->data != val) {
            curr = curr->next;
        }
        if (curr->next) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    SinglyLinkedList list;
    int val;

    cout << "Enter values to insert at end (-1 to stop): ";
    while (cin >> val && val != -1) {
        list.insertEnd(val);
    }

    cout << "List: "; list.display();

    cout << "Total nodes: " << list.countNodes() << "\n";

    cout << "Enter a value to search: ";
    cin >> val;
    cout << (list.search(val) ? "Found\n" : "Not Found\n");

    cout << "Insert at beginning, enter value: ";
    cin >> val;
    list.insertBeginning(val);
    cout << "List after insertion at beginning: ";
    list.display();

    cout << "Insert at end, enter value: ";
    cin >> val;
    list.insertEnd(val);
    cout << "List after insertion at end: ";
    list.display();

    cout << "Enter a value to delete: ";
    cin >> val;
    list.deleteValue(val);
    cout << "List after deletion: ";
    list.display();

    return 0;
}
