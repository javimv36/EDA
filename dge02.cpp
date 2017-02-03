/*
?????
Implementar un algoritmo que resuelva el siguiente problema:

P ≡ {0 < n < 10.000 ∧ 0 ≤ p < n}
fun xxxx (int a[], int n, int p) return bool b
Q ≡ {b = ∀u, w : 0 ≤ u ≤ p < w < n : a[u] < a[w]}

Requisitos de implementaci´on.
El orden de complejidad del algoritmo debe ser lineal respecto al n´umero de elementos del vector.

Entrada

La entrada comienza con un valor entero que indica el n´umero de casos de prueba. Cada caso de
prueba consta de dos l´ıneas. La primera contiene los valores de n y p. La segunda l´ınea contiene los
valores del vector.

Salida

Para cada caso de prueba se escribe en una l´ınea SI si el resultado de la funci´on es cierto y NO si es
falso.

Entrada de ejemplo
4
15 5
5 7 3 4 7 3 8 9 8 10 8 9 8 9 10
4 0
4 7 5 6
4 3
4 3 6 2
5 2
5 3 4 6 4

Salida de ejemplo
SI
SI
SI
NO
*/
//Author Javi

/*
pseudocode

fun solve(){
  for (i<p) max=max(m,V[i])
  for (j=p+1;j<N) min=min(m,V[j])
  return (max<min);
}
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 10000


bool solve(int A[], int n, int p){
  int i, j, M, m;
  for (i=M=0;i<=p; i++)M=max(M,A[i]);
  for (j=p+1, m=A[j]; j<n; j++)m=min(m, A[j]);
  return M<m;
}

int main(int argc, char **argv)
{
  int c; //casos a probar
  int p;
  int n;
  int A[MAX];
  cin >> c;
  for (int i=0; i<c; i++){
    cin >> n;
    cin >> p;
    for (int j=0; j<n; j++) cin >> A[j];
    if (solve(A,n,p)) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
