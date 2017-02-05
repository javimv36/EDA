/*
Subvectores y recursi´on en C
Implementa una funci´on recursiva (en O(n)) que cumpla la siguiente especificaci´on:
{N ≥ 2}
fun farest(int V[], int N) return int d
{d = m´ax p, q : 0 ≤ p ≤ q < N : |V [p] − V [q]|}
Entrada
El primer n´umero de la entrada indica el n´umero de casos de prueba que aparecer´an a continuaci´on.
Cada caso de prueba consta de dos l´ıneas: en la primera se expresa el n´umero de componentes del vector
de entrada -cumpliendo la precondici´on N ≥ 2- y en la segunda, los componentes separados por espacio.
Salida
Para cada caso de prueba se escribir´a, en una l´ınea diferente, el valor d que cumple la postcondici´on.
Entrada de ejemplo
3
10
1 2 8 4 5 6 7 3 9 10
4
30 2 35 37
10
6 2 3 4 5 6 16 26 22 14
Salida de ejemplo
9
35
24
Nota
Preferible hacer recursi´on pr divisi´on, aunque se puede hacer por sustracci´on
*/
#include <iostream>
#define MAX 100000
using namespace std;

int solve(int V[], int N);

int main(int argc, char **args){
	int n;
	int N;
	int V[MAX];
	cin >> n;
	for(int i=0; i<n;i++){
		cin >> N;
		for (int j=0; j<N; j++){
			cin >> V[j];
		}
		cout << solve(V,N) << endl;
	}
	return 0;
}

int solve(int V[], int N){
	int min = (V[0]<V[1])?V[0]:V[1];
	int max = (V[0]>V[1])?V[0]:V[1];
	for(int i=2;i<N;i++){
		min=(min<V[i])?min:V[i];
		max=(max>V[i])?max:V[i];
	}
	return max-min;
}
