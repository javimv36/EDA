#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

void solve (Stack<int>* pila){
	int suma=0, elem=0;
	while (pila->size()>1) {
		elem=pila->top();
		pila->pop();
		suma+=elem;
		cout << elem << " + ";
	}
	if(!pila->empty()){
		elem=pila->top();
		pila->pop();
		suma+=elem;
		cout << elem;
	}	

	cout << " = " << suma << "\n";
}
int main() {

	int n, elem;
	cin >> n;
	while(n!=-1){
		Stack<int>* pila = new Stack<int>();
		if (n==0){
			pila->push(n);
		}
		while (n > 0) {
			elem = n%10;
			n/=10;
			pila->push(elem);
		}
		solve(pila);
		delete pila;
		cin >> n;
	}
	return 0;
}