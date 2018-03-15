#ifndef CELLA_H_INCLUDED
#define CELLA_H_INCLUDED

#include <iostream>

template<class T>
class Cella{
public:
    typedef T tipoelem;
    Cella();
    Cella(tipoelem);

    void setElemento(tipoelem);
    tipoelem getElemento() const;

    void setPrimoFiglio(Cella<T>*);
    void setProxFratello(Cella<T>*);
    void setPadre(Cella<T>*);
    void setMarcato();
    void setNumNodi(int);
    void desetMarcato();
    Cella<T>* getPrimoFiglio() const;
    Cella<T>* getProxFratello() const;
    Cella<T>* getPadre() const;
    bool getMarcato() const;
    int getNumNodi() const;

    bool operator==(Cella<T>);
    bool operator<=(Cella<T>);
private:
    tipoelem elemento;
    Cella<T>*primoFiglio;
    Cella<T>*proxFratello;
    Cella<T>*padre;
    bool marcato;
    int numNodi;
};

//implementazione della classe Cella

template<class T>
Cella<T>::Cella(){
    primoFiglio=NULL;
    proxFratello=NULL;
    padre=NULL;
}

template<class T>
void Cella<T>::setElemento(tipoelem etichetta){
    elemento=etichetta;
}

template<class T>
T Cella<T>::getElemento() const{
    return elemento;
}

template<class T>
void Cella<T>::setMarcato(){
    marcato=true;
}

template<class T>
void Cella<T>::desetMarcato(){
    marcato=false;
}

template<class T>
bool Cella<T>::getMarcato() const{
    return marcato;
}

template<class T>
void Cella<T>::setNumNodi(int n){
    numNodi=n;
}

template<class T>
int Cella<T>::getNumNodi() const{
    return numNodi;
}

template<class T>
void Cella<T>::setPrimoFiglio(Cella<T>*p){
    primoFiglio=p;
}

template<class T>
void Cella<T>::setProxFratello(Cella<T>*p){
    proxFratello=p;
}

template<class T>
void Cella<T>::setPadre(Cella<T>*p){
    padre=p;
}

template <class T>
Cella<T>* Cella<T>::getPrimoFiglio() const{
     return primoFiglio; // return SX;
}

template <class T>
Cella<T>* Cella<T>::getProxFratello() const{
    return proxFratello; // return DX;
}

template <class T>
Cella<T>* Cella<T>::getPadre() const{
    return padre; // return DAD;
}

#endif // CELLA_H_INCLUDED
