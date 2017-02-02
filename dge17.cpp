/*
P ́erfil de una curva c ́oncava

Dados una serie de valores cuyo p ́erfil se ajusta al de una curva c ́oncava,
 es decir decrecen hasta undeterminado valor a partir del cual son crecientes,
  se pide encontrar el valor del m ́ınimo.  Se admitenl ́ıneas estrictamente cre
  cientes o estrictamente decrecientes.

  Requisitos de implementaci ́on.

  ndicar la recurrencia utilizada para el c ́alculo del coste y el coste de la
  soluci ́on obtenida.La soluci ́on obtenida debe emplear la t ́ecnica de divide
  y vencer ́asLa funci ́on que resuelve el problema debe recibir los datos en un
  vector y devolver el valor del m ́ınimo.

  Entrada

  La entrada consta de una serie de casos de prueba.  Cada caso de prueba consta
   de dos l ́ıneas, en laprimera se indica el n ́umero de elementos del vector
   y en la segunda los valores del vector separados porblancos.El n ́umero de
   elementos del vector es mayor que cero.

   Salida

   ara cada caso de prueba se escribe en una l ́ınea el m ́ınimo de la curva.

   Entrada de ejemplo
   5
   7 5 3 8 9
   8
   9 8 7 6 5 4 3 2
   1
   2
   2
   3 5
   10
   34 25 12 10 9 8 7 6 5 9

   Salida de ejemplo
   3
   2
   2
   3
   5
*/
//Author Javi
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000

void solve(unsigned long b, unsigned log n){

}

int main(int argc, char **argv)
{
  int c; //casos a probar
  int b;
  int n;

  cin >> c;
  for (int i=0; i<c; i++){
    cin >> b;
    cin >> n;
    solve(b,n);
  }
  return 0;
}
