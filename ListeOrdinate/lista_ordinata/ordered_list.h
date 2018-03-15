#ifndef ORDERED_LIST_H_INCLUDED
#define ORDERED_LIST_H_INCLUDED
#include "linear_list.h"
#include<stdlib.h>
#include<string>

// classe Lista
template< class T >
class Ordered_list : public Linear_list<T, int>{
 public:
	typedef typename Linear_list<T, int>::value_type value_type;
	typedef typename Linear_list<T, int>::position position;

	// costruttori
	Ordered_list();
	Ordered_list(int);
	// costruttore per copia
	Ordered_list(const Ordered_list<T>& );
	//distruttore
	~Ordered_list();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(const value_type &, position);
	position begin() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void erase(position);
	void insert_in_order(value_type);
	void merge(Ordered_list<T> &);
    position search(Ordered_list<T>::value_type p);
    void insert(const value_type &, position);
	// sovraccarico di operatori
	Ordered_list<T>& operator=(const Ordered_list<T>&); // the assignment operator
	bool operator==(const Ordered_list<T> &) const; // tests two list for equality

 private:List_vector<E>
	void change_dimension_(T*& , int , int );
	value_type* elements_;
	int length_; // the length of the list
	int array_dimension_; // array's dimension
};

// costruttore
template< class T >
Ordered_list< T >::Ordered_list() {
  array_dimension_ = 10;
  this->create();
}

// costruttore
template< class T >
Ordered_list< T >::Ordered_list(int dim){
  array_dimension_ = dim;
  this->create();
}

/* Il costruttore per copia effettua una copia o clone di un oggetto.
 * Questo costruttore viene invocato, per esempio, quando un oggetto viene passato
 * per valore ad una funzione o quando una funzione restituisce un oggetto.
 */
template< class T >
Ordered_list< T >::Ordered_list(const Ordered_list<T>& Lista) {
  this->array_dimension_ = Lista.array_dimension_;
  this->length_ = Lista.length_;
  this->elements_ = new T[array_dimension_];
  for (int i=0; i<Lista.array_dimension_; i++)
     this->elements_[i] = Lista.elements_[i];
}

// distruttore
template< class T >
Ordered_list< T >::~Ordered_list(){
	delete elements_;
}

// operatori
template< class T >
void Ordered_list< T >::create(){
  this->elements_ = new T[array_dimension_];
  this->length_ = 0;
}

template< class T >
bool Ordered_list< T >::empty() const {
    return(length_ == 0);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::begin() const {
	return(1); // e quindi pos(1)=pos(n+1) se la lista -Ah vuota (n=0)
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::next(position p) const {
	if ( (0 < p) && (p < length_+1)) // precondizione
		return(p+1);
	else
		return(p);
}

template< class T >
typename Ordered_list< T >::position Ordered_list< T >::previous(position p) const {
	if ( (1 < p) && (p < length_+1)) // precondizione
		return(p-1);
	else
		return(p);
}

template< class T >
bool Ordered_list< T >::end(position p) const {
	if ( (0 < p) && (p <= length_+1)) // precondizione
		return( p == length_+1);
	else
		return(false);
}

template< class T >
typename Ordered_list< T >::value_type Ordered_list< T >::read(position p) const {
	if ( (0 < p) && (p < length_+1)) // precondizione
		return(elements_[p-1]);
}

template< class T >
void Ordered_list< T >::write(const value_type &a, position p) {
  if ( (0 < p) && (p < length_+1)) // precondizione
    elements_[p-1] = a;
}

template< class T >
void Ordered_list<T>::insert(const value_type &a, position p){
  if (length_ == array_dimension_){
    change_dimension_(elements_, array_dimension_, array_dimension_ * 2);
    array_dimension_ = array_dimension_ * 2;
  }
  if ( (0 < p) && (p <= length_+1)) { // precondizione
		for (int i=length_; i>=p; i--)
			elements_[i] = elements_[i-1];
		elements_[p-1]=a;
		length_++;
	}
}


template< class T >
void Ordered_list< T >::erase(position p){
  if ( (0 < p) && ( p < length_ + 1)) // precondizione
    if (!empty()) {
			for (int i=p-1;i<(length_-1);i++)
				elements_[i]=elements_[i+1];
			length_--;
		}
}

template<class T>
void Ordered_list< T >::change_dimension_(T*& a, int vecchiaDim, int nuovaDim){

  T* temp = new T[nuovaDim];
  int number;
  if (vecchiaDim < nuovaDim)
     number = vecchiaDim;
  else
     number = nuovaDim;
  for (int i=0; i<number; i++)
     temp[i]=a[i];
  delete [] a;
  a = temp;
}

/* operatore di assegnamento */
template<class T>
Ordered_list<T>& Ordered_list<T>::operator=(const Ordered_list<T>& l){
	if (this != &l){   // attenzione agli autoassegnamenti: l = l
		this->array_dimension_ = l.array_dimension_;
		this->length_ = l.length_;
		delete this->elements_;
		this->elements_ = new T[array_dimension_];
		for (int i=0; i<l.array_dimension_; i++)
			this->elements_[i] = l.elements_[i];
	}
	return *this;
}

/* operatore di test di uguaglianza */
template<class T>
bool Ordered_list<T>::operator==(const Ordered_list<T> &l) const{
	if (l.length_ != this->length_)
		return false;
  for (int i=0; i<this->array_dimension_; i++)
		if (this->elements_[i] != l.elements_[i])
			return false;
	return true;
}

template<class T>
typename Ordered_list< T >::position Ordered_list< T >::search(Ordered_list<T>::value_type p){
    for(int i=begin()-1;i<=length_-1;i++){
        if(elements_[i]==p)
            return i+1;
    }
}
template<class T>
void Ordered_list<T>::insert_in_order(value_type v){
    if(length_==0){
        insert(v,begin());
    }else{
        position p;
        p=begin();
        while((read(p)<v) &&(p<=length_)){
            p=next(p);
        }
        insert(v,p);
    }

}
template<class T>
void Ordered_list<T>::merge(Ordered_list &B){
	position pb;
	this->change_dimension_(this->elements_,this->array_dimension_,this->array_dimension_+B.array_dimension_);

	pb = B.begin();

	while(!B.end(pb)){
        this->insert_in_order(B.read(pb));
        pb=B.next(pb);
	}
}
#endif // ORDERED_LIST_H_INCLUDED
