#include "SetOfInts3.h"
#include <iostream>
using namespace std;
#define MAX 10000
#include <stdlib.h> 
int pruebas1(){
	SetOfInts3 *s =  new SetOfInts3();
	SetOfInts3 *s2 =  new SetOfInts3();
	cin >> *s;
	cin >> *s2;
	cout << *s << endl;
	cout << *s2 << endl;
	if(*s== *s2) cout << "son iguales"<< endl;
	else cout << "no son iguales"<< endl;
	delete s;
	delete s2;
	return 0;
}

int pruebas2(){
	SetOfInts3 *s =  new SetOfInts3();
	SetOfInts3 *s2 =  new SetOfInts3();
	cin >> *s;
	cin >> *s2;
	cout << *s << endl;
	cout << *s2 << endl;
	if(*s < *s2) cout << "Es subconjunto"<< endl;
	else cout << "No es subconjunto"<< endl;
	delete s;
	delete s2;
	return 0;
}

void solve(int V[],int numElems, SetOfInts3& s){
	
	for(int i=0; i< numElems; i++){
		if(numElems == 1 || pos == numElems - 1){
			cout << s.getMin();
		}else{
			cout << s.getMin() << " ";
		}
		s.removeMin();
	}
	cout << endl;
}

int main(){
	int numElems;
	int V[MAX];
	cin >> numElems;
	while( numElems != 0 ){
		SetOfInts3 *s = new SetOfInts3();
		int n, i = 0;
		cin >> n;
		s->add(n);
		while( n != -1 ){
			V[i] = n;
			s->add(n);
			i++;
			cin >> n;
		}
		solve(V,numElems, *s); 
		delete s;
		cin >> numElems;
	}
    return 0;
}


