#include <iostream>
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

/*
    Podemos utilizar los árboles binarios para representar los caminos en la falda de una
    montaña. La raíz del árbol representa la cima de la que salen una o dos rutas. Las distintas
    rutas según se va ensanchando la falda de la montaña se dividen en dos formando caminos que
    nunca se volverán a conectar. Un escalador está en la cima de la montaña (raíz del árbol) y
    se da cuenta de que en distintas intersecciones (marcadas en el árbol con ’X’) hay amigos que
    necesitan su ayuda para subir. Tiene que bajar a cada una de las ’X’ y ayudarles a subir de
    uno en uno. Implementa una función con la cabecera

        int tiempoAyuda(const Arbin<char> &a);

    que, dado uno de estos árboles binarios, devuelva el tiempo que tardará el escalador en ayudar
    a todos esos amigos si cada tramo de intersección a intersección lleva una hora en ser recorrido
    (en cada uno de los dos sentidos).

    1 p x p p # # x p # # p # # p p # # x p # # p # # p p p # # x p # # p # # x p # # p p # # p # #
    ejemplo de entrada
        1: un único caso
        'p':paso libre
        'x':excursionista atrapado
        '#': representacion arbol vacío
    Caso:
        excursionistas atrapados: 5
        tiempo de rescate: 24h
    
*/
int iTiempoAyuda(const Arbin<char> &a, int nivel)
{
    if (a.esVacio()) //El árbol es vacio
        return 0;
     else    //El nodo no es hoja y puede tener o no excursionista atrapado. Si es así suma 2h*nivel a lo que se tarde por los dos hijos.
        return iTiempoAyuda(a.hijoIz(), nivel+1) + iTiempoAyuda(a.hijoDr(), nivel+1) + ((a.raiz()=='x')?(nivel*2):0);
}

int tiempoAyuda(const Arbin<char> &a){
    return iTiempoAyuda(a, 0);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Arbin<char> a = leerArbol('#');
        cout << tiempoAyuda(a) << endl;
    }
    return 0;
}