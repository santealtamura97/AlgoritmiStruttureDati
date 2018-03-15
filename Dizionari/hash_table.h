#ifndef HASH_TABLE_H_INCLUDED
#define HASH_TABLE_H_INCLUDED

#include <string>
#include "dictionary.h"
#include "list_vector.h"


/*Una possibile rappresentazione di un dizionario
è quella di usare l'hashing.Questo metodo usa una
hash function per tener traccia delle coppie
del dizionario nelle posizioni in una tabella.
Nella situazione ideale,se la coppia p ha una chiave
k e f è la funzione hash,la coppia p è memorizzata
nella posizione f(k) della tabella*/

/*SCANSIONE LINEARE*/
/*Il modo più facile di trovare la posizione in cui
mettere un valore nella tabella è quella di
cercare nella tabella il successivo bucket
disponibile

Dall'altro lato,la ricerca inizia dal primo bucket
f(k) della chiave k che stiamo cercando e continua
esaminando i bucket successivi nella tabella prima
che una delle seguenti condizioni accade:
i) un bucket contenente una coppia con chiave k è
raggiunta.
ii) si è raggiunto un bucket vuoto
iii) siamo ritornati al primo bucket
*/

/*classe hash_table con ricerca lineare*/

/*the home bucket è il primo elemento in cui si accede alla lista*/



using std::string;

template<class T>
class hash{
public:
  size_t operator()(const T the_key) const{
    return abs(the_key);
  }
};


/* a specialization with type string */
template<>
class hash<string>
{
public:
  size_t operator()(const string the_key) const {
    unsigned long hash_value = 0;
    int length = (int) the_key.length();
    for (int i=0; i<length; i++)
      hash_value = 5 * hash_value + the_key.at(i);
   // return size_t(hash_value);
    return hash_value;
  }
};

template<class K, class E>
struct mypair;


template<class K,class E>
class hash_table:public dictionary<K,E> {
public:
    bool empty() const{
        return (dsize==0);
    };

    int size() const{
        return dsize;
    };

    void erase(const K& k);
    void modify(const K& k, const E& e);
    hash_table(int);	    // il costruttore
    void create(){};
    int search(const K& ) const;
    mypair< K, E>* find(const K& ) const;
    void insert( mypair< K, E>& );
    bool containsValue(const E& e);
    E* value();
    K* keys();
    int returnDsize();
    int returnDivisor();
    void resize();
    void deleteTable();
    void cancella(const E&);



private:
    mypair<K,E>** table; //la tabella hash
    hash<K> hashm;
    int dsize; //numero di coppie nel dizionario
    int divisor; //divisiore delle funzioni hash
};

//costruttore

template<class K, class E>
hash_table<K,E>::hash_table(int the_divisor)
{
  divisor = the_divisor;
  dsize = 0;

  table = new mypair<K, E>* [divisor];
  for (int i=0; i<divisor; i++)
    table[i] = NULL;
}


/*Questo metodo ritorna una bucket b (la posizione)
nella tabella che soddisfa esattamente una delle seguenti:
1)table[b] punta a una coppia la cui chiave è the_key
2)nessuna coppia nella tabella ha la chiave the_key,
table[b] è NULL
3)nessuna coppia nella tabella ha la chiave the_key,
tabel[b] ha una chiave diversa da the_key,e la tabella è piena  */

template<class K,class E>
int hash_table<K,E>::search(const K& the_key) const{
    int i=(int) hashm(the_key) %divisor; //home_bucket:si trova la posizione dell'home_bucket facedo il modulo tra il valore numero in tabella ASCII della chiave e il numero di elementi, per trovare un valore univoco
    int j=i;
    do{
        if(table[j]==NULL || table[j]->first==the_key)
            return j;
        j=(j+1) %divisor; //il successivo bucket
    }while(j!=i);
    return j; //la tabella è piena
}

template<class K,class E>
void hash_table<K,E>::insert(mypair<K,E>& the_pair){
    //cerca nella tabella un elemento corrispondente
    int b=search(the_pair.first);
    //verifica se l'elemento corrispondente è stato trovato
    if(table[b]==NULL){
        //nessun elemento trovato e la tabella non è piena
        table[b]=new mypair<K,E> (the_pair);
        dsize++;
    }else{
        //verifica se if duplicatp o tabella piena
        if(table[b]->first==the_pair.first)
            //duplicato,quindi aggiorniamo cambiando il valore
            table[b]->second=the_pair.second;
        else{
            // table is full
            // throw the exception hash_table_full();
        }

    }

}

template<class K, class E>
mypair< K, E>* hash_table<K,E>::find(const K& the_key) const
{
  // search the table
  int b = search(the_key);
  // see if a match was found at table[b]
  if (table[b] == NULL || table[b]->first != the_key)
    return NULL;    // no match
  return table[b];  // matching pair
}




template<class K, class E>
void hash_table<K,E>::erase(const K& k){

}


template<class K, class E>
void hash_table<K,E>::modify(const K& k, const E& e){

}

template<class K,class E>
bool hash_table<K,E>::containsValue(const E& e){
    for(int i=0;i<divisor;i++){
        if(table[i]!=NULL &&table[i]->second==e)
            return true;
    }
    return false;
}

template<class K,class E>
E* hash_table<K,E>::value(){
    E* temp=new E[divisor];
    int j=0;
    for(int i=0;i<divisor;i++){
        if(table[i]!=NULL){
            temp[j]=table[i]->second;
            j++;
        }
    }
    return temp;
}

template<class K,class E>
K* hash_table<K,E>::keys(){
    K* temp=new K[divisor];
    int j=0;
    for(int i=0;i<divisor;i++){
        if(table[i]!=NULL){
            temp[j]=table[i]->first;
            j++;
        }
    }
    return temp;
}


template<class K,class E>
int hash_table<K,E>::returnDsize(){
    return dsize;
}

template<class K,class E>
int hash_table<K,E>::returnDivisor(){
    return divisor;
}

template<class K,class E>
void hash_table<K,E>::deleteTable(){
    for(int k=0;k<divisor;k++){
        delete table[k];
    }
}

//raddoppia la dimensione interna della tabella
template<class K,class E>
void hash_table<K,E>::resize(){
    hash_table<K,E> doppia(this->divisor*2);
    //inserimento dal dizionario originale a quello di dimensione doppia
    for(int i=0;i<divisor;i++){
        if(this->table[i]!=NULL){
            mypair<K,E> coppia;
            coppia.first=this->table[i]->first;
            coppia.second=this->table[i]->second;
            doppia.insert(coppia);
        }
    }
    doppia.dsize=this->dsize;
    //cancellazione vecchia tabella del dizionario
    this->deleteTable();

    //ri-creazione vecchia tabella originale con dimensione della tabella di doppia dimensione
    this->divisor=doppia.divisor;
    this->dsize=doppia.dsize;
    this->table=new mypair<K,E>* [divisor];
    for (int i=0; i<this->divisor; i++)
        this->table[i] = NULL;
    for(int j=0;j<doppia.divisor;j++){
        if(doppia.table[j]!=NULL){
            mypair<K,E> coppia;
            coppia.first=doppia.table[j]->first;
            coppia.second=doppia.table[j]->second;
            this->insert(coppia);//non funziona
        }
    }
}




#endif // HASH_TABLE_H_INCLUDED
