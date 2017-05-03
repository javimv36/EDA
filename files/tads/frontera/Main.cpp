#include <iostream>
#include <algorithm>
#include "Arbin.h"

using namespace std;

template <class T>
Arbin<T> leerArbol(const T &repVacio)
{
    T elem;
    cin >> elem;
    if (elem == repVacio)
	return Arbin<T>();
    else
    {
	Arbin<T> hi = leerArbol(repVacio);
	Arbin<T> hd = leerArbol(repVacio);
	return Arbin<T>(hi, elem, hd);
    }
}

void resuelveCaso()
{
    Arbin<int> arbol;
    arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
}

int main()
{
	resuelveCaso();
}