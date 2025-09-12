#ifndef STACKTP_H
#define STACKTP_H

template <class Type>
class Stack 
{
private:
    enum { MAX = 10 }; // default size of stack
    Type items[MAX];   // holds stack items
    int top;           // index for top stack item
public:
    Stack();           // constructor
    bool isEmpty();
    bool isFull();
    bool push(const Type & item); // add item to stack
    bool pop(Type & item);         // pop top into item

};

template <class Type>
Stack<Type>::Stack() 
{
    top = 0; // initialize stack to empty
}
template <class Type>
bool Stack<Type>::isEmpty()
{
    return top == 0; // true if stack is empty
}
template <class Type>
bool Stack<Type>::isFull()
{
    return top == MAX; // true if stack is full
}
template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < MAX) // is stack full?
    {
        items[top++] = item; // add item to stack
        return true; // success
    }
    else
    {
        return false; // stack is full
    }
}
template <class Type>
bool Stack<Type>::pop(Type & item)
{
    if (top > 0) // is stack empty?
    {
        item = items[--top]; // remove item from stack
        return true; // success
    }
    else
    {
        return false; // stack is empty
    }
}
#endif