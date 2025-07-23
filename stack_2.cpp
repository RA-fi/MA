#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Stack {
    char arr[100];
    int top;
    int capacity;
public:
    Stack(int size=100) : top(-1), capacity(size) {}

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }

    void push(char x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack Empty\n";
            return '\0';
        }
        return arr[top];
    }
};

// Check balanced parentheses
bool BalancedParentheses(const string& expr) {
    stack<char> s;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) return false;
            char top = s.top();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
            s.pop();
        }
    }
    return s.empty();
}

// Reverse string using stack
string ReverseString(const string& str) {
    stack<char> s;
    for (char ch : str) s.push(ch);
    string rev;
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }
    return rev;
}

// Check palindrome using stack
bool PalindromeCheck(const string& str) {
    stack<char> s;
    for (char ch : str) s.push(ch);
    for (char ch : str) {
        if (ch != s.top()) return false;
        s.pop();
    }
    return true;
}

int main() {
    Stack s;

    s.push('A');
    s.push('B');
    s.push('C');
    cout << "Top element is: " << s.peek() << endl;
    cout << "Popped element is: " << s.pop() << endl;
    cout << "Top element is: " << s.peek() << endl;

    string expression;
    cout << "Enter an expression with parentheses: ";
    getline(cin, expression);
    cout << (BalancedParentheses(expression) ? "Balanced\n" : "Not Balanced\n");

    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);
    cout << "Reversed string: " << ReverseString(str) << endl;

    cout << "Enter a string to check for palindrome: ";
    getline(cin, str);
    cout << (PalindromeCheck(str) ? "Palindrome\n" : "Not Palindrome\n");

    return 0;
}
