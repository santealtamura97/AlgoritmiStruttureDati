#include <iostream>
#include "coda..cpp"
#include <stdlib.h>


using namespace std;

int main(){

  Coda<int> C;
  Coda<int> A;
  C.creaCoda(4);
  C.inCoda(1);
  C.inCoda(2);
  C.inCoda(-3);
  C.inCoda(4);

  C.estraiMantenendoOriginale(C,A);

  cout << " " <<A.leggiCoda();
  A.fuoriCoda();
  cout << " " <<A.leggiCoda();
  A.fuoriCoda();
  cout << " " <<A.leggiCoda();
  A.fuoriCoda();

  cout << " " <<C.leggiCoda();
  C.fuoriCoda();

  system("pause");
  return 0;
}
