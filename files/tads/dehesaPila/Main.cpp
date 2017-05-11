#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;


int main() {
	
	int numVagones;
	Stack<int> pila;
	int orden[100000];
	bool posible = false;
	int vagon_llegada = 0;

	cin >> numVagones;

	for (int i = 1; i <= numVagones; i++) {
		cin >> orden[i];
	}
	
	while (numVagones != 0) {
		pila = Stack<int>();
		for (int i = 1; i <= numVagones; i++) {
			pila.push(i);
			cout << "Wagon " << i << " in" << endl;
			if (pila.top() == orden[vagon_llegada]) {
				cout << "Wagon " << pila.top() << " out" << endl;
				pila.pop();
				vagon_llegada++;
			}
		}
		if(pila.empty() && vagon_llegada == numVagones){
			posible = true;
		}
		if (posible) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
		
		vagon_llegada = 0;
		posible = false;
		cin >> numVagones;
	}

	return 0;
}

