/*
LICENSE:
Esta obra está bajo una licencia de Creative Commons Reconocimiento 4.0 Internacional.
http://creativecommons.org/licenses/by/4.0/


  Perfil de una curva concava

  Dados una serie de valores cuyo perfil se ajusta al de una curva concava,
  es decir decrecen hasta undeterminado valor a partir del cual son crecientes,
  se pide encontrar el valor del mÄ±nimo.  Se admiten lÄ±neas estrictamente cre
  cientes o estrictamente decrecientes.

  Requisitos de implementaci Ìon.

  indicar la recurrencia utilizada para el calculo del coste y el coste de la
  soluci Ìon obtenida.La soluci Ìon obtenida debe emplear la t Ìecnica de divide
  y vencer ÌasLa funci Ìon que resuelve el problema debe recibir los datos en un
  vector y devolver el valor del m ÌÄ±nimo.

  Entrada

  La entrada consta de una serie de casos de prueba.  Cada caso de prueba consta
   de dos l ÌÄ±neas, en laprimera se indica el n Ìumero de elementos del vector
   y en la segunda los valores del vector separados porblancos.El n Ìumero de
   elementos del vector es mayor que cero.

   Salida

   para cada caso de prueba se escribe en una l ÌÄ±nea el m ÌÄ±nimo de la curva.

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
#include <algorithm> // min
using namespace std;
#define MAX 10000
#define DYVONELINE 1
#define DYV 0
#define IT 0
#define REC 0

/*
fun minimoConcava(V,l){
if (l=1) dev V[0]
if (l=2) dev min(V);
if (l=3) dev min(v);
else
 if (V[mitad-1] < V[mitad])
  dev minimoConcava(V, mitad)
 else
  dev minimoCincava(Vmitad, mitad)
}
*/

#if DYVONELINE    //solucion divide y vencerÃ¡s en una linea

  int minimoConcava(int V[], int l){
       return (l==1)?V[0]:((l==2)?(min(V[0],V[1])):((V[(l/2)-1]<V[l/2])?minimoConcava(V, (l/2)):minimoConcava((V+(l/2)), (l-(l/2)))));
  }

#elif DYV   //solucion divide y venceras

  int minimoConcava(int V[], int l){
    if (l==1)return V[0];
    if (l==2)return min(V[0],V[1]);
    else return (V[(l/2)-1]<V[l/2])?minimoConcava(V, (l/2)):minimoConcava(V+(l/2), l-(l/2));
  }

#elif REC   //solucion recursiva

  int minimoConcava(int V[], int l){
    if (l==1)return V[0];
    if (l==2)return min(V[0],V[1]);
    if (l==3)return min(V[0],min(V[1],V[2]));
    else return min(minimoConcava(V, l/2),minimoConcava(V+d, l-(l/2)));
  }

#elif IT     //solucion iterativo

  int minimoConcava(int V[], int l){
    int min = V[0];
    for (int i =1; i<l; i++){
      min=(min<V[i])?min:V[i];
    }
  return min;
  }

#endif

//CUERPO DEL PROGRAMA
bool solve(){
  int n;
  int V[MAX];
  cin >> n;
  if (!cin){
    return false;
  }else{
    for (int i=0; i<n; i++) cin >> V[i];
    cout << minimoConcava(V,n) << endl;
    return true;
  }
}

int main(int argc, char **argv){
  while(solve());
  return 0;
}
