#ifndef FUNZIONI_H_INCLUDED
#define FUNZIONI_H_INCLUDED

#include "lista.h"
#include "pila.h"
#include "Coda.h"

void converti (List_vector<char> infissa,Coda<char> &coda_post);
void trasferisci(Pila<char> &s,Coda<char> &c,char &top_elem);
int precedenza(char op1,char op2);
int isNumero(char ch);

#endif // FUNZIONI_H_INCLUDED
