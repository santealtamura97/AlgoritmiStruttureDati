#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;


template <class Elemento>
class Stack
  {
  public:
    typedef Elemento tipoelem;
    Stack();
    Stack(int);
    ~Stack();
    void creaStack();
    bool StackVuota() const;
    tipoelem leggiStack() const;
    void fuoriStack();
    void inStack(tipoelem);
  private:
    tipoelem *elementi;
    int MAXLUNGH;
    int testa;
  };

template <class Elemento>
Stack<Elemento>::Stack()
{
  elementi = new tipoelem[100]; // dimensione standard della Stack
  MAXLUNGH = 100;
  creaStack();
}

template <class Elemento>
Stack<Elemento>::Stack(int N)
{
  elementi = new tipoelem[N]; // dimensione N della Stack
  MAXLUNGH = N;
  creaStack();
}

template <class Elemento>
Stack<Elemento>::~Stack()
{
  delete[] elementi;
};

template <class Elemento>
void Stack<Elemento>::creaStack()
{
  testa=0;
}

template <class Elemento>
bool Stack<Elemento>::StackVuota() const
  {
    return testa==0;
  }

template <class Elemento>
Elemento Stack<Elemento>::leggiStack() const
  {
    return elementi[testa-1];
  }

template <class Elemento>
void Stack<Elemento>::fuoriStack()
{
  if (!StackVuota())
    {
      testa-=1;
    }
  else
    {
      cout<<"nessun elemento nella Stack"<<endl;
    }
}

template <class Elemento>
void Stack<Elemento>::inStack(tipoelem el)
{
  if (testa==MAXLUNGH)
    {
      cout<<"raggiunta capacitÃ  massima della Stack"<<endl;
    }
  else
    {
      elementi[testa]=el;
      testa++;
    }
}

#endif // STACK_H_INCLUDED
