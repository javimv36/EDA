/*
1. (3,5 puntos) Dado un vector de n elementos (n ≥ 0), se desea obtener la suma
de todos los productos de valores situados en parejas de posiciones distintas
(con una complejidad O(n)).
Ejemplo: para el array con contenido: [1,3,5,7]
se debe devolver 1∗3+1∗5+1∗7+3∗5+3∗7+5∗7.
Para el array con contenido [6,2,5,9,1,2]
se debe devolver: 6∗2+6∗5+6∗9+6∗1+6∗2+2∗5+2∗9+2∗1+2∗2+5∗9+5∗1+5∗2+9∗1+9∗2+1∗2

Se pide:
1. Especicación del algoritmo.
2. Diseño y vericación (o derivación) e implementación del algoritmo iterativo.
3. Justicación de la complejidad.

Especificacion
P{}
fun solve(int )
*/
//Author Javi
#include <iostream>
#define MAX 100000
using namespace std;
/*
  Coste de la funcion O(n)
*/
int sumaTotal(int v[], int n){
  int suma;
  for (int i=suma=0; i<n;i++) suma += v[i]; //Coste O(n)
  return suma/2;
}
/*
  Coste de la función O(n)+O(n) -> 2O(n) -> C*O(n) -> O(n)
*/
int solve(int v[], int n){
  int suma, sumaT=sumaTotal(v,n); //Coste función sumaTotal(v,n) -> O(n)
  for (int i=suma=0; i<n ; i++) suma += (sumaT-v[i])*v[i]; //Coste O(n)
  return suma;
}
/*
int solve(int v[], int n){
  int suma;
  for(int i=suma=0; i<n; i++)
    for (int j=i+1;j<n;j++){
      suma+=(v[i]*v[j]);
    }
  return suma;
}
*/
int main(int argc, char **args){
  int V[MAX];
  int N;
  cin >> N;
  for (int i=0; i<N; i++)cin >> V[i];
  cout << solve(V,N) << endl;
  return 0;
}
