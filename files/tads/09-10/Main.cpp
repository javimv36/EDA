#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "List.h"

using namespace std;


Arbin<char> reconstruirArbol(List<char> pre)
{
	if (pre.empty())
	{
		return Arbin<char>();
	}
	List<char>::ConstIterator it_pre = pre.cbegin();

	char raiz = pre.back();
	List<char> pre_iz;
	List<char> pre_dr;
	Arbin<char> arbol;
	while (it_pre.elem() != '.')
	{
		pre_iz.push_back(it_pre.elem());
		it_pre.next();
	}
	it_pre.next();
	while (it_pre.elem() != '.')
	{
		pre_dr.push_back(it_pre.elem());
		it_pre.next();
	}
	Arbin<char> iz = reconstruirArbol(pre_iz);
	Arbin<char> dr = reconstruirArbol(pre_dr);
	return Arbin<char>(iz, raiz, dr);
}

int main()
{
	char a;
	int numCasos;

	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {
		List<char> preorden = List<char>();
		char c;
		cin.get(c);
		c = cin.peek(); // Nos dice el siguiente caracter pero sin consumirlo
		while (c != '\n') {
			cin >> a; // como sabemos que no viene el salto de l�nea leemos el siguiente entero
			preorden.push_back(a);
			c = cin.peek();
		}
		Arbin<char> arb = reconstruirArbol(preorden);
	}
		
	return 0;
}