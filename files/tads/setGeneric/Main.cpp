#include "Set.h"
#include <iostream>
#define MAX 10000
#include <stdlib.h>
using namespace std;


void solve(int numElems, Set<>& s){
	int n = s.getSize();
	while(n>numElems){
		s.removeMin();
		n--;
	}
	while(n >= 0){
		cout << s.getMin() << " ";
		s.removeMin();
		n--;
	}
	cout << endl;
}

int main(){
	char c;
	int numElems;
	int V[MAX];
	cin >> c;
	Set<> *s = new Set();
	while(!cin.fail()){
		cin >> numElems;
		if(c=='N'){
			int entrada;
			cin >> entrada;
			while(entrada != -1){
				s->add(entrada);
				cin >> entrada;
			}
		}else if(c=='P'){
			string entrada;
			cin >> entrada;
			while(entrada != "FIN"){
				s->add(entrada);
				cin >> entrada;
			}

		}
		solve(numElems, *s);
		cin >> c;
	}
	delete s;
    return 0;
}
