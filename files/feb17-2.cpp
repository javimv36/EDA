/*
Diseña e implementa un algoritmo recursivo que reciba un vector de longitud
0<=n<=1000 que se sabe creciente (no necesariamente estrictamente creciente)
y devielva si el vector es creciente por los pelos. Justifica el algoritmo implementado

Se valorara DYV

La entrada empieza con una linea que indica el numero de casos de pureba. Cada
caso de prueba tendrá el valor n y los elementos del vector y el programa
escribira SI si el vector es creciente por los pelos y NO en caso contrario

NOTA:
Un vector es CRECIENTE POR LOS PELOS cuando a demas de ser creciente, la
diferencia entre un elemento y el elemento siguiente es como mucho 1.

1 2 3 4 SI
1 2 2 3 SI
1 1 1 1 SI
1 2 1 3 NO
*/
#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;
#define DYV 0
#define DYVONELINE 1

#if DYV
  bool solve(int V[], int n){
    if (n==2)
      return((V[0]==V[1])||((V[0]+1)==V[1]));
    else if (n==3)
      return(((V[0]==V[1])||((V[0]+1)==V[1]))&&((V[1]==V[2])||((V[1]+1)==V[2])));
    else
      return ((solve(V,(n/2))) && (solve(V+(n/2), (n-(n/2)))));
  }
#elif DYVONELINE
  bool solve(int V[], int n){
    return ((n==2)?((V[0]==V[1])||((V[0]+1)==V[1])):((n==3)?(((V[0]==V[1])||((V[0]+1)==V[1]))&&((V[1]==V[2])||((V[1]+1)==V[2]))):((solve(V,(n/2))) && (solve(V+(n/2), (n-(n/2)))))));
  }
#endif

int main(){
  int c;
  int n;
  int V[MAX];
  cin >> c;
  for (int i=0; i<c;i++){
    cin >> n;
    for (int j=0; j<n; j++) cin >> V[j];
    cout << ((solve(V,n))?"SI":"NO") << endl;
  }


}
