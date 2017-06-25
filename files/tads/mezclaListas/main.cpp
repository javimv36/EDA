#include <iostream>
#include <fstream>
#include "List.h"
#include <cstdlib>

using namespace std;


void mostrarLista(List<int>* l) {
	List<int>::ConstIterator it = l->cbegin();

	if (!l->empty()) {
		if (it != l->cend()) {
			cout << it.elem();
			it.next();
		}
		while (it != l->cend()) {
			cout << " " << it.elem();
			it.next();
		}
		cout << endl;
	}
}

List<int>* concatena(List<int>* l1, List<int>* l2){
    List<int>* ret = new List<int>();
    List<int>::ConstIterator it1 = l1->cbegin();
    List<int>::ConstIterator it2 = l2->cbegin();
    while(it1 != l1->cend() || it2 != l2->cend()){
        if(it2==l2->cend()){
            ret->push_back(it1.elem());
            it1.next();
        }else if(it1==l1->cend()){
            ret->push_back(it2.elem());
            it2.next();
        }else if(it1.elem()<it2.elem()){
            ret->push_back(it1.elem());
            it1.next();
        }else{
            ret->push_back(it2.elem());
            it2.next();
        }
    }
    return ret;
}


int main() {
	int n1, n2, numCasos;
	List<int>* concatenada = new List<int>();
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {

		List<int>* l1 = new List<int>();
		char c;
		cin.get(c);
		c = cin.peek(); // Nos dice el siguiente caracter pero sin consumirlo
		while (c != '\n') {
			cin >> n1; // como sabemos que no viene el salto de l�nea leemos el siguiente entero
			l1->push_back(n1);
			c = cin.peek();
		}
		List<int>* l2 = new List<int>();
		char d;
		cin.get(d);
		d = cin.peek();
		while (d != '\n') {
			cin >> n2;
			l2->push_back(n2);
			d = cin.peek();
		}
		concatenada = concatena(l1, l2);
		mostrarLista(concatenada);
		delete l1;
		delete l2;
	}
	return 0;
}