#include <iostream>
using namespace std;

// Stack using array
class StackArr {
    int *arr, top, capacity;
public:
    StackArr(int size) : capacity(size), top(-1) {
        arr = new int[size];
    }
    ~StackArr() { delete[] arr; }

    void push(int val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n"; return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n"; return;
        }
        cout << "Popped: " << arr[top--] << "\n";
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() { return top == -1; }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n"; return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n";
    }
};

// Queue using linked list
struct QNode {
    int data;
    QNode* next;
    QNode(int v): data(v), next(nullptr) {}
};

class QueueLL {
    QNode *front, *rear;
public:
    QueueLL(): front(nullptr), rear(nullptr) {}

    void enqueue(int val) {
        QNode* n = new QNode(val);
        if (!rear) front = rear = n;
        else {
            rear->next = n;
            rear = n;
        }
    }

    void dequeue() {
        if (!front) {
            cout << "Queue Underflow\n";
            return;
        }
        QNode* t = front;
        front = front->next;
        if (!front) rear = nullptr;
        cout << "Dequeued: " << t->data << "\n";
        delete t;
    }

    bool isEmpty() { return front == nullptr; }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        QNode* curr = front;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n";
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
};

int main() {
    // Stack Array demo
    StackArr st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();
    cout << "Top element: " << st.peek() << "\n";
    st.pop();
    st.display();

    // Queue Linked List demo
    QueueLL q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    cout << "Front element: " << q.peek() << "\n";
    q.dequeue();
    q.display();

    return 0;
}
