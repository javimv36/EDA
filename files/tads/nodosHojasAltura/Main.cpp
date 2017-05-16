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

void analizaArbol(Arbin<char> arbol, int &nodos, int &hojas, int &altura){
    if(arbol.raiz()==NULL){
        nodos=0;
        hojas=0;
        altura=0;
        return;
    }else if (arbol.hijoIz().raiz().esVacio()&&arbol.hijoDr().raiz().esVacio()){
        nodos = 1;
        altura = 1;
        hojas = 1;
        return;
    }else{
        int altIz = 0, altDr = 0, nodosIz = 0, nodosDr = 0, hojasIz = 0, hojasDr = 0;
        analizaArbol(arbol.hijoIz(), nodosIz, hojasIz, alturaIz);
        analizaArbol(arbol.hijoDr(), nodosDr, hojasDr, alturaDr);
        if (alturaIz>alturaDr){
            altura = alturaIz + 1;
        }else{
            altura = alturaDr + 1;
        }
        nodos = nodosIz+nodosDr+1;
        hojas = hojasIz + hojasDr;
        return;
    }
}

void resuelveCaso()
{
    Arbin<char> arbol;
    char c = '.';
    arbol = leerArbol(c); 
    int nodos = 0, hojas = 0, altura =0;
    analizaArbol(arbol, nodos, hojas, altura);
    cout << nodos << " " << hojas << " " << altura << endl;
}

int main()
{
	resuelveCaso();
}