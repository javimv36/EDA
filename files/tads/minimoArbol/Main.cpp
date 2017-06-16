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
template <class T>
T minimoArbol(Arbin<T> a)
{
    if(a.esVacio()){
        return NULL;
    }
    else if(a.hijoIz().esVacio()&&a.hijoDr().esVacio()){
        return a.raiz();
    }
    else{
        T min_iz = minimoArbol(a.hijoIz());
        T min_dr = minimoArbol(a.hijoDr());
        T min_hijos = (min_iz < min_dr)?min_iz:min_dr;
        T min = (min_hijos < a.raiz())?min_hijos:a.raiz();
        return min;
    }
}

int main()
{
    char c;
    while(true){
        cin >> c;
        if(c =='N'){
            Arbin<int> a;
            a = leerArbol(-1); // -1 es la repr. de arbol vacio
            cout << minimoArbol(a) << endl;
        }else if (c=='P'){
            Arbin<string> a;
            string vacio="#";
            a = leerArbol(vacio); // # es la repr. de arbol vacio
            cout << minimoArbol(a) << endl;
        }
        
    }
}