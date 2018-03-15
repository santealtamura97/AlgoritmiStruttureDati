#ifndef CELLA_H_INCLUDED
#define CELLA_H_INCLUDED

template <class T>
class Cella{
public:
    typedef T tipoelem;
    Cella(); //costruttore
    void setElemento(tipoelem);
    tipoelem getElemento() const;

    void setSX(Cella<T>* sx);
    void setDX(Cella<T>* dx);
    void setDAD(Cella<T>* dad);
    void setNumeroNodi(int);
    Cella<T>* getSX() const;
    Cella<T>* getDX() const;
    Cella<T>* getDAD() const;
    int getNumeroNodi();

    bool operator ==(Cella<T>);
    bool operator <=(Cella<T>);
private:
     /*La classe Cella<T> è formata a
    sua volta da puntatori a classe
    di tipo Cella<T>*/
    int altezza=0;//altezza della cella
    int livello=0;//livello della cella
    int numeroNodi=0; //numero dei nodi del sottoalbero della cella
    tipoelem elemento;
    Cella<T>* SX;
    Cella<T>* DX;
    Cella<T>* DAD;
};

//implementazione classe cella
template<class T>
Cella<T>::Cella(){
    SX=NULL;
    DX=NULL;
    DAD=NULL;
}

template<class T>
void Cella<T>::setElemento(tipoelem etichetta){
    elemento=etichetta;
}

template<class T>
typename Cella<T>::tipoelem Cella<T>::getElemento() const{
    return elemento;
}

template<class T>
void Cella<T>::setSX(Cella<T>* sx){
    SX=sx;
}

template<class T>
void Cella<T>::setDX(Cella<T>* dx){
    DX=dx;
}

template<class T>
void Cella<T>::setDAD(Cella<T>* dad){
    DAD=dad;
}

template <class T>
Cella<T>* Cella<T>::getSX() const{
    return SX;
}

template <class T>
Cella<T>* Cella<T>::getDX() const{
     return DX;
}

template <class T>
Cella<T>* Cella<T>::getDAD() const{
    return DAD;
}

//sovraccarico di operatori
template<class T>
bool Cella<T>::operator<=(Cella<T> cella){
    return (this->getElemento()<=cella.getElemento());
}

template<class T>
bool Cella<T>::operator==(Cella<T> cella){
    return(this->getElemento()==cella.getElemento());
}

template<class T>
void Cella<T>::setNumeroNodi(int nNodi){
    numeroNodi=nNodi;
}

template<class T>
int Cella<T>::getNumeroNodi(){
    return numeroNodi;
}





#endif // CELLA_H_INCLUDED
