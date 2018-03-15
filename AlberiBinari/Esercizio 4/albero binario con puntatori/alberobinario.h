#ifndef ALBEROBINARIO_H_INCLUDED
#define ALBEROBINARIO_H_INCLUDED

#include<iostream>
#include"cella.h"
#include <limits.h>
#include<vector>
using namespace std;

template<class T>
class BinAlbero{
public:

    typedef T tipoelem;
    typedef Cella<T>*  Nodo; //puntatore ad una classe di tipo cella
    BinAlbero();//costruttore
    //~BinAlbero(); distruttore

    //operatori
    void creaBinAlbero();
    bool binAlberoVuoto();
    Nodo binRadice();//restituisce la radice dell'albero
    Nodo binPadre(Nodo);//restituisce il padre di Nodo
    Nodo figlioSinistro(Nodo);//restituisce il figlio sinistro di Nodo
    Nodo figlioDestro(Nodo);//restituisce il figlio destro di Nodo
    bool sinistroVuoto(Nodo);
    bool destroVuoto(Nodo);
    void cancSottoBinAlbero(Nodo); //cancella il sottoalbero con radice in Nodo
    tipoelem leggiNodo(Nodo); //restituisce l'elemento di Nodo
    void scriviNodo(Nodo,tipoelem);
    void insBinRadice(Nodo);
    void insFiglioSinistro(Nodo);
    void insFiglioDestro(Nodo);
    void stampaSottoAlbero(Nodo n);
    void stampa();
    //SERVIZIO
    int count(Nodo n); //restituisce il numero di nodi del sottoalbero a partire da n
    int altezza(Nodo n);//restituisce l'altezza di nodo n
    int livello(Nodo n);//restituisce il livello del nodo n
    void modificaNumeroNodi(Nodo n);
    int livello_n(Nodo,int k);//restituisce il numero di nodi di livello k(larghezza di livello)
    bool is_height_balanced(Nodo);//stabilisce se è bilanciato in altezza
    bool foglia(Nodo);
    int altezzaMinimale(Nodo);//l'altezza minima dal nodo ad una della sue foglie
    int larghezza(Nodo);
    int lunghezzaDiCammino(Nodo,int);//somma delle distanze dai nodi alla radice
    void creaSottoAlbero(BinAlbero<T> tree,Nodo n,Nodo corrente); //crea un sottoalbero a partire dal Nodo n in tree
    void inserisciSottoAlberoaSinistraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d);//inserisce il sotto albero subtree in this a partire dal nodo sinistro di n, in cui il nodo d è la radice del sotto albero subtree
    void inserisciSottoAlberoaDestraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d);//inserisce il sottoalbero subtree in this a partire dal nodo destro di n,in cui il nodo d è la radice del sotto albero subtree
    void inserisciSottoAlbero(BinAlbero,Nodo,Nodo);
    void mutate(BinAlbero<T>& tree1,BinAlbero<T>& tree2,Nodo n1,Nodo n2);//scambia i sottoalberi che hanno radice in n1 per tree1 e n2 per tree2
    // STAMPA VISITA
    void stampaPreOrdine(Nodo n);
    void stampaPostOrdine(Nodo n);
    void stampaSimmetrica(Nodo n);


private:
    void larghezza(Nodo,vector<T>&,int);
    void is_height_balanced(Nodo,bool&);
    int numeroElementi;
    Nodo radice;
};

template<class T>
BinAlbero<T>::BinAlbero(){
    creaBinAlbero();
}

template<class T>
void BinAlbero<T>::creaBinAlbero(){
    numeroElementi=0;
    radice=NULL;//L'albero è vuoto
}

template<class T>
bool BinAlbero<T>::binAlberoVuoto(){
    return(radice==NULL);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binRadice(){
    return (radice);
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::binPadre(Nodo n){
    if(n!=radice)
        return(n->getDAD());
    else
        return NULL;
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioSinistro(Nodo n){
    return(n->getSX());
}

template<class T>
typename BinAlbero<T>::Nodo BinAlbero<T>::figlioDestro(Nodo n){
    return(n->getDX());
}

template<class T>
bool BinAlbero<T>::sinistroVuoto(Nodo n){
    return(n->getSX()==NULL);
}

template<class T>
bool BinAlbero<T>::destroVuoto(Nodo n){
    return(n->getDX()==NULL);
}

template<class T>
void BinAlbero<T>::insBinRadice(Nodo n){
    if(binAlberoVuoto()){
        radice=n;
    }
}

template<class T>
void BinAlbero<T>::insFiglioSinistro(Nodo n){
    if(sinistroVuoto(n)){
        n->setSX(new Cella<T>);
        n->getSX()->setDAD(n);
        n->getSX()->setSX(NULL); //il figlio sinistro di n appena inserito non ha figlio sinistro
        n->getSX()->setDX(NULL);
    }
}

template<class T>
void BinAlbero<T>::insFiglioDestro(Nodo n){
    if(destroVuoto(n)){
        n->setDX(new Cella<T>);
        n->getDX()->setDAD(n);
        n->getDX()->setSX(NULL);
        n->getDX()->setDX(NULL);
    }
}

template<class T>
typename BinAlbero<T>::tipoelem BinAlbero<T>::leggiNodo(Nodo n){
    if(n!=NULL)
        return(n->getElemento());
}

template<class T>
void BinAlbero<T>::scriviNodo(Nodo n,tipoelem a){
    if(n!=NULL){
        n->setElemento(a);
        numeroElementi++;
    }
}

template<class T>
void BinAlbero<T>::cancSottoBinAlbero(Nodo n){
    if(n!=NULL){
        if(!sinistroVuoto(n))
            cancSottoBinAlbero(figlioSinistro(n));
        if(!destroVuoto(n))
            cancSottoBinAlbero(figlioDestro(n));
        if(n!=radice){
            Nodo padre=binPadre(n);
            if(figlioSinistro(padre)==n)
                padre->setSX(NULL); //se il nodo da cancellare è il figlio sinistro
            else
                padre->setDX(NULL); //se il nodo da cancellare è il figlio destro
        }else{
            radice=NULL; //se il nodo da cancellare è radice
        }
        numeroElementi--;
    }
    if(!binAlberoVuoto())
        modificaNumeroNodi(binRadice());
}


template<class T>
void BinAlbero<T>::stampaSottoAlbero(Nodo n){
    std::cout<<"["<<n->getElemento()<<"("<<n->getNumeroNodi()<<")"<<", ";
    if(!sinistroVuoto(n))
        stampaSottoAlbero(figlioSinistro(n));
    else std::cout<<"NIL";
    std::cout<<", ";
    if(!destroVuoto(n))
        stampaSottoAlbero(figlioDestro(n));
    else std::cout<<"NIL";
    std::cout<<" ]";

}


template<class T>
void BinAlbero<T>::stampa(){
    if(!binAlberoVuoto())
        stampaSottoAlbero(binRadice());
    else
        std::cout <<"[]"<<std::endl;
    std::cout << std::endl;

}

template<class T>
int BinAlbero<T>::count(Nodo n){
     int sx=0,dx=0;
     if(!sinistroVuoto(n))
        sx=count(figlioSinistro(n));
     if(!destroVuoto(n))
        dx=count(figlioDestro(n));
     return(sx+dx+1);
}

template<class T>
int BinAlbero<T>::altezza(Nodo n){
    if(sinistroVuoto(n) && destroVuoto(n))
        return (0);
    int u=0;
    if(!sinistroVuoto(n))
        u=altezza(figlioSinistro(n));
    int v=0;
    if(!destroVuoto(n))
        v=altezza(figlioDestro(n));
    if(u>v)
        return (u+1);
    else
        return (v+1);

}

template<class T>
void BinAlbero<T>::modificaNumeroNodi(Nodo n){
    if(!binAlberoVuoto()){
        if(n!=NULL){
            n->setNumeroNodi(count(n));
                modificaNumeroNodi(figlioSinistro(n));
                modificaNumeroNodi(figlioDestro(n));
        }
    }
}

template<class T>
void BinAlbero<T>::stampaPreOrdine(Nodo n){
    if(!binAlberoVuoto()){
        if(n!=NULL){
            cout<<n->getElemento()<<" ";
            stampaPreOrdine(figlioSinistro(n));
            stampaPreOrdine(figlioDestro(n));
        }
    }
}

template<class T>
void BinAlbero<T>::stampaPostOrdine(Nodo n){
    if(n==NULL)
        return;
    stampaPostOrdine(figlioSinistro(n));
    stampaPostOrdine(figlioDestro(n));
    cout<<n->getElemento()<<" ";
}

template<class T>
void BinAlbero<T>::stampaSimmetrica(Nodo n){
    if(n==NULL)
        return;
    stampaSimmetrica(figlioSinistro(n));
    cout<<n->getElemento()<<" ";
    stampaSimmetrica(figlioDestro(n));
}

//Nodo corrente sarà la radice del sottoalbero
/*crea un sottoalbero di tree che ha come radice il nodo n*/
template<class T>
void BinAlbero<T>::creaSottoAlbero(BinAlbero<T> tree,Nodo n,Nodo corrente){
   this->scriviNodo(corrente,tree.leggiNodo(n));
   if(!tree.sinistroVuoto(n)){
        if(this->sinistroVuoto(corrente)){
            this->insFiglioSinistro(corrente);
        }
        creaSottoAlbero(tree,tree.figlioSinistro(n),this->figlioSinistro(corrente));
   }
   if(!tree.destroVuoto(n)){
        if(this->destroVuoto(corrente)){
            this->insFiglioDestro(corrente);
        }
        creaSottoAlbero(tree,tree.figlioDestro(n),this->figlioDestro(corrente));
   }
   this->modificaNumeroNodi(this->binRadice());
}

template<class T>
void BinAlbero<T>::inserisciSottoAlbero(BinAlbero<T> subtree,Nodo n,Nodo d){
    this->scriviNodo(n,subtree.leggiNodo(d));
    if(!subtree.sinistroVuoto(d)){
        if(this->sinistroVuoto(n)){
            this->insFiglioSinistro(n);
        }
        inserisciSottoAlbero(subtree,this->figlioSinistro(n),subtree.figlioSinistro(d));
    }
    if(!subtree.destroVuoto(d)){
        if(this->destroVuoto(n)){
            this->insFiglioDestro(n);
        }
        inserisciSottoAlbero(subtree,this->figlioDestro(n),subtree.figlioDestro(d));
    }
}

template<class T>
void BinAlbero<T>::inserisciSottoAlberoaSinistraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d){
    using namespace std;
    if(this->sinistroVuoto(n)){
        this->insFiglioSinistro(n);
        inserisciSottoAlbero(subtree,this->figlioSinistro(n),subtree.binRadice());
        this->modificaNumeroNodi(this->binRadice());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void BinAlbero<T>::inserisciSottoAlberoaDestraDelNodo(BinAlbero<T> subtree,Nodo n,Nodo d){
    using namespace std;
    if(this->destroVuoto(n)){
        this->insFiglioDestro(n);
        inserisciSottoAlbero(subtree,this->figlioDestro(n),subtree.binRadice());
        this->modificaNumeroNodi(this->binRadice());
    }else{
        cout<<"L'operazione non puo' essere eseguita";
    }
}

template<class T>
void BinAlbero<T>::mutate(BinAlbero<T>& tree1,BinAlbero<T>& tree2,Nodo n1,Nodo n2){
    BinAlbero<T> sub1,sub2;
    sub1.insBinRadice(new Cella<T>);
    sub2.insBinRadice(new Cella<T>);
    sub1.creaSottoAlbero(tree1,n1,sub1.binRadice());
    sub2.creaSottoAlbero(tree2,n2,sub2.binRadice());
    BinAlbero<T>::Nodo padre1,padre2;
    padre1=tree1.binPadre(n1);
    padre2=tree1.binPadre(n2);
    int SxOrDx1,SxOrDx2; //flag
    if(n1==tree1.binPadre(n1)->getSX())
        SxOrDx1=0;//è un nodo sinistro
    else
        SxOrDx1=1;//è un nodo destro
    if(n2==tree1.binPadre(n2)->getSX())
        SxOrDx2=0;
    else
        SxOrDx2=1;
    tree1.cancSottoBinAlbero(n1);
    tree2.cancSottoBinAlbero(n2);
    if(SxOrDx2==0)
        tree2.inserisciSottoAlberoaSinistraDelNodo(sub1,padre2,sub1.binRadice());
    else
        tree2.inserisciSottoAlberoaDestraDelNodo(sub1,padre2,sub1.binRadice());
    if(SxOrDx1==0)
        tree1.inserisciSottoAlberoaSinistraDelNodo(sub2,padre1,sub2.binRadice());
    else
        tree1.inserisciSottoAlberoaSinistraDelNodo(sub2,padre1,sub2.binRadice());
    tree1.modificaNumeroNodi(tree1.binRadice());
    tree2.modificaNumeroNodi(tree2.binRadice());

}

template<class T>
int BinAlbero<T>::livello(Nodo n){
    int l=0;
    if(n==binRadice())
        return l;
    else{
        l=livello(binPadre(n));
    }
    return l+1;
}

template<class T>
int BinAlbero<T>::livello_n(Nodo n,int k){
    if(n==NULL)
        return 0;
    if(k==0)
        return 1;
    return livello_n(figlioSinistro(n),k-1)+livello_n(figlioDestro(n),k-1);
}

template<class T>
bool BinAlbero<T>::is_height_balanced(Nodo n){
    bool ris=false;
    is_height_balanced(n,ris);
    return ris;
}

template<class T>
void BinAlbero<T>::is_height_balanced(Nodo n,bool& ris){
     if(!binAlberoVuoto() || !ris){
        if(n!=NULL && figlioSinistro(n)!=NULL && figlioDestro(n)!= NULL){
            if((altezza(figlioSinistro(n))-altezza(figlioDestro(n)))>1 || (altezza(figlioDestro(n))-altezza(figlioSinistro(n)))>1)
                ris=false;
            else
                ris=true;
            (is_height_balanced(figlioSinistro(n),ris));
            (is_height_balanced(figlioDestro(n),ris));
        }
    }
}

template<class T>
bool BinAlbero<T>::foglia(Nodo n){
    if(figlioSinistro(n)==NULL && figlioDestro(n)==NULL){
        return true;
    }
}


template<class T>
int BinAlbero<T>::altezzaMinimale(Nodo n){
    int h1,hr;
    if(n==NULL)
        return UINT_MAX;
    if(foglia(n))
        return 0;
    h1=altezzaMinimale(figlioSinistro(n));
    hr=altezzaMinimale(figlioDestro(n));
    return min(h1,hr)+1;

}

template<class T>
void BinAlbero<T>::larghezza(Nodo t,vector<T>& conteggio,int level){
    if(t!=NULL){
        conteggio[level]=conteggio[level]+1;
        larghezza(figlioSinistro(t),conteggio,level+1);
        larghezza(figlioDestro(t),conteggio,level+1);
    }
}

template<class T>
int BinAlbero<T>::larghezza(Nodo t){
    vector<T> conteggio(30,0);
    larghezza(t,conteggio,0);
    int maxC=0;
    for(int i=0;i<=numeroElementi;i++){
        if(conteggio[i]>=maxC)
            maxC=conteggio[i];
    }
    return maxC;
}

template<class T>
int BinAlbero<T>::lunghezzaDiCammino(Nodo n,int l){
    if(n==NULL)
        return 0;
    return l+lunghezzaCammino(figlioSinistro(n),l+1)+lunghezzaCammino(figlioDestro(n),l+1);
}

#endif // ALBEROBINARIO_H_INCLUDED
