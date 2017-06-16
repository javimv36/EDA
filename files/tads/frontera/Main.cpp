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

List<int> concatenaListas(List<int> l_iz, List<int> l_dr){
    while(!l_dr.empty()){
        int e =l_dr.front();
        l_dr.pop_front();
        l_iz.push_back(e);
    }
    return l_iz;
}
List<int> frontera(Arbin<int> a)
{
    List<int> l;
    if(a.esVacio()){    //si hemos llegado por un nodo sin hijo en uno de los lados
        //devolver lista vacia
        return l;
    }
    if(a.hijoIz().esVacio()&&a.hijoDr().esVacio()){ //si el nodo es hoja
        l.push_back(a.raiz());
        return l;
    }else{      //si es un nodo con al menos un hijo
        List<int> l_iz = frontera(a.hijoIz());
        List<int> l_dr = frontera(a.hijoDr());
        l = concatenaListas(l_iz, l_dr);
        return l;
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n;i++){
        Arbin<int> arbol;
        arbol = leerArbol(-1); // -1 es la repr. de arbol vacio
	    List<int> frontera_list = frontera(arbol);
        while(!frontera_list.empty()){  //imprimir lista
            int e =frontera_list.front();
            frontera_list.pop_front();
            cout << e << " ";
        }
        cout << endl;
    }
}