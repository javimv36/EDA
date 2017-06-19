#include <iostream>
#include <algorithm>
#include "Arbin.h"
#include "List.h"

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

bool genealogico(Arbin<int> a, int &gen)
{
    if (a.esVacio()){
        gen = 0;
        return true;
    }
    else if(a.hijoIz().esVacio()&&a.hijoDr().esVacio()){
        gen = 1;
        return true;
    }
    else{
        bool genealogico_iz = true, genealogico_dr = true;
        int generaciones_iz = 0, generaciones_dr = 0;
        int edad_iz = -2, edad_dr = -2;
        if (!a.hijoIz().esVacio()){
            genealogico_iz = genealogico(a.hijoIz(), generaciones_iz);
            edad_iz = a.hijoIz().raiz();
        }
        if (!a.hijoDr().esVacio()){
             genealogico_dr = genealogico(a.hijoDr(), generaciones_dr);
             edad_dr = a.hijoDr().raiz();
        }
        gen = ((generaciones_iz>generaciones_dr)?generaciones_iz:generaciones_dr)+1;
        return(a.raiz()>=edad_iz+18) && (a.raiz()>=edad_dr+18) && (edad_iz>=edad_dr+2 && genealogico_iz && genealogico_dr);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        Arbin<int> arbol;
        int generaciones;
        arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
	    genealogico(arbol, generaciones)?cout << "YES " << generaciones:cout << "NO";
        cout << endl;
    }
}