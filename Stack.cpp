#include "Stack.h"
#include <iostream>
using namespace std;

/*template<typename T>
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
        elements[count++] = value;
    else
        cout << "overflow!" << endl;
}

template<typename T>
void Stack<T>::pop()
{
    if(!empty())
        count--;
    else
        cout << "underflow!" << endl;

}*/
