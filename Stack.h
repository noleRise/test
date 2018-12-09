#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:

    Stack();
    ~Stack();
    bool empty();
    bool full();
    T peek();
    void push(T);
    void pop();

private:
    T* elements;
    int count;
    int capacity;


};

template<typename T>
Stack<T>::Stack():count(0),capacity(20)
{
    elements = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
    delete [] elements;
}

template<typename T>
bool Stack<T>::empty()
{
    return count == 0;
}

template<typename T>
bool Stack<T>::full()
{
    return count == capacity;
}

template<typename T>
T Stack<T>::peek()
{
    return elements[count-1];
}

template<typename T>
void Stack<T>::push(T value)
{
    if(full())
        cout << "overflow!" << endl;
    else
        elements[count++] = value;
}

template<typename T>
void Stack<T>::pop()
{
    if(empty())
        cout << "underflow!" << endl;
    else
        count--;
}
#endif // STACK_H_INCLUDED
