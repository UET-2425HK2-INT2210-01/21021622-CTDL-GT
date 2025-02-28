#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    int count_triplets() {
        if (!head || !head->next || !head->next->next) return 0;
        int count = 0;
        Node* curr = head->next;
        while (curr->next) {
            if (curr->prev->data + curr->data + curr->next->data == 0) {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }
};

int main() {
    int n;
    cin >> n;
    
    DoublyLinkedList dll;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        dll.append(num);
    }
    
    cout << dll.count_triplets() << endl;
    
    return 0;
}
