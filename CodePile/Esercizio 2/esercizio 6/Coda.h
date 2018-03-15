#ifndef CODA_H_INCLUDED
#define CODA_H_INCLUDED

template < class tipoelem >
class Coda {

public:

  Coda(){
    testa=0;
    lung=0;
  }

  ~Coda(){delete[] elementi;}

  void creaCoda(int maxlung){
    elementi = new tipoelem[maxlung];
  }

  bool codaVuota(){
    return (lung == 0);
  }

  tipoelem leggiCoda(){
    if (!codaVuota())
      return (elementi[testa]);
  }

  void fuoriCoda(){
    if (!codaVuota()){
      testa = (testa + 1) % maxlung;
      lung--;
    }
  }

  void inCoda(tipoelem a){
    if (lung != maxlung){
      elementi[(testa+lung) % maxlung] = a;
      lung++;
    }
  }

 private:
  tipoelem *elementi;
  int testa, lung, maxlung;
};

#endif // CODA_H_INCLUDED
