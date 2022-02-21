//
//  Display 17.19 Implementation of the Stack Template Class
//  stack.cpp
//  AbsoluteCpp_ch17_17
//

//This is the implementation file stack.cpp.
//This is the implementation of the template class Stack.
//The interface for the template class Stack is in the header file
//stack.h

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "stack.h"
using std::cout;

namespace StackSavitch
{

// Uses cstddef:
template<class T>
Stack<T>::Stack():top(NULL)
{
    //Intentionally empty
}

template<class T>
Stack<T>::Stack(const Stack<T>& aStack){
    // do your selft
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rightSide){
    // do your selft
}

template<class T>
Stack<T>::~Stack( )
{
    T next;
    while (! isEmpty( ))
        next = pop( );//pop calls delete.
}

//Uses cstddef:
template<class T>
bool Stack<T>::isEmpty( ) const
{
    return (top == NULL);
}
template<class T>
void Stack<T>::push(T stackFrame){
    // do your selft
}

//Uses cstdlib and iostream:
template<class T>
T Stack<T>::pop( )
{
    if (isEmpty( ))
    {
        cout << "Error: popping an empty stack.\n";
        exit(1);
    }
    
    T result = top->getData( );
    Node<T> *discard;
    discard = top;
    top = top->getLink( );
    delete discard;
    return result;
}
}//StackSavitch
