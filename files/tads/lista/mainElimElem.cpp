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



int main(){
	int n, numCasos, elem;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		List<int>* l = new List<int>();
		cin >> n;
		while (n != -1){
			l->push_back(n);
			cin >> n;
		}
		cin >> elem;
		mostrarLista(l);
		l->removeAll(elem);
		mostrarLista(l);
		delete l;
	}
	return 0;
}

