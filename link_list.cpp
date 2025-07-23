#include <iostream>
using namespace std;

// ---------- Singly Linked List using Class ----------
class SinglyLinkedList {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int d) : data(d), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val) {
        Node* temp = head;
        Node* prev = nullptr;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) return;
        if (!prev) head = temp->next;
        else prev->next = temp->next;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    bool search(int val) {
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void removeDuplicatesSorted() {
        Node* temp = head;
        while (temp && temp->next) {
            if (temp->data == temp->next->data) {
                Node* dup = temp->next;
                temp->next = dup->next;
                delete dup;
            } else {
                temp = temp->next;
            }
        }
    }
};

// ---------- Doubly Linked List using Class ----------
class DoublyLinkedList {
private:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;
        Node(int d) : data(d), prev(nullptr), next(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayBackward() {
        Node* temp = head;
        if (!temp) return;
        while (temp->next) temp = temp->next;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* curr = head;
        while (curr) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp) head = temp->prev;
    }

    int count() {
        int cnt = 0;
        Node* temp = head;
        while (temp) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    int search(int val) {
        int index = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == val) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void updateValue(int oldVal, int newVal) {
        Node* temp = head;
        while (temp) {
            if (temp->data == oldVal) {
                temp->data = newVal;
                return;
            }
            temp = temp->next;
        }
    }

    bool isPalindrome() {
        if (!head) return true;
        Node* left = head;
        Node* right = head;
        while (right->next) right = right->next;
        while (left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};

// ---------- Main Function ----------
int main() {
    cout << "=== Singly Linked List ===\n";
    SinglyLinkedList sll;
    sll.insertAtEnd(1);
    sll.insertAtEnd(2);
    sll.insertAtEnd(2);
    sll.insertAtEnd(3);
    sll.insertAtBeginning(0);
    cout << "List: "; sll.display();
    sll.deleteValue(2);
    cout << "After deleting 2: "; sll.display();
    cout << "Count: " << sll.count() << endl;
    cout << "Search 3: " << (sll.search(3) ? "Found" : "Not found") << endl;
    sll.reverse(); cout << "Reversed: "; sll.display();
    sll.removeDuplicatesSorted(); cout << "No Duplicates: "; sll.display();

    cout << "\n=== Doubly Linked List ===\n";
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(2);
    dll.insertAtEnd(1);
    cout << "Forward: "; dll.displayForward();
    cout << "Backward: "; dll.displayBackward();
    dll.reverse(); cout << "Reversed: "; dll.displayForward();
    cout << "Count: " << dll.count() << endl;
    cout << "Search 3: " << (dll.search(3) != -1 ? "Found" : "Not found") << endl;
    dll.updateValue(3, 99); cout << "Updated: "; dll.displayForward();
    cout << "Is Palindrome? " << (dll.isPalindrome() ? "Yes" : "No") << endl;

    return 0;
}
