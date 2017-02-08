/*
????? Continuación

Implementar un algoritmo que resuelva el siguiente problema:

P ≡ {0 < n < 10.000}
fun xxxx (int a[], int n) return int p
Q ≡ {(0 ≤ p < n) ∧ (menores(a, n, p) ∧ (¬Ej : 0 ≤ j < p : menores(a, n, j)}
donde menores(a, n, p) ≡ ∀u, w : 0 ≤ u ≤ p < w < n : a[u] < a[w]

Requisitos de implementación.
El orden de complejidad del algoritmo debe ser lineal respecto al número de elementos del vector.

Entrada

La entrada comienza con un valor entero que indica el número de casos de prueba. Cada caso de
prueba consta de dos líneas. La primera contiene el valor de n. La segunda línea contiene los valores del
vector.

Salida

Para cada caso de prueba se escribe en una línea el valor de p.

Entrada de ejemplo
2
6
3 2 4 1 7 6
15
2 1 3 1 2 6 5 6 9 10 10 9 13 15 13

Salida de ejemplo
3
4
*/
#include <iostream>
using namespace std;
#define MAX 100000

int min(int a, int b){return (a<b)?a:b;}
int max(int a, int b){return (a>b)?a:b;}

bool menores (int a[], int n, int p){
  int u,w;
  for (u=0; u>=p; u++){
    for(w=p+1; w<n; w++)
    if (!(a[u] < a[w]))return false;
  }
  return true;
}

int solve(int a[], int n){
	int p;
	for(p=0; p<n && !(menores(a,n,p));p++){
    for(int j=0; j<p; j++){
     if (!menores(a,n,j))break;
    }
  }
  return p;
}

int main(int argc, char **argv){
	int N;
	int n;
	int V[MAX];
	cin >> n;
	for(n;n>0;n--){
		cin>>N;
		for(int i=0; i<N; i++)cin>>V[i];
		cout << solve(V, N) << endl;
	}
}
