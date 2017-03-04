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
#include <iostream>    // cin, cout
#include <algorithm>  // max
#include <limits>
using namespace std;

#define MAX 10000
  
int solve(int V[], int N){
	int p = 0, n = 1, m = V[0], s = V[0];
	while ( n < N ){
		s = max(s, V[n]);
		if (V[n] <= m){
			p = n;
			m = max( m, s);
		}
		n++;
	}
    return p;
}


int main(int argc, char **argv){
    int n,
        N,
        A[MAX];

    cin >> n;
    for (int i=0; i < n ; i++){
        cin >> N ;
        for (int j=0; j < N ; j++){
            cin >> A[j];
        }
		cout << solve(A,N) << endl;
    }
    return 0;
}
