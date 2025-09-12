#ifndef STCKTP1_H
#define STCKTP1_H

template <class Type>
class Stack
{
private:
    enum {SIZE = 10};
    int stacksize;
    Type *items;
    int top;
public:
    explicit Stack(int ss = SIZE);
    Stack(const Stack &st);
    ~Stack() { delete[] items; }
    bool isEmpty() const { return top == 0; }
    bool isFull() const { return top == stacksize; }
    bool push(const Type & item);
    bool pop(Type & item);
    Stack & operator=(const Stack & st);
};
template <class Type>
Stack<Type>::Stack(int ss) : stacksize(ss) , top(0) 
{
    items = new Type[stacksize];
}
template <class Type>
Stack<Type>::Stack(const Stack &st) {
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0;i<top;i++)
        items[i] = st.items[i];
}
template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st)
{
    if (this == &st)
        return *this;
    delete[] items;
    stacksize = st.stacksize;
    top = st.top;
    items = new Type[stacksize];
    for(int i = 0; i < top; i++)
        items[i] = st.items[i];
    return *this;
}
template <class Type>
bool Stack<Type>::push(const Type & item)
{
    if (top < stacksize) // is stack full?
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