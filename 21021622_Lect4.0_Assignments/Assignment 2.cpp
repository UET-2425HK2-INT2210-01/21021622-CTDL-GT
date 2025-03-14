#include <iostream>

using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node(int v, int p) : value(v), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;
public:
    PriorityQueue() : head(nullptr) {}
    
    void enqueue(int x, int p) {
        Node* newNode = new Node(x, p);
        if (!head || p > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= p) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    void dequeue() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void printQueue() {
        Node* temp = head;
        bool first = true;
        while (temp) {
            if (!first) cout << "; ";
            cout << "(" << temp->value << ", " << temp->priority << ")";
            first = false;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    PriorityQueue pq;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }
    
    pq.printQueue();
    return 0;
}
