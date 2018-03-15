#include <iostream>
#include <stdlib.h>
#include "cella.h"
#include "alberoN.h"
#include "coda.h"

using namespace std;

int main()
{
    Albero<char> T;
    typename Albero<char>::Nodo radice,n;
    n=new Cella<char>;
    radice=new Cella<char>;
    T.insRadice(radice);
    T.scriviNodo(T.radiceAlbero(),'a');
    T.insPrimoFiglio(T.radiceAlbero());
    T.scriviNodo(T.primoFiglio(T.radiceAlbero()),'b');
    T.insFratello(T.primoFiglio(T.radiceAlbero()));
    T.scriviNodo(T.succFratello(T.primoFiglio(T.radiceAlbero())),'c');
    radice=T.primoFiglio(T.radiceAlbero());
    T.insPrimoFiglio(radice);
    T.scriviNodo(T.primoFiglio(radice),'d');
    T.insFratello(T.primoFiglio(radice));
    T.scriviNodo(T.succFratello(T.primoFiglio(radice)),'f');
    T.insPrimoFiglio(T.succFratello(T.primoFiglio(T.radiceAlbero())));
    T.scriviNodo(T.primoFiglio(T.succFratello(T.primoFiglio(T.radiceAlbero()))),'z');

    T.stampaAlbero();
     cout<<"\nL'altezza minimale dell'albero e':"<<T.altezzaMinimale(T.radiceAlbero());
    cout<<"\nStampa in pre-ordine dell'albero:";
    T.stampaPreOrdine(T.radiceAlbero());
    cout<<"\nStampa in post-ordine dell'albero:";
    T.stampaPostOrdine(T.radiceAlbero());
    cout<<"\nStampa simmetrica dell'albero:";
    T.stampaSimmetrica(T.radiceAlbero());
    T.contaNodi(T.radiceAlbero());
    cout<<"\nStampa in ampiezza dell'albero:";
    T.stampaBFS(T.radiceAlbero());
    cout<<"\nLa profondita' dell'albero e':"<<T.profondita(T.radiceAlbero());
    cout<<"\nLa larghezza dell'albero e':"<<T.larghezza(T.radiceAlbero());

    Albero<int> T1;
    typename Albero<int>::Nodo u;
    u=new Cella<int>;
    T1.insRadice(u);
    T1.scriviNodo(T1.radiceAlbero(),4);
    T1.insPrimoFiglio(T1.radiceAlbero());
    T1.scriviNodo(T1.primoFiglio(T1.radiceAlbero()),6);
    T1.insFratello(T1.primoFiglio(T1.radiceAlbero()));
    T1.scriviNodo(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())),8);
    T1.insFratello(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())));
    T1.scriviNodo(T1.succFratello(T1.succFratello(T1.primoFiglio(T1.radiceAlbero()))),2);
    u=T1.primoFiglio(T1.radiceAlbero());
    T1.insPrimoFiglio(u);
    T1.scriviNodo(T1.primoFiglio(u),2);
    T1.insFratello(T1.primoFiglio(u));
    T1.scriviNodo(T1.succFratello(T1.primoFiglio(u)),2);
    T1.insPrimoFiglio(T1.succFratello(T1.primoFiglio(T1.radiceAlbero())));
    T1.scriviNodo(T1.primoFiglio(T1.succFratello(T1.primoFiglio(T1.radiceAlbero()))),4);

    T1.stampaAlbero();
    cout<<"\nStampa in ampiezza dell'albero:";
    T1.stampaBFS(T1.radiceAlbero());
    cout<<"\nIl livello del primo figlio della radice e':"<<T1.livello(T1.primoFiglio(T1.radiceAlbero()));
    int somma=0;
    T1.foglieK(T1.radiceAlbero(),somma,12);
    T1.stampaAlbero();
    cout<<"\nStampa in ampiezza dell'albero:";
    T1.stampaBFS(T1.radiceAlbero());
    cout<<"\nIl numero di foglie presenti nell'albero e':"<<T1.numFoglie(T1.radiceAlbero());
    cout<<"\nIl valore massimo dell'albero e':"<<T1.maxAlbero(T1.radiceAlbero());
    cout<<"\nL'altezza dell'albero e':"<<T1.altezza(T1.radiceAlbero());
    int k=2;
    cout<<"\nIl numero di nodi con 2 figli e':"<<T1.nodiKfigli(T1.radiceAlbero(),k);
    if(T1.tuttiPari(T1.radiceAlbero())){
        cout<<"\nTutti pari";
    }
    int h=2;
    int numero=0;
    T1.n_livello(T1.radiceAlbero(),h,numero);
    cout<<"\nIl numero di nodi di livello "<<h<<" e':"<<numero;
    cout<<"\nL'altezza minimale dell'albero e':"<<T1.altezzaMinimale(T1.radiceAlbero());
    T1.cancellaPrimoFiglio(T1.radiceAlbero());
    //T1.cancellaSuccFratello(T1.primoFiglio(T1.radiceAlbero()));
    T1.stampaAlbero();
    if(T1.pariDispari(T1.radiceAlbero()))
        cout<<"\nOgni nodo pari ha solo figli dispari";
    else
        cout<<"\nNon tutti i nodi pari hanno solo figli dispari";

    return 0;
}
