#include <iostream>
#include <fstream>
#include "Queue.h"

using namespace std;

int main(){
	
	int pos, a, numCasos, cont = 0;

	cin >> numCasos;
	while (cont < numCasos) {
		Queue<int>* cola = new Queue<int>();
		cin >> a;
		while(a!= -1){
			cola->push_back(a);
			cin >> a;
		}
		cont++;
		cin >> pos;
		cout << *cola;
		cola->cola_injusta(pos);
		cout << *cola;
		delete cola;
	}
	return 0;
}