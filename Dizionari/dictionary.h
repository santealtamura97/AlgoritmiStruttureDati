#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED

/*Un dizionario è una collezione di coppie della forma
(k,v),dove k è la chiave e v è il valore*/

/*La coppia*/

template <class K,class E>
struct mypair{
    //dati membri
    K first; //chiave
    E second; //valore

    //metodi tutti privati

    //costruttore
    mypair(){};
    //costruttore di copia
    mypair(mypair<K,E>& the_pair){
        first=the_pair.first;
        second=the_pair.second;
    }
};

template<class K,class E>
class dictionary{
public:
    virtual ~dictionary() {}

  virtual void create() = 0;
      // crea un dizionario vuoto
  virtual bool empty() const = 0;
      // ritorna true se il dizionario è vuoto
  virtual int size() const = 0;
      // ritorna il numero di coppie del dizionario
  virtual mypair< K, E>* find(const K& k) const = 0;
      // ritorna la coppia con la chiave k(che è di tipo K)
  virtual void insert( mypair< K, E>& p) = 0;
      // inserisce la coppia p nel dizionario
  virtual void erase(const K& k) = 0;
      // cancella la coppia con la chiave k
  virtual void modify(const K& k, const E& e) = 0;
      // modifica il valore della coppia con chiave k in e

};
#endif // DICTIONARY_H_INCLUDED
