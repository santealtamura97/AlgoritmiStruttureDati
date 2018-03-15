#include <iostream>
#include<stdlib.h>
#include "alberobinario.h"
#include "cella.h"


using namespace std;

int main()
{
    BinAlbero<int> Tree;
    /*Poichè il puntatore NULL non può puntare a niente, utilizzo
    l'operatore "new" che mi crea un puntatore non NULL da assegnare
    alla radice di Tree*/



    typename BinAlbero<int>::Nodo radice;
    radice=new Cella<int>;



    Tree.insBinRadice(radice);
    Tree.scriviNodo(Tree.binRadice(),2345);
    cout<<"         L'elemento radice dell'albero binario e': "<<Tree.binRadice()->getElemento();
    Tree.insFiglioSinistro(Tree.binRadice());
    Tree.insFiglioDestro(Tree.binRadice());
    Tree.scriviNodo(Tree.figlioSinistro(Tree.binRadice()),234);
    Tree.scriviNodo(Tree.figlioDestro(Tree.binRadice()),235);
    cout<<"\n\n         Il figlio sinistro della radice dell'albero binario e': "<<Tree.figlioSinistro(Tree.binRadice())->getElemento();
    cout<<"\n\n         Il figlio destro della radice dell'albero binario e': "<<Tree.figlioDestro(Tree.binRadice())->getElemento();
    radice=Tree.figlioDestro(Tree.binRadice());
    Tree.insFiglioSinistro(radice);
    Tree.scriviNodo(Tree.figlioSinistro(radice),345);
    cout<<"\n\n         Il figlio sinistro del nodo 235 e': "<<Tree.figlioSinistro(radice)->getElemento();
    Tree.modificaNumeroNodi(Tree.binRadice());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         L'altezza minimale dell'albero e':"<<Tree.altezzaMinimale(Tree.binRadice());
    int k=1;
    cout<<"\n\n         Il numero di nodi di livello "<<k<<" e':"<<Tree.livello_n(Tree.binRadice(),k);
    cout<<"\n\n         Stampa in preordine: ";
    Tree.stampaPreOrdine(Tree.binRadice());
    cout<<"\n\n         Stampa in postordine: ";
    Tree.stampaPostOrdine(Tree.binRadice());
    cout<<"\n\n         Stampa simmetrica: ";
    Tree.stampaSimmetrica(Tree.binRadice());
    cout<<"\n\n         Il numero di nodi del sottoalbero con radice in figliosinistro di radice e':"<<Tree.count(Tree.figlioSinistro(Tree.binRadice()));
    cout<<"\n\n         Il numero di nodi del sottoalbero con radice in figliodestro di radice e':"<<Tree.count(Tree.figlioDestro(Tree.binRadice()));
    Tree.cancSottoBinAlbero(Tree.figlioSinistro(Tree.binRadice()));
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo canc figlio sx di radice) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         L'altezza del figlio destro della radice e': "<<Tree.altezza(Tree.figlioDestro(Tree.binRadice()));
    radice=Tree.figlioDestro(Tree.binRadice());
    cout<<"\n\n         L'altezza del figlio sinistro del figlio destro della radice e': "<<Tree.altezza(Tree.figlioSinistro(radice));
    cout<<"\n\n         L'altezza della radice e': "<<Tree.altezza(Tree.binRadice());
    cout<<"\n\n         Il livello del figlio destro della radice e': "<<Tree.livello(Tree.figlioDestro(Tree.binRadice()));
    cout<<"\n\n         Il livello del figlio sinistro del figlio destro della radice e': "<<Tree.livello(Tree.figlioSinistro(radice));
    cout<<"\n\n         Il livello della radice e': "<<Tree.livello(Tree.binRadice());
    BinAlbero<int> sub1;
    typename BinAlbero<int>::Nodo radiceSub;
    radiceSub=new Cella<int>;
    sub1.insBinRadice(radiceSub);
    sub1.creaSottoAlbero(Tree,Tree.figlioDestro(Tree.binRadice()),sub1.binRadice());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO SUB1 **********************";
    cout<<"\n\n         ";
    sub1.stampa();
    Tree.inserisciSottoAlberoaSinistraDelNodo(sub1,Tree.binRadice(),sub1.binRadice());//inserisce il sottoalbero sub1 a sinistra del nodo radice
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo inserimento sottoalbero sub1 a sinistra della radice) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE **********************";
    typename BinAlbero<int>::Nodo nodo;
    nodo=Tree.figlioSinistro(Tree.figlioDestro(Tree.binRadice()));
    Tree.inserisciSottoAlberoaDestraDelNodo(sub1,nodo,sub1.binRadice());//inserisce il sottoalbero sub1 a destra del nodo nodo in tree
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO TREE(dopo inserimento sottoalbero sub1 a destra del nodo nodo) **********************";
    cout<<"\n\n         ";
    Tree.stampa();
    BinAlbero<int> albero1,albero2;
    typename BinAlbero<int>::Nodo radice1,radice2;
    radice1=new Cella<int>;
    radice2=new Cella<int>;
    albero1.insBinRadice(radice1);
    albero2.insBinRadice(radice2);
    albero1.scriviNodo(albero1.binRadice(),5);
    albero1.insFiglioSinistro(albero1.binRadice());
    albero1.scriviNodo(albero1.figlioSinistro(albero1.binRadice()),4);
    albero1.insFiglioDestro(albero1.binRadice());
    albero1.scriviNodo(albero1.figlioDestro(albero1.binRadice()),3);
    radice1=albero1.figlioSinistro(albero1.binRadice());
    albero1.insFiglioSinistro(radice1);
    albero1.scriviNodo(albero1.figlioSinistro(radice1),2);
    albero1.modificaNumeroNodi(albero1.binRadice());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO1 **********************";
    cout<<"\n\n         ";
    albero1.stampa();
    albero2.scriviNodo(albero2.binRadice(),34);
    albero2.insFiglioSinistro(albero2.binRadice());
    albero2.scriviNodo(albero2.figlioSinistro(albero2.binRadice()),23);
    albero2.insFiglioDestro(albero2.binRadice());
    albero2.scriviNodo(albero2.figlioDestro(albero2.binRadice()),56);
    radice2=albero2.figlioSinistro(albero2.binRadice());
    albero2.insFiglioSinistro(radice2);
    albero2.scriviNodo(albero2.figlioSinistro(radice2),48);
    albero2.modificaNumeroNodi(albero2.binRadice());
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO2 **********************";
    cout<<"\n\n         ";
    albero2.stampa();
    albero1.mutate(albero1,albero2,albero1.figlioSinistro(albero1.binRadice()),albero2.figlioSinistro(albero2.binRadice()));
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO1(dopo la mutate) **********************";
    cout<<"\n\n         ";
    albero1.stampa();
    cout<<"\n\n         ";
    cout<<"********************** STAMPA DELL'ALBERO ALBERO2(dopo la mutate) **********************";
    cout<<"\n\n         ";
    albero2.stampa();

    BinAlbero<int> Tree2;
    typename BinAlbero<int>::Nodo radix;
    radix=new Cella<int>;
    Tree2.insBinRadice(radix);
    Tree2.scriviNodo(Tree2.binRadice(),2345);
    Tree2.insFiglioSinistro(Tree2.binRadice());
    Tree2.insFiglioDestro(Tree2.binRadice());
    Tree2.scriviNodo(Tree2.figlioSinistro(Tree2.binRadice()),234);
    Tree2.scriviNodo(Tree2.figlioDestro(Tree2.binRadice()),235);

    Tree2.stampa();
    if(Tree2.is_height_balanced(Tree2.binRadice())){
        cout<<"E' bilanciato in altezza";
    }

    cout<<"\n\nLa larghezza dell'albero binario e': "<<Tree2.larghezza(Tree2.binRadice());
    return 0;
}
