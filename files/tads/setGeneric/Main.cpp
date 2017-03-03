#include "Set.h"
#include <iostream>
#define MAX 10000
#include <stdlib.h>
using namespace std;


void solve(int numElems, Set<T>& s){
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
	
	while(!cin.fail()){
		cin >> numElems;
		if(c=='N'){
		Set<int> *s = new Set();
			int entrada;
			cin >> entrada;
			while(entrada != -1){
				s->add(entrada);
				cin >> entrada;
			}
		}else if(c=='P'){
		Set<string> *s = new Set();
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
