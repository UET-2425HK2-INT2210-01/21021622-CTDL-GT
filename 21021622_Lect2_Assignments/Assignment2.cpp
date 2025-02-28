#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}
    
    void insert(int p, int x) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != nullptr && i < p - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void remove(int p) {
        if (head == nullptr) return;
        Node* temp = head;
        if (p == 0) {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; temp != nullptr && i < p - 1; i++) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
    
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        } else if (operation == "delete") {
            int p;
            cin >> p;
            list.remove(p);
        }
    }
    list.print();
    return 0;
}
