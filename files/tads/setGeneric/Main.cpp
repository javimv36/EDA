#include "Set.h"
#include <iostream>
#define MAX 10000
#include <stdlib.h>
using namespace std;

template<class T>
void solve(int numElems, Set<T>& s){
	int n = s.getSize();
	while(n>numElems){
		s.removeMin();
		n--;
	}
	while(n > 0){
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
			Set<int> *s = new Set<int>();
			int entrada;
			cin >> entrada;
			while(entrada != -1){
				s->add(entrada);
				cin >> entrada;
			}
			solve(numElems, *s);
			delete s;
		}else {
			Set<string> *s = new Set<string>();
			string entrada;
			cin >> entrada;
			while(entrada != "FIN"){
				s->add(entrada);
				cin >> entrada;
			}
			solve(numElems, *s);
			delete s;
		}

		cin >> c;
	}
  return 0;
}
