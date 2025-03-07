//pseudo-codes
define structure Node
    data: integer
    next: pointer to Node
end structure

define class Stack
    top: pointer to Node

    function Stack()
        top = nullptr
    end function

    function push(x)
        create newNode with data = x
        newNode.next = top
        top = newNode
    end function

    function pop()
        if top is nullptr then return
        temp = top
        top = top.next
        delete temp
    end function

    function printReverse(node)
        if node is nullptr then return
        printReverse(node.next)
        print node.data
    end function

    function print()
        printReverse(top)
    end function
end class

begin
    input n
    create Stack s

    for i = 0 to n - 1 do
        input operation
        if operation = "push" then
            input x
            s.push(x)
        else if operation = "pop" then
            s.pop()
        end if
    end for

    s.print()
end

//C++ codes in Lect2-Assignment5
