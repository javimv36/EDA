#include <iostream>
#include <fstream>
#include "Stack.h"
using namespace std;
int main() {
	int numVagones;
	Stack<int> pila;
	int orden[100000];
	bool posible = false;
	cin >> numVagones;
	while (numVagones != 0) {
		int vagon_llegada = 0;
		pila = Stack<int>();
		bool sacar = true;
		for (int i = 0; i < numVagones; i++) {
			cin >> orden[i];
		}
		for (int i = 1; (i <= numVagones); i++) {
			pila.push(i);
			cout << "Wagon " << i << " in" << endl;
			while (!pila.empty() && pila.top() == orden[vagon_llegada]) {
				cout << "Wagon " << pila.top() << " out" << endl;
				pila.pop();
				vagon_llegada++;
			}
		}
		while (sacar && vagon_llegada < numVagones){
			if (pila.top() == orden[vagon_llegada]) {
				cout << "Wagon " << pila.top() << " out" << endl;
				pila.pop();
				vagon_llegada++;
				sacar = true;
			}
			else sacar = false;		
		}
		if (pila.empty() && vagon_llegada == numVagones){
			posible = true;
		}
		if (posible) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}	
		posible = false;
		cin >> numVagones;
	}

	return 0;
}

