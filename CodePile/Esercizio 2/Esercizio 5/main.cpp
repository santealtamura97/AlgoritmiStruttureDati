#include <iostream>
#include "pila.h"

using namespace std;

int main()
{
    Pila<char> pila(20);
    char x='a';
    pila.inPila(x);
    x='b';
    pila.inPila(x);
    cout<<pila.leggiPila();
    pila.fuoriPila();
    cout<<pila.leggiPila();
    pila.fuoriPila();
    return 0;
}
