#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

bool comprobarOrden(Stack<int>* pila, int* orden, int numVagones){

	int cima = 0;
	for (int i = 1; i <= numVagones; i++){
		cima = pila->top();
		if (cima != orden[i - 1]){

			return false;
		}
		else{
			cout << "Wagon " << cima << " out" << endl;
			pila->pop();
		}
	}
	return true;
}

int main() {
	const int MAX_SIZE = 99999;
	int numVagones;
	Stack<int>* pila = new Stack<int>();
	int orden[MAX_SIZE];
	cin >> numVagones;
	
	while (numVagones != 0){	
		for (int j = 0; j < numVagones; j++){
			cin >> orden[j];
		}
		for (int i = 1; i <= numVagones; i++){
			pila->push(i);
			cout << "Wagon " << i << " in" << endl;
		}

		if (!pila->empty()){
			if(comprobarOrden(pila, orden, numVagones)){
				cout << "POSSIBLE" << endl;
			}
			else{
				cout << "IMPOSSIBLE" << endl;
			}
		}
		cin >> numVagones;
	}
	
	return 0;
}

