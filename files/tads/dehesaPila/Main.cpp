#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;


int main() {
	const int MAX_SIZE = 100000;

	int a[MAX_SIZE];

	int numElems, i = 0, aux;

	bool posible = true;
	Stack<int>* pila = new Stack<int>();

	cin >> numElems;
	if (numElems!=0) {
		cin >> a[i];
		pila->push(a[i]);
		i++;
		while (i < numElems) {
			cin >> a[i];
			if (a[i] < a[i - 1]) {
				aux = a[i-1];
				pila->pop();
				pila->push(a[i]);
				pila->push(a[i-1]);
				i++;
			}
			else {
				pila->push(a[i]);
				i++;
			}
		}
		for (int j = 0; j < i ; j++) {
			if (a[j] < a[0]) {
				aux = a[0];
				a[j] = a[j + 1];
				a[0] = aux;
			}
			for (int i = 0; i < numElems; i++) {
				cout << "Vagon " << a[i] << " in" << endl;
			}
			
		}
		while (!pila->empty() && posible) {
			/*cima = pila->top();
			pila->pop();
			cout << "Vagon " << i << " out" << endl;
			nuevaCima = pila->top();
			
			if (cima == nuevaCima) {
				pila->pop();
			}
			else posible = false;*/
			pila->dehesaPila(posible);
		}if (posible) {
			cout << "POSSIBLE" << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}