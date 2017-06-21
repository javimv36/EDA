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

int navegables(Arbin<int> a, int &caudal)
{
    if (a.esVacio()){
        caudal = 0;
        return 0;
    }
    else if(a.hijoIz().esVacio()&&a.hijoDr().esVacio()){
        caudal = 1;
        return 0;
    }
    else{
        int caudal_iz=0, caudal_dr=0;
        int navegables_iz = navegables(a.hijoIz(), caudal_iz);
        int navegables_dr = navegables(a.hijoDr(), caudal_dr);
        caudal = caudal_iz + caudal_dr - a.raiz();
        int nav = navegables_iz + navegables_dr;
        nav+=(caudal_iz>=3)?1:0;
        nav+=(caudal_dr>=3)?1:0;
        caudal=(caudal<0)?0:caudal;
        return nav;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        Arbin<int> arbol;
        arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
        int caudal=0;
	    cout << navegables(arbol, caudal) << endl;
   }
}