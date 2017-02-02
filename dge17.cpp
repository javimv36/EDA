/*
P ́erfil de una curva c ́oncava

Dados una serie de valores cuyo perfil se ajusta al de una curva concava,
 es decir decrecen hasta undeterminado valor a partir del cual son crecientes,
  se pide encontrar el valor del mınimo.  Se admiten lıneas estrictamente cre
  cientes o estrictamente decrecientes.

  Requisitos de implementaci ́on.

  indicar la recurrencia utilizada para el calculo del coste y el coste de la
  soluci ́on obtenida.La soluci ́on obtenida debe emplear la t ́ecnica de divide
  y vencer ́asLa funci ́on que resuelve el problema debe recibir los datos en un
  vector y devolver el valor del m ́ınimo.

  Entrada

  La entrada consta de una serie de casos de prueba.  Cada caso de prueba consta
   de dos l ́ıneas, en laprimera se indica el n ́umero de elementos del vector
   y en la segunda los valores del vector separados porblancos.El n ́umero de
   elementos del vector es mayor que cero.

   Salida

   para cada caso de prueba se escribe en una l ́ınea el m ́ınimo de la curva.

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
#define DYV

bool solve();
int minimoConcava(int V[], int l);

int main(int argc, char **argv){
  while(solve());
  return 0;
}

  bool solve(){
    int n; //numero de elementos del caso
    int V[MAX];

    cin >> n;
    while(n>0){
      for (int i=0; i<n; i++) cin >> V[i];
      cout << minimoConcava(V,n) << endl;
      cin >> n;
    }
    return false;
  }
#ifdef DYV

  int min(int a, int b){
    return (a<b)?a:b;
  }
  int minimoConcava(int V[], int l){
    int m1;
    int m2;
    if (l==1)return V[0];
    if (l==2)
      return min(V[0],V[1]);
    if (l==3){
      m1 = min(V[0],V[1]);
      m2 = min(m1,V[2]);
    }
    else{
      int d=l/2;
      m1 =minimoConcava(V, d);
      m2 =minimoConcava(V+d, l-d);
    }
    return min(m1,m2);
  }
#else
  int minimoConcava(int V[], int l){
    int min = V[0];
    for (int i =1; i<l; i++){
      min=(min<V[i])?min:V[i];
    }
  return min;
  }
  #endif
