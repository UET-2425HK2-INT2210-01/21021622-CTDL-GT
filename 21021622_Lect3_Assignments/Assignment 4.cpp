//pseudo-codes
define structure Node
    data: integer
    next: pointer to Node
end structure

define class Queue
    front: pointer to Node
    rear: pointer to Node

    function Queue()
        front = nullptr
        rear = nullptr
    end function

    function enqueue(x)
        create newNode with data = x
        if rear is nullptr then
            front = rear = newNode
        else
            rear.next = newNode
            rear = newNode
        end if
    end function

    function dequeue()
        if front is nullptr then return
        temp = front
        front = front.next
        if front is nullptr then rear = nullptr
        delete temp
    end function

    function print()
        temp = front
        while temp is not nullptr do
            print temp.data
            temp = temp.next
        end while
    end function
end class

begin
    input n
    create Queue q

    for i = 0 to n - 1 do
        input operation
        if operation = "enqueue" then
            input x
            q.enqueue(x)
        else if operation = "dequeue" then
            q.dequeue()
        end if
    end for

    q.print()
end

//C++ codes in Lect2-Assignment4
