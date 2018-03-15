#ifndef POLINOMIO_H_INCLUDED
#define POLINOMIO_H_INCLUDED

#include "list_vector.h"
#include <cmath>
#include <cstdlib>

template<class T>
class polynomial{
public:
    typedef T tipoelem;
    polynomial(); //costruisce un polinomio di grado 0
    void input(int,tipoelem coefficienti[]); //acquisisce un polinomio sotto forma di grado e di una serie di elementi,che sono i coefficienti
    void output();//visualizza il polinomio
    void somma(const polynomial<tipoelem> &a);
    void moltiplica( polynomial<tipoelem> &b);
    int grado(); //restituisce il grado di un polinomio
    tipoelem valore(tipoelem x); // restituisce il valore del polinomio nel punto x
    tipoelem potenza(tipoelem x,int); //calcola la potenza con base x ed esponente int
    void cancella_polinomio(); //pone a zero tutti i coefficienti del polinomio
    polynomial<T>& operator=(const polynomial<T>&); // operatore di assegnamento
private:
    List_vector<tipoelem> polinomio; //lista di elementi di tipo tipoelem
    int grade; //grado del polinomio
};

template<class T>
polynomial<T>::polynomial(){
    polinomio;
    grade=0;
}

template<class T>
int polynomial<T>::grado(){
    return grade;
}

template<class T>
void polynomial<T>::input(int grad,tipoelem coefficienti[]){
    for(int i=0;i<=grad;i++){
        polinomio.insert(coefficienti[i],i+1);
    }
    grade=grad;
}

template<class T>
void polynomial<T>::output(){
    using namespace std;
    cout<<"\n\nIl polinomio e': ";
    for(int i=grade;i>=0;i--){
            if(polinomio.read(i+1)!=0){
                if(i==0){
                 if(polinomio.read(i+1)>=0)
            cout<<"+ "<<polinomio.read(i+1);
        else
            cout<<polinomio.read(i+1);
            }else{
                 if(polinomio.read(i+1)>=0)
            cout<<"+ "<<polinomio.read(i+1)<<"x^"<<i<<" ";
        else
            cout<<polinomio.read(i+1)<<"x^"<<i<<" ";
            }
            }
    }
    cout<<"\n";
}

template<class T>
void polynomial<T>::somma(const polynomial<tipoelem>& add){
    int i=0;
    tipoelem somma;
    this->polinomio.change_dimension_(this->polinomio.elements_,this->polinomio.getArrayDimension(),this->polinomio.getArrayDimension()+10);
    while(i<=this->grade && i<=add.grade){
        somma=this->polinomio.read(i+1) + add.polinomio.read(i+1);
        this->polinomio.write(somma,i+1);
        i++;
    }
    if(add.grade>this->grade){
        while(i<=add.grade){
            this->polinomio.write(add.polinomio.read(i+1),i+1);
            i++;
            this->grade++;
        }
    }
}

template<class T>
typename polynomial<T>::tipoelem polynomial<T>::valore(tipoelem x){
    tipoelem valore=0;
    for(int i=0;i<=grade;i++){
        valore = valore+(potenza(x,i)*polinomio.read(i+1));
    }
    return valore;
}

template<class T>
typename polynomial<T>::tipoelem polynomial<T>::potenza(tipoelem x,int esp){
    tipoelem potenza=x;
    if(esp==0)
        potenza=1;
    else{
        for(int i=1;i<esp;i++)
        potenza=potenza*x;
    }
    return potenza;
}
template<class T>
void polynomial<T>::cancella_polinomio(){
    for(int i=0;i<=grade;i++)
        polinomio.write(0,i+1);
}

template<class T>
polynomial<T>& polynomial<T>::operator=(const polynomial<T>& p){
   this->polinomio=p.polinomio;
   this->grade=p.grade;
}


template<class T>
void polynomial<T>::moltiplica( polynomial<tipoelem>& moltiplicatore){
    tipoelem prodotto;
    int esp_prodotto;
    polynomial<tipoelem> prod;
    this->polinomio.change_dimension_(this->polinomio.elements_,this->polinomio.getArrayDimension(),this->polinomio.getLenght_()*moltiplicatore.polinomio.getLenght_());
    for(int i=0;i<=this->grade;i++){
         for(int j=0;j<=moltiplicatore.grade;j++){
            prodotto=this->polinomio.read(i+1)*moltiplicatore.polinomio.read(j+1);
            esp_prodotto=i+j;
            if(esp_prodotto<prod.grade){
                prod.polinomio.insert(prodotto+prod.polinomio.read(esp_prodotto+1),esp_prodotto+1);
            }else{
                prod.polinomio.insert(prodotto,esp_prodotto+1);
                prod.grade=prod.grade+(esp_prodotto-prod.grade);
            }
        }
    }
    this->cancella_polinomio();
    this->polinomio=prod.polinomio; //chiamata ad operatore di assegnamento delle liste
    this->grade=prod.grade;
}



#endif // POLINOMIO_H_INCLUDED
