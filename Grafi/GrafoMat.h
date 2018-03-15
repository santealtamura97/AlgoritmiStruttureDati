#ifndef GRAFOMAT_H_INCLUDED
#define GRAFOMAT_H_INCLUDED

#include "Grafo.h"
#include "coda.h"
#include <stdlib.h>

template<class P>
class InfoArco {
 public:
	P peso;//se il peso vale -1 allora è un arco uscente,altrimenti se vale 1 è entrante
	 //se il grafo è pesato si utilizzano i pesi al posto degli elementi binari
	bool vuoto;

	InfoArco(){
		vuoto = true;
	}
};

class NodoG{
 public:
    List_vector<NodoG*> padri;
	NodoG(int i){
		nodoId = i;
	}
	NodoG(){
	}
	int getId(){ return nodoId; }
	void setId(int id) {nodoId = id;} //id è un identificatore

	bool operator ==(NodoG& n1){
        if(this->getId()==n1.getId()){
            return true;
        }else{
            return false;
        }
	}
 private:
	int nodoId;
};

template<class E, class P>
	class InfoNodo {
 public:
    NodoG * parent=NULL;
    bool visitato=false;
	E   etichetta;
	bool vuoto;
	void* info;
	InfoArco<P>* archi;

	InfoNodo(){
		info = 0;
		vuoto = true;
	}

	~InfoNodo(){
		if (!vuoto)
			delete [] archi;
	}
};




template<class E, class P>
	class GrafoMat : public Grafo<E, P, NodoG > {
 public:
    typedef E Etichetta;
    typedef P Peso;
    typedef NodoG Nodo;
    typedef Arco_<Peso, Nodo> Arco;
    typedef Grafo<Etichetta, Peso, Nodo> Grafo_;
    typedef typename Grafo_::ListaNodi ListaNodi;
    typedef typename Grafo_::listaNodo listaNodo;
    typedef typename Grafo_::ListaNodiPos ListaNodiPos;

    GrafoMat(int);
    ~GrafoMat();

    bool vuoto() const;
    void insNodo(NodoG&);
    void insArco(Nodo, Nodo&, Peso);
    void cancNodo(Nodo);
    void cancArco(Nodo, Nodo);
		//    bool esisteNodo(Nodo);
		//    bool esisteArco(Arco);
    ListaNodi Adiacenti(Nodo) const ;
    listaNodo listaAdiacenti(Nodo) const;
    ListaNodi listaPadri(Nodo) const;
    ListaNodi list_nodi() const ;
    Etichetta leggiEtichetta(Nodo) const ;
    void scriviEtichetta(Nodo, Etichetta) ;
    Peso leggiPeso(Nodo, Nodo) const ;
    void scriviPeso(Nodo, Nodo, Peso) ;


		int numNodi(){
			return nodi;
		};
		int numArchi(){
			return archi;
		};
    //esercitazione
    int inDegree(Nodo);
    int OutDegree(Nodo);
    //visita

    void BFS(Nodo&);//stampa in ampiezza partendo da un nodo dato
    //servizio
    double meanOutDegree(Nodo*);

    /*findPath : Stabilisce se esiste un path da S a D
    e in tal caso lo stampa */
    void findPath(Nodo& u,Nodo& D);
    void stampaDFS(Nodo& u);
    void setVisitato(Nodo& u);
    bool getVisitato(Nodo& u);
    void setNotVisitato();//inizializza a false tutti i visitati

 private:
    bool trovaPercorso(Nodo&,Nodo&,bool&);
    void stampaPercorso(Nodo&,Nodo&);
    InfoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
    int archi;
};


template<class E, class P>
	GrafoMat<E, P>::GrafoMat(int _dimensione){
	dimensione = _dimensione;
	nodi = 0;
	archi = 0;
	matrice = new InfoNodo<E,P>[dimensione];
	for (int i=0; i<dimensione; i++)
		matrice[i].archi = new InfoArco<P>[dimensione];
}

template<class E, class P>
	GrafoMat<E, P>::~GrafoMat() {
	delete [] matrice;
}

template<class E, class P>
	bool GrafoMat<E, P>::vuoto() const {
	return (nodi == 0);
}

template<class E, class P>
	void GrafoMat<E, P>::insNodo(Nodo& N) {
	int n = 0;
	if (nodi < dimensione){
		while (matrice[n].vuoto == false)
			n++;
		nodi++;
		matrice[n].vuoto = false;
	}
	N.setId(n); //ad N associo la posizione n nella matrice di adiacenza
}


/*Inserisce un arco tra due nodi n1 e n2 di peso P*/
template<class E, class P>
	void GrafoMat<E, P>::insArco(Nodo n1, Nodo& n2, P peso) {

    //assert n1 e n2 devono esistere nel Grafo
    /*Trova nella matrice la posizione dell'id di n1
      e nella lista archi trova la posizione dell'id di n2
      e gli assegna il peso*/
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
	/*Si stabilisce che è presente un arco tra n1 e n2*/
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;

	n2.padri.insert(new NodoG(n1.getId()),n2.padri.begin());

	archi++;
}


template<class E, class P>
	void GrafoMat<E, P>::cancNodo(Nodo n) {
	// ATTENZIONE: controllare prima che non ci siano archi uscenti o entranti in n
	bool canc = true;
	int i;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[n.getId()].archi[i].vuoto)
			canc = false;
	for (i=0; i < dimensione && canc; i++)
		if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto)
			canc = false;

	if (canc){
		delete matrice[n.getId()].archi;
		matrice[n.getId()].vuoto = true;
	}
}

template<class E, class P>
	void GrafoMat<E, P>::cancArco(Nodo n1, Nodo n2){
	matrice[n1.getId()].archi[n2.getId()].vuoto = true;
	archi--;
}

/*Questa è composta da puntatori a Nodi*/
template<class E, class P>
	typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::Adiacenti(Nodo n) const{
	ListaNodi list;

	for (int i = 0; i < dimensione; i++) {
		if (!matrice[n.getId()].archi[i].vuoto) {
			list.insert(new NodoG(i), list.begin());
		}
	}
	return list;
}

/*Questa è composta da Nodi*/
template<class E,class P>
    typename GrafoMat<E,P>::listaNodo GrafoMat<E,P>::listaAdiacenti(Nodo n) const{
        listaNodo lista;

        for(int i=0;i<dimensione;i++){
            if(!matrice[n.getId()].archi[i].vuoto){
                lista.insert(NodoG(i),lista.begin());
            }
        }
        return lista;
    }

template<class E, class P>
	typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::list_nodi() const {
	ListaNodi list;
	for (int i = 0; i < dimensione; i++)
		if (!matrice[i].vuoto)
			list.insert(new NodoG(i), list.begin());
	return list;
}

template<class E, class P>
	E GrafoMat<E, P>::leggiEtichetta(Nodo n) const {
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviEtichetta(Nodo n, E etichetta) {
	matrice[n.getId()].etichetta = etichetta;
}

template<class E, class P>
	P GrafoMat<E, P>::leggiPeso(Nodo n1, Nodo n2) const {
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
	void GrafoMat<E, P>::scriviPeso(Nodo n1, Nodo n2, P peso) {
	matrice[n1.getId()].archi[n2.getId()].peso = peso;
}

template<class E,class P>
    int GrafoMat<E,P>::inDegree(Nodo N){
        int numArchiEntranti=0;
        for(int i=0;i<dimensione;i++){
            if(!matrice[N.getId()].archi[i].vuoto){
                if(matrice[N.getId()].archi[i].peso==1)
                numArchiEntranti++;
            }
        }
        return numArchiEntranti;
    }

template<class E,class P>
    int GrafoMat<E,P>::OutDegree(Nodo N){
        int numArchiUscenti=0;
        for(int i=0;i<dimensione;i++){
            if(!matrice[N.getId()].archi[i].vuoto){
                if(matrice[N.getId()].archi[i].peso==-1)
                numArchiUscenti++;
            }
        }
        return numArchiUscenti;
    }


template<class E,class P>
  double GrafoMat<E,P>::meanOutDegree(Nodo* u){
      double media=0;
      List_vector<int> Storico;
      Coda<Nodo*> Q(numNodi());
      Q.inCoda(u);
      while(!Q.codaVuota()){
        u=Q.leggiCoda();
        Q.fuoriCoda();
        if(!Storico.search(u->getId())){//controllo se l'ho già controllato in precedenza
            media=media + OutDegree(*u);
            Storico.insert(u->getId(),Storico.begin());
        }
        ListaNodi lista;
        lista=Adiacenti(*u);
        for(ListaNodiPos i=lista.begin();!lista.end(i);i=lista.next(i)){
            Nodo *v=lista.read(i);
            if(!Q.appartiene(v)){
                Q.inCoda(v);
            }
        }
    }
    return media/numNodi();
  }

template<class E,class P>
typename GrafoMat<E, P>::ListaNodi GrafoMat<E, P>::listaPadri(Nodo n) const{
    return n.padri;
}

template<class E,class P>
void GrafoMat<E,P>::findPath(Nodo& u,Nodo& D){
    bool ris=false;
    trovaPercorso(u,D,ris);
    if(ris){
        cout<<"\nIl percorso esiste ed e': ";
        stampaPercorso(u,D);
        cout<<" "<<leggiEtichetta(D);
    }
}

template<class E,class P>
bool GrafoMat<E,P>::trovaPercorso(Nodo &s,Nodo &D,bool &ris){
    setNotVisitato();
    Coda<Nodo*> F(numNodi());
    F.inCoda(&s);
    setVisitato(s);
    while(!F.codaVuota()){
        Nodo *u=F.leggiCoda();
        F.fuoriCoda();
        if(leggiEtichetta(*u)==leggiEtichetta(D)){
            ris=true;
        }
        ListaNodi lista;
        lista=Adiacenti(*u);
        for(ListaNodiPos i=lista.begin();!lista.end(i);i=lista.next(i)){
            if(getVisitato(*lista.read(i))==false){
                setVisitato(*lista.read(i));
                F.inCoda(lista.read(i));
                matrice[lista.read(i)->getId()].parent=u;
            }
        }
    }
}

template<class E,class P>
void GrafoMat<E,P>::stampaPercorso(Nodo &s,Nodo &v){
    if(leggiEtichetta(v)!=leggiEtichetta(s)){
       if(matrice[v.getId()].parent==NULL){
            cout<<"No path";
        }else{
            stampaPercorso(s,*matrice[v.getId()].parent);
            cout<<" "<<leggiEtichetta(*matrice[v.getId()].parent);
        }
    }
}


template<class E,class P>
void GrafoMat<E,P>::BFS(Nodo & s){
    setNotVisitato();
    Coda<Nodo*> F(numNodi());
    F.inCoda(&s);
    setVisitato(s);
    while(!F.codaVuota()){
        Nodo *u=F.leggiCoda();
        F.fuoriCoda();
        cout<<" "<<leggiEtichetta(*u);
        ListaNodi lista;
        lista=Adiacenti(*u);
        for(ListaNodiPos i=lista.begin();!lista.end(i);i=lista.next(i)){
            if(getVisitato(*lista.read(i))==false){
                setVisitato(*lista.read(i));
                F.inCoda(lista.read(i));
            }
        }
    }
}


template<class E,class P>
void GrafoMat<E,P>::stampaDFS(Nodo& u){
    //esamina Nodo
    cout<<" "<<leggiEtichetta(u);
    this->setVisitato(u);
    ListaNodi lista;
    lista=Adiacenti(u);
    ListaNodiPos i=lista.begin();
    while(!lista.end(i)){
       if(getVisitato(*lista.read(i))==false){
            stampaDFS(*lista.read(i));
       }
       i=lista.next(i);
    }
    return;
}

template<class E,class P>
void GrafoMat<E,P>::setVisitato(Nodo& u){
    matrice[u.getId()].visitato=true;
}

template<class E,class P>
bool GrafoMat<E,P>::getVisitato(Nodo& u){
    return matrice[u.getId()].visitato;
}

template<class E,class P>
void GrafoMat<E,P>::setNotVisitato(){
    for (int i = 0; i < dimensione; i++){
        if (!matrice[i].vuoto)
            matrice[i].visitato=false;
    }
    return;
}
#endif // GRAFOMAT_H_INCLUDED
