#include <iostream>
#include <fstream>
#include "List.h"

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

int main(){
	
	int n, numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		List<int>* l = new List<int>();
		char c;
		cin.get(c);
		c = cin.peek(); // Nos dice el siguiente caracter pero sin consumirlo
		while (c != '\n'){
			cin >> n; // como sabemos que no viene el salto de l�nea leemos el siguiente entero
			l->push_back(n);
			c = cin.peek();
		}
		l->intercala_nodos();
		mostrarLista(l);
		delete l;
	}
	return 0;
}