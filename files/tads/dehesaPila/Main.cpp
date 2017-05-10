#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

bool comprobarOrden(Stack<int> &pila, int orden, int numVagones) {
	int cima = 0;
	cima = pila.top();
	if (cima != orden) {
		return false;
	}
	else {
		pila.pop();
		cout << "Wagon " << orden << " out" << endl;
		return true;
	}
}

int main() {
	
	int numVagones;
	Stack<int> pila;
	int orden;
	bool posible = true;


	cin >> numVagones;
	while (numVagones != 0) {
		for (int i = 0; i < numVagones; i++) {
			cout << "Wagon " << i + 1 << " in" << endl;
			pila.push(i + 1);
		}
		for (int i = 0; i < numVagones; i++) {
			cin >> orden;
			if (!pila.empty() && posible) {
				posible = comprobarOrden(pila, orden, numVagones);
			}
		}
		if (posible) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
		posible = true;
		cin >> numVagones;
	}

	return 0;
}

