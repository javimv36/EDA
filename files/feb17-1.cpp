/*
1. (4 puntos) Especifica, diseña e impelmenta una funcion que reciba un vector de enteros
de longitud 0<=n<=1000 y un parametro d>0 y devuelva si el vector es creciente por
los pelos y d-divertido. Escribe el invariante y funcion de cota que permitan demostrar
la correccion del algoritmo conseguido.

La entrada comienza con una linea que contiene el numero de casos de prueba. Cada caso de
prueba contendrá los valores d y n y los elementos del vector. El programa escribirá SI si
es creciente por los pelos y d-divertido y NO en caso contrario.

NOTA:
Un vector es CRECIENTE POR LOS PELOS cuando a demas de ser creciente, la
diferencia entre un elemento y el elemento siguiente es como mucho 1.

1 2 3 4 SI
1 2 2 3 SI
1 1 1 1 SI
1 2 1 3 NO

Un vector es aburrido si los elementos aparecen muchas veces. Y es D-DIVERTIDO si ningun
elemento se repite mas de D-veces
Ejemplos:
  1-divertido
    1 2 3 4
    4 3 7 0
  3-divertido
    6 7 6 6
  2-divertido
    7 3 7 3
    7 3 7 0
  4-divertido
    9 9 9 9
*/
#include <iostream>
#define MAX 1000
using namespace std;

bool solve(int n, int d, int V[]){
  int i;
  int C[MAX];
  for(i=1; (((V[i]==V[(i-1)])||(V[i]==V[i-1]+1))&&(V[i]!=V[(i+d)])&&(i<n));i++);//me salgo del vector por la derecha
  return (i>=n-1);
}

int main(){
  int n;
  int d;
  int V[MAX];
  cin >> d;
  cin >> n;
  for (int i=0;i<n;i++)cin >> V[i];
  cout << ((solve(n,d,V))?"SI":"NO") << endl;
  return 0;
}
