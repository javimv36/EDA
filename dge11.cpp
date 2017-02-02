/*
Encuentra la  ́ultima posici ́on de equilibrio

Implementa una funci ́on que resuelva el siguiente problemaa:

P≡{n≥0}funxxxx(inta[],intn)return intp
Q≡{(−1≤p < n)∧numUnos(a, p) =numCeros(a, p)∧∀u:p < u < n:numU nos(a, u)6=numCeros(a, u)}
dondenumUnos(a, x)≡#u: 0≤u≤x:a[u] = 1 ynumUnos(a, x)≡#u: 0≤u≤x:a[u] = 0.

Requisitos de implementaci ́on.Indicar el coste de la soluci ́on obtenida.
La  funci ́on  que  resuelve  el  problema  debe  recibir  los  datos  en  un
vector  y  devolver  el  valor  de  laposici ́on (observad que puede ser -1).

Entrada


La entrada comienza con el n ́umero de casos de prueba.  Cada caso de prueba
tiene dos l ́ıneas.  En laprimera l ́ınea se indica el tama ̃no del vector, en
la segunda los valores separados por blancos.

Salida

Para cada caso de prueba se escribe en una l ́ınea el valor de la posici ́on
pedida.  Si el tama ̃no delvector es cero la posici ́on debe ser -1.

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
#include <algorithm>
using namespace std;
#define MAX 10000

void solve(unsigned long b, unsigned log n){

}

int main(int argc, char **argv)
{
  int N;
  int n;
  int V[MAX];
  cin >> N;
  for (int i=0; i<N; i++){
    cin >> n;
    for (int j=0; j<n; j++){
      cin >> V[j];
      solve(V,n);
    }
  }
  return 0;
}
