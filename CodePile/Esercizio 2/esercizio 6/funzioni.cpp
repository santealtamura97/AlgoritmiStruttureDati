#include<iostream>
#include<stdlib.h>
#include "funzioni.h"
#include "pila.h"
#include "lista.h"
#include "Coda.h"
#include <ctype.h>

void trasferisci(Pila<char> &s,Coda<char> &c,char &top_elem){

    top_elem=s.leggiPila();
    s.fuoriPila();
    c.inCoda(top_elem);

}

int isNumero(char ch){
    /*restituisce vero se il ch è un operando
    falso altrimenti*/
    return(((ch>='a')&&(ch<='z'))||
           ((ch>='A')&& (ch<='Z'))||
           ((ch>='0')&& (ch<='9')));
}


int precedenza(char op1,char op2){

    /*restituisce 1 se op1 ha precedenza su op2
    oppure 0 altrimenti*/
    if(op1=='(') return 0;
    else
        if(op2=='(') return 0;
    if(op2==')') return 1;
    else
        if((op1=='*') || (op1=='/')) return 1;
    else
        if((op2=='*') || (op2=='/')) return 0;
    else return 0;
}
void converti (List_vector<char> infissa,Coda<char> &coda_post){

    char t;
    char top_elem;
    Pila<char> pila_op;
    coda_post.creaCoda(50);
    int position=infissa.begin();
    while(!infissa.end(position)){
        t=infissa.read(position);
        if(isNumero(t))
            pila_op.inPila(t);
        else if(pila_op.pilaVuota()){
            pila_op.inPila(t);
        }
        else if(t=='(')
            pila_op.inPila(t);
        else if(t==')'){
             top_elem=pila_op.leggiPila();
             while(top_elem!='(')
                    trasferisci(pila_op,coda_post,top_elem);
             pila_op.fuoriPila();
        }

        else{
            while(precedenza(top_elem,t)==1){
                trasferisci(pila_op,coda_post,top_elem);
            }

            pila_op.fuoriPila();
        }

        position++;
    }

    while(!pila_op.pilaVuota())
        trasferisci(pila_op,coda_post,top_elem);
}
