#ifndef ALBERON_H_INCLUDED
#define ALBERON_H_INCLUDED

#include "cella.h"
#include "coda.h"
#include <cassert>
#include <limits.h>
#include <iostream>

using namespace std;

template<class T>
class Albero{
public:

    //tipi
    typedef T tipoelem;
    typedef Cella<T>* Nodo;
    //costruttori e distruttori
    Albero();
    //operatori
    void creaAlbero();
    bool alberoVuoto();
    void insRadice(Nodo);
    void insPrimoFiglio(Nodo);
    void insFratello(Nodo);
    Nodo radiceAlbero();
    Nodo padre(Nodo);
    Nodo primoFiglio(Nodo);
    Nodo succFratello(Nodo);
    bool ultimoFratello(Nodo);
    void insPrimoSottoAlbero(Nodo,Albero<T>&);//inserisce il sotto albero come primo figlio di Nodo
    void insSottoAlbero(Nodo,Albero<T>&);//inserisce il sotto albero come succFratello di Nodo
    void cancSottoAlbero(Nodo);
    bool foglia(Nodo);//stabilisce se Nodo è foglia
    //operazioni elementari
    tipoelem leggiNodo(Nodo);
    void scriviNodo(Nodo,tipoelem);
    //SERVIZIO
    void stampaAlbero();//stampa albero dalla radice
    void stampaSottoAlbero(Nodo);//stampa albero dal Nodo
    void stampaPreOrdine(Nodo);//stampa l'albero dal Nodo in preordine
    void stampaPostOrdine(Nodo);//stampa l'albero dal Nodo in post Ordine
    void stampaSimmetrica(Nodo);//stamoa l'albero in simmetria dal Nodo
    int profondita(Nodo); //calcola la profondità dell'albero
    void stampaBFS(Nodo);//stampa in ampiezza dell'albero
    int larghezza(Nodo);
    int contaNodi(Nodo);
    void foglieK(Nodo u,int somma,int k);
    int numFoglie(Nodo);
    void n_livello(Nodo,int k,int&);
    bool pariDispari(Nodo);//verifica se ogni nodo pari ha solo figli dispari

    tipoelem maxAlbero(Nodo);//restituisce il valore massimo contenuto in albero
    int altezza(Nodo);//restituisce l'altezza dell'albero
    int nodiKfigli(Nodo,int k);//calcola il numero di nodi con k figli
    bool tuttiPari(Nodo);//verifica se tutti i valori dei nodi sono pari partendo dal Nodo
    int livello(Nodo);//restituisce il livello di un nodo
    bool trovaElemento(Nodo,T valore);//verifica che valore appartiene all'albero
    int altezzaMinimale(Nodo n);
    void cancellaPrimoFiglio(Nodo n);
    void cancellaSuccFratello(Nodo n);
    bool appartiene(Nodo u,Nodo n);//controlla se Nodo u appartiene all'albero partendo la ricerca dal Nodo n
private:
    void altezzaMinimale(Nodo n,int &minAltezza);
    Nodo radice;
    void deleteMarcato(Nodo);//mette a false tutti i nodi
};

template<class T>
Albero<T>::Albero(){
    creaAlbero();
}

template<class T>
void Albero<T>::creaAlbero(){
    radice=NULL;
}

template<class T>
bool Albero<T>::alberoVuoto(){
    return(radice==NULL);
}

template<class T>
void Albero<T>::insRadice(Nodo r){
    assert(alberoVuoto());//l'albero deve essere vuoto per poter inserire la radice
    radice=r;
}

template<class T>
Cella<T>* Albero<T>::radiceAlbero(){
    assert(!alberoVuoto());
    return radice;
}

template<class T>
Cella<T>* Albero<T>::padre(Nodo n){
    assert(n!=radiceAlbero()); // n non è radice
    return n->getPadre();
}

template<class T>
bool Albero<T>::foglia(Nodo n){
    if(n->getPrimoFiglio()==NULL)
        return true;
    return false;
}

template<class T>
Cella<T>* Albero<T>::primoFiglio(Nodo n){
    return (n->getPrimoFiglio());
}

template<class T>
bool Albero<T>::ultimoFratello(Nodo n){
    return (n->getProxFratello()==NULL);
}

template<class T>
Cella<T>* Albero<T>::succFratello(Nodo n){
    return (n->getProxFratello());
}

template<class T>
void Albero<T>::insPrimoSottoAlbero(Nodo n,Albero<T>& A){

    A.radiceAlbero()->setProxFratello(n->getPrimoFiglio());//quello che era il primo figlio di n diventa succFratello della radice dell'albero A
    A.radiceAlbero()->setPadre(n); //n diventa padre della radice di A
    n->setPrimoFiglio(A.radiceAlbero());//la radice di A diventa il primo figlio di n
}

template<class T>
void Albero<T>::insSottoAlbero(Nodo n,Albero<T>& A){

    A.radiceAlbero()->setProxFratello(n->getProxFratello());//quello che era il succFratello di n diventa il succFratello della radice di A
    A.radiceAlbero()->setPadre(n->getPadre());//quello che era il padre di n diventa anche il padre della radice di A
    n->setProxFratello(A.radiceAlbero());//il succFratello di n diventa la radice dell'albero A
}

template<class T>
T Albero<T>::leggiNodo(Nodo n){
    return(n->getElemento());
}

template <class T>
void Albero<T>::scriviNodo(Nodo n,tipoelem a){
    n->setElemento(a);
}

template<class T>
void Albero<T>::stampaSottoAlbero(Nodo u){
    cout<<"\n "<<leggiNodo(u)<<" :";

        Nodo c=primoFiglio(u);
        while(c!=NULL){
            cout<<" "<<leggiNodo(c);
            c=succFratello(c);
        }
        c=primoFiglio(u);
        while(c!=NULL){
            stampaSottoAlbero(c);
            c=succFratello(c);
        }

}

template<class T>
void Albero<T>::stampaAlbero(){
    cout<<"\n*****STAMPA DELL'ALBERO*****\n";
    if(!alberoVuoto()){
        cout<<"{\n";
        stampaSottoAlbero(radiceAlbero());
        cout<<"\n\n}";
    }
}

template<class T>
void Albero<T>::insPrimoFiglio(Nodo u){
    u->setPrimoFiglio(new Cella<T>);
    primoFiglio(u)->setPadre(u);
}

template<class T>
void Albero<T>::insFratello(Nodo u){
    u->setProxFratello(new Cella<T>);
    succFratello(u)->setPadre(padre(u));
}

template<class T>
void Albero<T>::stampaPreOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        cout<<" "<<leggiNodo(u);
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPreOrdine(temp);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
void Albero<T>::stampaPostOrdine(Nodo u){
    Nodo temp;
    if(u!=NULL){
        temp=primoFiglio(u);
        while(temp!=NULL){
            stampaPostOrdine(temp);
            temp=succFratello(temp);
        }
    }
    cout<<" "<<leggiNodo(u);
    return;
}

template<class T>
void Albero<T>::stampaSimmetrica(Nodo u){
    Nodo temp;
    if(foglia(u)){
        cout<<" "<<leggiNodo(u);
    }else{
        temp=primoFiglio(u);
        stampaSimmetrica(temp);
        cout<<" "<<leggiNodo(u);
        temp=succFratello(temp);
        while(temp!=NULL){
            stampaSimmetrica(temp);
            temp=succFratello(temp);
        }
    }
}

template<class T>
void Albero<T>::cancSottoAlbero(Nodo n){
    cout<<"\nEntro nella procedura per eliminare nodo:"<<n->getElemento();
    //spezzo i legami tra n, il padre ed i fratelli
    if(radiceAlbero()==n)
        delete radiceAlbero();
    else{
        if(n==primoFiglio(padre(n))){//se n è il primo figlio
            if(ultimoFratello(n))//e non ha fratelli
                padre(n)->setPrimoFiglio(NULL);
            else//altrimenti ha un fratello che diventa primo figlio
                padre(n)->setPrimoFiglio(succFratello(n));
        }else{
            Nodo prec=primoFiglio(padre(n));
            Nodo current=succFratello(prec);
            while(current!=n){
                prec=current;
                current=succFratello(current);
            }
            if(ultimoFratello(n))
                prec->setProxFratello(NULL);
            else
                prec->setProxFratello(succFratello(n));
        }
    }
    delete n;
    contaNodi(radiceAlbero());
}
template<class T>
int Albero<T>::profondita(Nodo u){
    Nodo v;
    int massimo,temp;
    if(foglia(u))
        return 0;
    else{
        v=primoFiglio(u);
        massimo=0;
        while(v!=NULL){
            temp=profondita(v);
            if(massimo<=temp)
                massimo=temp;
            v=succFratello(v);
        }
        return massimo+1;
    }
}

template<class T>
void Albero<T>::deleteMarcato(Nodo n){
    Nodo temp;
    if(n!=NULL){
        if(n->getMarcato())
            n->desetMarcato();
        temp=primoFiglio(n);
        while(temp!=NULL){
            deleteMarcato(temp);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
void Albero<T>::stampaBFS(Nodo v){
    deleteMarcato(radiceAlbero());//pone a false tutti i marcati
    Coda<Nodo> C(contaNodi(radiceAlbero()));
    C.inCoda(v);
    v->setMarcato();
    Nodo t;
    while(!C.codaVuota()){
        t=C.leggiCoda();
        C.fuoriCoda();
        cout<<" "<<leggiNodo(t)<<"("<<t->getNumNodi()<<")";
        Nodo u=primoFiglio(t);
        while(u!=NULL){
            if(!u->getMarcato()){
                u->setMarcato();
                C.inCoda(u);
            }
            u=succFratello(u);
        }
    }
}
/*notando che quando tutti i nodi di un livello vengono
 estratti dalla coda, la coda contiene solo e
unicamente i nodi del livello successivo.
Basta quindi utilizzare la dimensione della coda
come misuratore
della larghezza del livello, e confrontarla con la larghezza
massima trovata fino ad ora. Non solo, il valore
della larghezza puo essere copiato nella variabile  conteggio,
 e utilizzato per scoprire quando sara terminato il
prossimo livello. Il costo di questa funzione, piu elegante
 della precedente,  e sempre  O(n), ma in questo
caso non e' richiesta memoria aggiuntiva pari ad  O(n),
ma solo pari a O(l), dove l e' la massima larghezza.*/
template<class T>
int Albero<T>::larghezza(Nodo t){
    if(t==NULL)
        return 0;
    int conteggio=1;
    int larghezza=1;
    Coda<Nodo> Q(30);
    Q.inCoda(t);
    while(!Q.codaVuota()){
        Nodo u=Q.leggiCoda();
        Q.fuoriCoda();
        Nodo v=primoFiglio(u);
        while(v!=NULL){
            Q.inCoda(v);
            v=succFratello(v);
        }
        conteggio=conteggio-1;
        if(conteggio==0){
            conteggio=Q.Size();
            larghezza=max(larghezza,conteggio);
        }
    }
    return larghezza;
}

/*Dato un albero N-ario si vuole memorizzare in ciascun campo
''numNodi'' di ogni nodo il numero di nodi radicati nel suo sottoalbero*/
template<class T>
int Albero<T>::contaNodi(Nodo u){
    int conteggio=0;
    Nodo temp;
    if(u!=NULL){
        if(foglia(u)){
            u->setNumNodi(1);
            conteggio++;
        }else{
            conteggio++;
            temp=primoFiglio(u);
            while(temp!=NULL){
                conteggio=conteggio+contaNodi(temp);
                temp=succFratello(temp);
            }
            u->setNumNodi(conteggio);
        }
    }
    return conteggio;
}

/*Dato un albero ordinato i cui nodi contengono valori interi
si vogliono cancellare tutte le foglie per il quale il percorso radice-foglia
ha somma complessiva uguale a k*/
template<class T>
void Albero<T>::foglieK(Nodo u,int somma,int k){
    Nodo v;
    if(!foglia(u)){
        v=primoFiglio(u);
        while(v!=NULL){
            foglieK(v,somma+ leggiNodo(u),k);
            v=succFratello(v);
        }
    }else{
        if(somma+leggiNodo(u)==k)
            cancSottoAlbero(u);
    }
}

template<class T>
/*Restituisce il numero di foglie presenti nell'albero n ario*/
int Albero<T>::numFoglie(Nodo t){
  if(t==NULL)
    return 0;
  if(primoFiglio(t)==NULL)
    return 1+numFoglie(succFratello(t));
  else
    return (numFoglie(primoFiglio(t))+numFoglie(succFratello(t)));
}

template<class T>
T Albero<T>::maxAlbero(Nodo n){
    assert(!alberoVuoto());
    tipoelem currMax;
    tipoelem massimo=n->getElemento();
    Nodo temp=primoFiglio(n);
    while(temp!=NULL){
        currMax=maxAlbero(temp);
        if(currMax>massimo)
            massimo=currMax;
        temp=succFratello(temp);
    }
    return massimo;
}


template<class T>
int Albero<T>::altezza(Nodo n){
    int maxAltezza=0;
    Nodo temp=primoFiglio(n);
    while(temp!=NULL){
        int t=altezza(temp)+1;
        if(t>maxAltezza)
            maxAltezza=t;
        temp=succFratello(temp);
    }
    return maxAltezza;
}

template<class T>
int Albero<T>::nodiKfigli(Nodo n,int k){
    int k1=0;
    Nodo temp;
    if(n==NULL)
        return 0;
    else{

        temp=primoFiglio(n);
        while(temp!=NULL){
            k1++;
            temp=succFratello(temp);
        }
        if(k==k1)
            return(1+nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k));
        else
            return (nodiKfigli(succFratello(n),k)+nodiKfigli(primoFiglio(n),k));
    }
}

template<class T>
int Albero<T>::livello(Nodo n){
    int Livel;
    //restituisce il livello di n
    //se n è radice il livello è 0
    if(n==radiceAlbero())
        return 0;
    else{
        Livel=1;
        Nodo temp=padre(n);
        while(temp!=radiceAlbero()){
            Livel++;
            temp=padre(temp);
        }
    }
    return Livel;
}

/*restituisci il numero di nodi di livello k*/
template<class T>
void Albero<T>::n_livello(Nodo u,int k,int& numero){
    Nodo temp;
    if(u!=NULL){
        if(livello(u)==k){
            numero++;
        }
        temp=primoFiglio(u);
        while(temp!=NULL){
            n_livello(temp,k,numero);
            temp=succFratello(temp);
        }
    }
    return;
}

template<class T>
bool Albero<T>::tuttiPari(Nodo n){
    Nodo temp;
    bool ris;
    if(n!=NULL){
        if(leggiNodo(n) % 2==0)
            ris=true;
        else
            ris=false;
        temp=primoFiglio(n);
        while(temp!=NULL && ris){
            ris=tuttiPari(temp);
            temp=succFratello(temp);
        }
    }
    return ris;
}

template<class T>
bool Albero<T>::appartiene(Nodo u,Nodo n){
    Nodo temp;
    bool trovato=false;
    if(n==NULL)
        return false;
    if(n==u)
        return true;
    temp=primoFiglio(n);
    while(temp!=NULL && !trovato){
        if(appartiene(u,temp))
                trovato=true;
        temp=succFratello(temp);
    }
    return trovato;
}

template<class T>
bool Albero<T>::trovaElemento(Nodo n,T valore){
    Nodo temp;
    bool trovato=false;
    if(n==NULL)
        return false;
    if(leggiNodo(n)==valore)
        return true;
    temp=primoFiglio(n);
    while(temp!=NULL && !trovato){
        if(trovaElemento(temp,valore))//una volta che lo ha trovato,tutti i trovato nella funzioni ricorsive vanno a true
            trovato=true;
        temp=succFratello(temp);
    }
    return trovato;
}

template<class T>
void Albero<T>::altezzaMinimale(Nodo n,int &minAltezza){
    Nodo temp;
    int current=0;
    if(n!=NULL){
        if(foglia(n)){
            current=livello(n);
            if(current<=minAltezza)
                minAltezza=current;
        }else{
           temp=primoFiglio(n);
            while(temp!=NULL){
                altezzaMinimale(temp,minAltezza);
                temp=succFratello(temp);
            }
        }
    }
    return;
}

template<class T>
int Albero<T>::altezzaMinimale(Nodo n){
    int minAltezza=altezza(n);
    altezzaMinimale(n,minAltezza);
    return minAltezza;
}

template<class T>
void Albero<T>::cancellaPrimoFiglio(Nodo n){
    if(foglia(n))
        return;
    else{
        Nodo temp=primoFiglio(n);
        delete primoFiglio(n);
        n->setPrimoFiglio(succFratello(temp));
    }
}

template<class T>
void Albero<T>::cancellaSuccFratello(Nodo n){
    if(succFratello(n)==NULL)
        return;
    else{
        Nodo temp=succFratello(n);
        delete succFratello(n);
        n->setProxFratello(succFratello(temp));
    }
}

template<class T>
bool Albero<T>::pariDispari(Nodo n){
    Nodo temp;
    bool ris=true;
    if(n==NULL)
        return true;
    if(leggiNodo(n)%2){
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris &&pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }else{
        temp=primoFiglio(n);
        while(temp!=NULL){
            ris=ris && (leggiNodo(temp)%2) && pariDispari(temp);
            temp=succFratello(temp);
        }
        return ris;
    }
}

#endif // ALBERON_H_INCLUDED
