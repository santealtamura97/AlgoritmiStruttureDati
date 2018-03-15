#include "GrafoMat.h"

#include <string>

using namespace std;

int main(){

    GrafoMat<string,int> G1(10);
	NodoG n1,n2,n3,n4,n5;
    G1.insNodo(n1);
    G1.scriviEtichetta(n1,"a");
    G1.insNodo(n2);
    G1.scriviEtichetta(n2,"b");
    G1.insNodo(n3);
    G1.scriviEtichetta(n3,"c");
    G1.insNodo(n4);
    G1.scriviEtichetta(n4,"d");
    G1.insNodo(n5);
    G1.scriviEtichetta(n5,"e");
    G1.insArco(n1,n2,-1);
    G1.insArco(n1,n3,-1);
    G1.insArco(n2,n4,-1);
    G1.insArco(n4,n5,-1);
    G1.insArco(n4,n3,-1);
    G1.insArco(n5,n3,-1);
    G1.insArco(n1,n5,-1);



    cout<<"\nStampa DFS ";
    G1.stampaDFS(n1);
    cout << "\nNumNodi " << G1.numNodi();
	cout << "\nNumArchi " << G1.numArchi();
	cout << "\nNumArchiEntranti in n3 " <<G1.inDegree(n3);
	cout << "\nNumArchiUscenti da n1 "<<G1.OutDegree(n1);
	cout << "\nMediaNumArchiUscenti "<<G1.meanOutDegree(&n1);


	GrafoMat<string,int>::ListaNodi L = G1.Adiacenti(n5);
	GrafoMat<string,double>::ListaNodiPos p;
	cout << "\nAdiacenti di " << G1.leggiEtichetta(n5) << "--> ";
	p = L.begin();
	while (!L.end(p)){
		cout <<  G1.leggiEtichetta(*(L.read(p))) << " ";
		p = L.next(p);
	}

    GrafoMat<string,int>::ListaNodi P = G1.listaPadri(n3);
	GrafoMat<string,double>::ListaNodiPos t;
	cout << "\nPadri di " << G1.leggiEtichetta(n3) << "--> ";
	t = P.begin();
	while (!P.end(t)){
		cout <<  G1.leggiEtichetta(*(P.read(t))) << " ";
		t = P.next(t);
	}


	cout<<"\nStampa BFS ";
    GrafoMat<string,int>::ListaNodi S;
    //G1.stampaBFS(&n1);
    G1.BFS(n1);
    G1.findPath(n1,n5);


	/*GrafoMat<string,double> G(10);

	NodoG n1,n2,n3,n4,n5,n6;

	G.insNodo(n1);
	G.scriviEtichetta(n1,"a");
	G.insNodo(n2);
	G.scriviEtichetta(n2,"b");
	G.insNodo(n3);
	G.scriviEtichetta(n3,"c");
	G.insNodo(n4);
	G.scriviEtichetta(n4,"d");
	G.insNodo(n5);
	G.scriviEtichetta(n5,"e");
	G.insNodo(n6);
	G.scriviEtichetta(n6,"f");



	G.insArco(n1,n2, 1.0);
	G.insArco(n1,n3, 0.9);
	G.insArco(n1,n5, 0.3);
	G.insArco(n2,n4, 0.1);
	G.insArco(n2,n6, 0.2);
	G.insArco(n3,n4, 1.0);
	G.insArco(n3,n6, 0.7);
	G.insArco(n4,n1, 0.5);
	G.insArco(n5,n2, 0.4);
	G.insArco(n5,n3, 0.2);
	G.insArco(n6,n4, 0.1);

	cout << "\nNumNodi " << G.numNodi();
	cout << "\nNumArchi " << G.numArchi();

	G.cancNodo(n6);

	cout << "\nNumNodi " << G.numNodi() << endl;

	GrafoMat<string,double>::ListaNodi L = G.Adiacenti(n1);

	GrafoMat<string,double>::ListaNodiPos p;


	cout << "Adiacenti di " << G.leggiEtichetta(n1) << "--> ";
	p = L.begin();
	while (!L.end(p)){
		cout <<  G.leggiEtichetta(*(L.read(p))) << " ";
		p = L.next(p);
	}*/






}
