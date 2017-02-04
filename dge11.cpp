/*
Encuentra la  ́ultima posicion de equilibrio

Implementa una funcion que resuelva el siguiente problemaa:

P≡{n≥0} fun xxxx(int a[],int n) return int p
Q≡{(−1≤p < n) ∧ numUnos(a, p) = numCeros(a, p) ∧ ∀ u:p < u < n:numUnos(a, u)!=numCeros(a, u)}
dondenumUnos(a, x)≡#u: 0≤u≤x:a[u] = 1 y numUnos(a, x)≡#u: 0≤u≤x:a[u] = 0.

Requisitos de implementacion. Indicar el coste de la solucion obtenida.
La  funcion  que  resuelve  el  problema  debe  recibir  los  datos  en  un
vector  y  devolver  el  valor  de  la posicion (observad que puede ser -1).

Entrada

La entrada comienza con el numero de casos de prueba.  Cada caso de prueba
tiene dos lıneas.  En laprimera lınea se indica el tamaño del vector, en
la segunda los valores separados por blancos.

Salida

Para cada caso de prueba se escribe en una lınea el valor de la posicion
pedida.  Si el tamano del vector es cero la posicion debe ser -1.

Entrada de ejemplo
5
8
2 1 1 0 2 3 0 2
6
0 1 0 1 1 1
5
1 1 1 1 1
4
2 3 2 3
1
0

Salida de ejemplo
7
3
-1
3
-1


*/
//Author Javi
#include <iostream>
using namespace std;
#define MAX 100000

int solve(int V[], int n){
  int nCeros, nUnos = 0;
  int p=-1;
  for (int i=0;i<n;i++){
    nCeros+=(V[i]==0);
    nUnos+=(V[i]==1);
    cout << "unos: " << nUnos << " ceros: " << nCeros << endl;
    p=(nUnos==nCeros)?i:p;
  }
  return p;
}

int main(int argc, char **argv)
{
  int N;
  int n;
  int V[MAX];
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> n;
    for (int j=0; j<n; j++)cin >> V[j];
      cout << solve(V,n) << endl;
  }
  return 0;
}
