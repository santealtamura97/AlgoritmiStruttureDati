template < class tipoelem >
class Coda {

public:

  Coda(){
    testa = 0;
    lung = 0;
  }

  ~Coda(){delete[] elementi;}

  void creaCoda(int num){
    maxlung=num;
    elementi = new tipoelem[maxlung];
    testa = 0;
    lung = 0;
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
  void estraiSenzaMantenereOriginale(Coda q,Coda &q1){
    q1.creaCoda(q.lung);
    tipoelem e;
    while (!q.codaVuota()){
        e=q.leggiCoda();
        if(e>0)
            q1.inCoda(e);
        q.fuoriCoda();
    }
  }

  void estraiMantenendoOriginale(Coda &q,Coda &q1){
    q1.creaCoda(q.lung);
    Coda<tipoelem> Aux;
    Aux.creaCoda(q.maxlung);
    tipoelem e;
    while (!q.codaVuota()){
        e=q.leggiCoda();
        if(e>0)
            q1.inCoda(e);
        q.fuoriCoda();
        Aux.inCoda(e);
    }
    //ricostruiamo quella originale
    while(!Aux.codaVuota()){
        e=Aux.leggiCoda();
        q.inCoda(e);
        Aux.fuoriCoda();
    }
  }

 private:
  tipoelem *elementi;
  int testa, lung, maxlung;
};
