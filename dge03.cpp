/*
????? Continuaci´on

Implementar un algoritmo que resuelva el siguiente problema:

P ≡ {0 < n < 10.000}
fun xxxx (int a[], int n) return int p
Q ≡ {(0 ≤ p < n) ∧ (menores(a, n, p) ∧ (¬∃j : 0 ≤ j < p : menores(a, n, j)}
donde menores(a, n, p) ≡ ∀u, w : 0 ≤ u ≤ p < w < n : a[u] < a[w]

Requisitos de implementaci´on.
El orden de complejidad del algoritmo debe ser lineal respecto al n´umero de elementos del vector.

Entrada

La entrada comienza con un valor entero que indica el n´umero de casos de prueba. Cada caso de
prueba consta de dos l´ıneas. La primera contiene el valor de n. La segunda l´ınea contiene los valores del
vector.

Salida

Para cada caso de prueba se escribe en una l´ınea el valor de p.

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
#include <algorithm>
using namespace std;
#define MAX 100000;


void solve(int A[], int V[], int N){
	V[0] = A[0];
	for(i=1; i< N; i++) V[i] = A[i]+V[i-1];	
}

int main(int argc, char **argv){
	
	int V[MAX];
	int A[MAX];
	int N;
	
	cin>>N;
	for(int j=0; j<N; j++)cin>>A[i];
	
	solve(A, &V, N);

	for(int i=0; i < N; i++)cout<<V[i];

}