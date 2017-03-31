#include <iostream>
#include <fstream>
#include "List.h"
#include <cstdlib>

using namespace std;


void mostrarLista(List<int>* l){
	List<int>::ConstIterator it = l->cbegin();
	if (it != l->cend()){
		cout << it.elem();
		it.next();
	}
	while (it != l->cend()){
		cout << " " << it.elem();
		it.next();
	}
	cout << endl;
}

void duplicarPicos(List<int>* l, int& k){
	List<int>::Iterator it = l->begin();
	int suma = 0;
	while (it != l->end()){
		if (suma == it.elem()){
			l->insert(it.elem(), it);
			k++;
		}
		suma += it.elem();
		++it;
	}
}

int main(){
	int n, numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		List<int>* l = new List<int>();
		char c;
		cin.get(c);
		c = cin.peek(); // Nos dice el siguiente caracter pero sin consumirlo
		while (c != '\n'){
			cin >> n; // como sabemos que no viene el salto de línea leemos el siguiente entero
			l->push_back(n);
			c = cin.peek();
		}
		int k=0;
		duplicarPicos(l,k);
		cout << k << ": ";
		mostrarLista(l);
		delete l;
	}


	
	return 0;
}

