
#ifndef Set_H_
#define Set_H_

#include <iostream>
using namespace std;

#include "Error.h"


template<class T>
class Set {
	// Conjuntos genéricos representados mediante un array dinámico ordenado sin repeticiones
	private:
		static const int DEFAULT_CAPACITY = 5;

		T* elems;
		int size;
		int capacity;

		bool isFull() const;
		void binSearch(const T& x,bool& found,int& pos) const;
		int binSearchAux(const T& x, int a, int b) const;
		void shiftRightFrom(int i);
		void shiftLeftFrom(int i);
		void reallocate();

	public:
		Set(int initCapacity = DEFAULT_CAPACITY);
		Set(const Set<T>& set);
		~Set();
		bool isEmpty() const;
		void add(const T& x);
		bool contains(const T& x) const;
		void remove(const T& x);
		void erase();
		void write(ostream& sOut);
		void read(istream& sIn);
		int getMin() const;
		void removeMin();
		int getMax() const;
		void removeMax();
		int getSize() const;
};


// Constructors

template<class T>
Set<T>::Set(int initCapacity) {
	size = 0;
	capacity = initCapacity;
	elems = new T[capacity];
}

template<class T>
Set<T>::Set(const Set<T>& set) {
	size = set.size;
	capacity = set.capacity;
	elems = new T[capacity];
	for (int i = 0; i < size; i++)
		elems[i] = set.elems[i];
}

template<class T>
Set<T>::~Set() {
	delete[] elems;
	elems = NULL;
}

// Public methods

template<class T>
bool Set<T>::isEmpty() const{
	return (size == 0);
}

template<class T>
void Set<T>::add(const T& x){
	bool found;
	int pos;

	binSearch(x,found,pos);
	if (!found){
		shiftRightFrom(pos+1);
		elems[pos+1] = x;
		size++;
		if (isFull()) reallocate();
	}
}

template<class T>
void Set<T>::remove(const T& x){
	bool found;
	int pos;

	binSearch(x,found,pos);
	if (found) {
		shiftLeftFrom(pos);
		size--;
	}
}

template<class T>
bool Set<T>::contains(const T& x) const {
	bool found;
	int pos;

	binSearch(x,found,pos);
	return found;
}

template<class T>
void Set<T>::erase(){
	size = 0;
}

template<class T>
void Set<T>::write(ostream& sOut){
	sOut << "{";
	for (int i = 0; i < size-1; i++)
		sOut << elems[i] << ",";
	if (size > 0) sOut << elems[size-1];
	sOut << "}";
}

template<class T>
void Set<T>::read(istream& sIn){
	int n;
	T d;
	sIn >> n;
	size = 0;
	for (int i = 0; i < n; i++){
		sIn >> d;
		add(d);
	}
}

template<class T>
istream& operator>>(istream& sIn, Set<T>& set) {
	set.read(sIn);
	return sIn;
}

template<class T>
ostream& operator<<(ostream& sOut, Set<T>& set) {
	set.write(sOut);
	return sOut;
}


// Private methods

template<class T>
bool Set<T>::isFull() const {
	return size == capacity;
}

template<class T>
int Set<T>::binSearchAux(const T& x, int a, int b) const {
	// Pre: elems está ordenado entre 0 .. size-1
	//      ( 0 <= a <= size ) && ( -1 <= b <= size ) && ( a <= b+1 )
	//      todos los elementos a la izquierda de 'a' son <= x
	//      todos los elementos a la derecha de 'b' son > x

	int p, m;

	if (a == b + 1)
		p = a - 1;
	else if (a <= b) {
		m = (a + b) / 2;
		if (elems[m] <= x)
			p = binSearchAux(x, m + 1, b);
		else
			p = binSearchAux(x, a, m - 1);
	}
	return p;
	// Post: devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//       elems[i] <= x
	//       si x es menor que todos los elementos de elems, devuelve -1
}

template<class T>
void Set<T>::binSearch(const T& x, bool& found, int& pos) const {
	// Pre: los size primeros elementos de elems están ordenados
	//      size >= 0

	pos = binSearchAux(x, 0, size - 1);
	found = (pos >= 0) && (pos < size) && (elems[pos] == x);

	// Post : devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//        elems[i] <= x
	//        si x es menor que todos los elementos de elems, devuelve -1
	//        found es true si x esta en elems[0..size-1]
}

template<class T>
void Set<T>::shiftRightFrom(int i){
	for (int j = size; j > i; j--)
		elems[j] = elems[j-1];
}

template<class T>
void Set<T>::shiftLeftFrom(int i){
	for (; i < size-1; i++)
		elems[i] = elems[i+1];
}

template<class T>
void Set<T>::reallocate(){
	capacity = capacity*2;
	T* newElems = new T[capacity];
	for (int i = 0; i < size; i++)
		newElems[i] = elems[i];
	delete[] elems;
	elems = newElems;
}

template<class T>
int Set<T>::getMin()const{
	return elems[0];
}

template<class T>
void Set<T>::removeMin(){
	remove(0);
}

template<class T>
int Set<T>::getMax()const{
	return elems[size-1];
}

template<class T>
void Set<T>::removeMax(){
	remove(size-1);
}
template<class T>
int Set<T>::getSize()const{
	return size;
}
#endif /* Set_H_ */
