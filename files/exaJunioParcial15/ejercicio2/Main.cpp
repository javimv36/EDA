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

    Preguntas:
        He entendido el ejercicio como que hay que resolver el problema recogiendo a los excursionistas
        como dice el enunciado: de uno en uno. Es decir que tengo que resolver el problema bajando hasta
        encontrar un excursionista atrapado y en ese momento llevarlo a la cima contabilizando el tiempo
        que conlleve. El problema es que puede que más abajo de ese camino haya otro excursionista atrapado
        y para poder llegar a él no puedo encontrar a ningún excursionista en el camino. Esto me lleva
        a querer cambiar el valor de la raiz cuando me encuentre a un excursionista atrapado.

        Otra opción que se me ocurre es llevar la cuenta de lo que llevo por cada hijo pero esta
        esta implementación respetando la cabecera que exige el problema se me hace compleja.

        Otra opción es que haya entendido mal el problema.
    
*/
int tiempoAyuda(const Arbin<char> &a)
{
    if (a.esVacio()) //El árbol es vacio
        return 0;
    else if (a.hijoIz().esVacio()&&a.hijoDr().esVacio()){ //El nodo es hoja
        return (a.raiz() == 'x')?2:0; //si hay alguien devuelve 2 si no 0 (habría que cambia el valor de la raiz)
    }
    else if (a.raiz() == 'x') // El nodo tiene un excursionista atrapado
    {
        //a._ra='p';    
        // Sabiendo que el atributo es privado, 
        //¿cómo se modifica, si se puede, para no volver a recoger al 
        //excursionista 'x' y dejar ese paso libre 'p'
        return 2;
    }
    else
    {
        int horasIz = 0, horasDr = 0, tiempo = 0;
        tiempo = tiempoAyuda(a.hijoIz());
        horasIz += tiempo+2;
        while (tiempo != 0) //¿Es correcto bajar tantas veces como 
                            //excursionistas haya atrapado en cada hijo del árbol?
                            //Esto lo hago entendiendo
        {
            horasIz += tiempo+2;
            tiempo = tiempoAyuda(a.hijoIz());
        }
        tiempo = tiempoAyuda(a.hijoDr());
        while (tiempo != 0) //Igualmente por el hijo derecho baja a recoger a los
                            //excursionistas tantas veces como excursionistas haya
        {
            horasDr += tiempo+2;
            tiempo = tiempoAyuda(a.hijoDr());
        }
        return horasIz + horasDr;
    }
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