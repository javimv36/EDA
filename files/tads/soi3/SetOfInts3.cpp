#include <iostream>
using namespace std;

#include "Error.h"
#include "SetOfInts3.h"


// Constructors

SetOfInts3::SetOfInts3() {
	size = 0;
}


// Public methods

bool SetOfInts3::isEmpty() const{
	return (size == 0);
}

void SetOfInts3::add(int x) throw (Error) {
	bool found;
	int pos;

	binSearch(x,found,pos);
	if (!found){
		if (isFull())
			throw Error("Cannot add: The set is full");
		else {
			shiftRightFrom(pos+1);
			elems[pos+1] = x;
			size++;
		}
	}
}

void SetOfInts3::remove(int x){
	bool found;
	int pos;

	binSearch(x,found,pos);
	if (found) {
		shiftLeftFrom(pos);
		size--;
	}
}

bool SetOfInts3::contains(int x) const {
	bool found;
	int pos;

	binSearch(x,found,pos);
	return found;
}

istream& operator>>(istream& sIn, SetOfInts3& set) {
	int n;
	int d;
	sIn >> n;
	set.size = 0;
	for (int i = 0; i < n; i++){
		sIn >> d;
		set.add(d);
	}
	return sIn;
}

ostream& operator<<(ostream& sOut, SetOfInts3& set) {
	sOut << "{";
	for (int i = 0; i < set.size-1; i++)
		sOut << set.elems[i] << ",";
	if (set.size > 0) sOut << set.elems[set.size-1];
	sOut << "}";
	return sOut;
}


// Private methods

bool SetOfInts3::isFull() const {
	return size == MAXSIZE;
}

int SetOfInts3::binSearchAux(int x, int a, int b) const {
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
			p = binSearchAux(x,m + 1,b);
		else
			p = binSearchAux(x,a,m - 1);
	}
	return p;
	// Post: devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//       elems[i] <= x
	//       si x es menor que todos los elementos de elems, devuelve -1
}

void SetOfInts3::binSearch(int x, bool& found, int& pos) const {
	// Pre: los size primeros elementos de elems están ordenados
	//      size >= 0

	pos = binSearchAux(x, 0, size-1);
	found = (pos >= 0) && (pos < size) && (elems[pos] == x);

	// Post : devuelve el mayor índice i (0 <= i <= size-1) que cumple
	//        elems[i] <= x
	//        si x es menor que todos los elementos de elems, devuelve -1
	//        found es true si x esta en elems[0..size-1]
}

void SetOfInts3::shiftRightFrom(int i){
	for (int j = size; j > i; j--)
		elems[j] = elems[j-1];
}

void SetOfInts3::shiftLeftFrom(int i){
	for (; i < size-1; i++)
		elems[i] = elems[i+1];
}
