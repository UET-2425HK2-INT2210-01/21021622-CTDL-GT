#pseudo-codes
function createQueue(capacity)
    initialize array with size = capacity
    set front = 0, rear = -1, size = 0
end function

function isEmpty()
    return size = 0
end function

function isFull()
    return size = capacity
end function

function enqueue(value)
    if queue is full then
        return
    end if
    rear = (rear + 1) mod capacity
    array[rear] = value
    size = size + 1
end function

function dequeue()
    if queue is empty then
        return
    end if
    front = (front + 1) mod capacity
    size = size - 1
end function

function peek()
    if queue is empty then
        return -1
    end if
    return array[front]
end function

begin
    input n
    if n ≤ 0 or n > 100 then
        print "Kích thước không hợp lệ!"
        return
    end if

    createQueue(n)  
end

#C++ codes:
#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100]; 
    int front, rear, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        front = 0;
        rear = -1;
        size = 0;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }

    void enqueue(int value) {
        if (isFull()) return;
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (isEmpty()) return;
        front = (front + 1) % capacity;
        size--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
};

int main() {
    int n;
    cin >> n;
    
    if (n <= 0 || n > 100) {
        cout << "Kích thước không hợp lệ!\n";
        return 0;
    }

    Queue q(n);  
}

