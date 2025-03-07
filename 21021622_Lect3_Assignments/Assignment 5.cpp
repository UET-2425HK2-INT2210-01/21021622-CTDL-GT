//pseudo-codes
define class Stack
    array: list of integers
    top: integer
    capacity: integer

    function Stack(cap)
        capacity = cap
        top = -1
    end function

    function isEmpty()
        return top = -1
    end function

    function isFull()
        return top = capacity - 1
    end function

    function push(value)
        if isFull() then return
        top = top + 1
        array[top] = value
    end function

    function pop()
        if isEmpty() then return
        top = top - 1
    end function

    function peek()
        if isEmpty() then return -1
        return array[top]
    end function
end class

begin
    input n
    if n ≤ 0 or n > 100 then return

    create Stack s(n)
end

//C++ codes
#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        top = -1;
    }

    bool isEmpty() { return top == -1; }

    bool isFull() { return top == capacity - 1; }

    void push(int value) {
        if (isFull()) return;
        arr[++top] = value;
    }

    void pop() {
        if (isEmpty()) return;
        top--;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[top];
    }
};

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n > 100) {
        return 0;
    }

    Stack s(n);
}
