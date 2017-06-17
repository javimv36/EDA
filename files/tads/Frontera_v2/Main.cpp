#include<iostream>
#include "Arbin.h"
using namespace std;


Arbin<int> leerArbol(const int& repVacio) {
	int elem;
	Arbin<int> hi;
	Arbin<int> hd;
	cin >> elem;
	if (elem == repVacio) {
		return Arbin<int>();
	}
	else {
		hi = leerArbol(repVacio);
		hd = leerArbol(repVacio);
		return Arbin<int>(hi, elem, hd);
	}
}

void calcular_frontera(Arbin<int> arbol, List<int> &frontera) {
	Arbin<int> hi, hd;
	
	if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
		frontera.push_back(arbol.raiz());
	}
	else {
		calcular_frontera(arbol.hijoIz(), frontera);
		calcular_frontera(arbol.hijoDr(), frontera);
	}
}

void resuelveCaso() {
	int n;
	Arbin<int> arbol;
	List<int> frontera;

	arbol = leerArbol(-1);
	if (!arbol.esVacio()) {
		calcular_frontera(arbol, frontera);
		while (frontera.size() != 0) {
			n = frontera.front();
			frontera.pop_front();
			cout << n << " ";
		}
		cout << endl;
	}
}

int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}
	return 0;
}