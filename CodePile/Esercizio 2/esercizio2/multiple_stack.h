#ifndef MULTIPLE_STACK_H_INCLUDED
#define MULTIPLE_STACK_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "stack.h"

using namespace std;

template <class T>
class MultipleStack : public Stack<T>{
public:
    typedef typename Stack<T>::tipoelem tipoelem;
    MultipleStack(unsigned int);
    void Push(tipoelem&,unsigned int);
    tipoelem Pop(unsigned int);

private:
    Stack<tipoelem> * vett;
};

template<class T>
MultipleStack<T>::MultipleStack(unsigned int a){
    vett=new Stack<T>[a];
}

template<class T>
void MultipleStack<T>::Push(tipoelem &b,unsigned int a){
    vett[a].inStack(b);
}

template<class T>
typename MultipleStack<T>::tipoelem MultipleStack<T>::Pop(unsigned int a){
    return vett[a].leggiStack();
}

#endif // MULTIPLE_STACK_H_INCLUDED
