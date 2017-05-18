#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include <climits>

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

int encontrarTesoro(Arbin<int> caminos, int &minDragones){
	int dragones_iz = INT_MAX;
	int dragones_de = INT_MAX;
	int entrada_iz = 0;
	int entrada_de = 0;
	int entrada = 0;
	if (caminos.esVacio()){
		return 0;
	}
	if (caminos.hijoIz().esVacio() && caminos.hijoDr().esVacio()){
		minDragones = 0;
		return caminos.raiz();
	}


	entrada_iz = encontrarTesoro(caminos.hijoIz(), dragones_iz);
	entrada_de = encontrarTesoro(caminos.hijoDr(), dragones_de);



	if (dragones_iz <= dragones_de){
		minDragones = dragones_iz;
		entrada = entrada_iz;
	}
	else{
		minDragones = dragones_de;
		entrada = entrada_de;
	}
	if (caminos.raiz() == 1){
		minDragones += 1;
	}
	return entrada;

}

void resuelveCaso()
{
	Arbin<int> caminos;
	int entrada, minDragones;
	caminos = leerArbol(-1); // -1 es la repr. de arbol vacio
	entrada = encontrarTesoro(caminos, minDragones);
	cout << entrada << endl;
}

int main()
{
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
		resuelveCaso();

	return 0;
}