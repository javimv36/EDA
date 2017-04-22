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

void planificarRescate(Arbin<int> rutas, int rescatados, int &maxRescate, int &grupos)
{

    int gruposI = 0, gruposD = 0;
    int rescatadosI = 0, rescatadosD = 0;
    int maxRescateI = 0, maxRescateD = 0;
    if (rutas.esVacio())
    {
		return;
    }
    planificarRescate(rutas.hijoIz(), rescatadosI, maxRescateI, gruposI);
    planificarRescate(rutas.hijoDr(), rescatadosD, maxRescateD, gruposD);

    maxRescate = (maxRescateI > maxRescateD) ? maxRescateI : maxRescateD;
    grupos = gruposI + gruposD;

    if (rutas.raiz() != 0 && grupos == 0)
	grupos++;

    maxRescate += rutas.raiz();
}

void resuelveCaso()
{
    Arbin<int> rutas;
    int grupos = 0, max = 0;
    rutas = leerArbol(-1); // -1 es la repr. de arbol vacio
    planificarRescate(rutas, 0, max, grupos);
    cout << grupos << " " << max << endl;
}

int main()
{
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; i++)
	resuelveCaso();
}