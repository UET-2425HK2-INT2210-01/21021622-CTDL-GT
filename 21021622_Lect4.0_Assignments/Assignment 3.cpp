#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(nullptr), prev(nullptr) {}
};

class Stack {
public:
    Node* top;
    Stack() : top(nullptr) {}
    
    void push(char x) {
        Node* newNode = new Node(x);
        if (top) {
            top->next = newNode;
            newNode->prev = top;
        }
        top = newNode;
    }
    
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->prev;
            if (top) top->next = nullptr;
            delete temp;
        }
    }
    
    char peek() {
        return top ? top->data : '\0';
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

bool isValid(string s) {
    Stack stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else {
            if (stack.isEmpty()) return false;
            char topChar = stack.peek();
            if ((c == ')' && topChar == '(') || (c == ']' && topChar == '[') || (c == '}' && topChar == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string s;
    while (cin >> s) {
        cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
