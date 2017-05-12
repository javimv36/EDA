#include <iostream>
#include <list>
#include "TreeMap.h"
#include <string>

using namespace std;

void printLista(const list<int>& l, ostream& sout){
	list<int>::const_iterator it = l.cbegin();
	if (it != l.cend()){
		sout << *it;
		++it;
	}
	while (it != l.end()){
		sout << " " << *it;
		++it;
	}
	sout << endl;
}

void aMinusculas(std::string& palabra) {
	for (char& c : palabra) {
		if (c >= 'A' && c <= 'Z')
			c = c - 'A' + 'a';
	}
}

void resuelveCaso(int numLineas){
	char c;
	string palabra;
	TreeMap<string, list<int>> diccionario;

		for (int linea = 1; linea <= numLineas; linea++){
			cin.get(c);

			while (c != '\n'){
				cin.unget();
				cin >> palabra;
				if (palabra.length() > 2){
					aMinusculas(palabra);
					
					if (!diccionario[palabra].empty()){
						if (diccionario[palabra].back() == linea){
							diccionario[palabra].pop_back();
						}
						diccionario[palabra].push_back(linea);
					}
					else{
						list<int> l;
						l.push_back(linea);
						diccionario.insert(palabra, l);
					}
				}
				
				cin.get(c);
			}
		}
		TreeMap<string, list<int>>::ConstIterator it = diccionario.cbegin();
		while (it != diccionario.cend()){
			cout << it.key() << " ";
			printLista(it.value(), cout);
			it.next();
		}
		cout << "----" << endl;
}

int main(){
	int numLineas;
	char c;
	cin >> numLineas; cin.get(c);
	while (numLineas != 0){
		resuelveCaso(numLineas);
		cin >> numLineas; cin.get(c);
	}
}