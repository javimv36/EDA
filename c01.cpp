/*
Implementa una funcion que cumpla la siguiente especi cacion:
{b >1^n >1}
fun log(intb,intn)
return int r
{b^r-1<n<=b^r}

Entrada

El primer n ́umero de la entrada indica el n ́umero de casos de prueba
que aparecer ́an a continuaci ́on.Cada caso de prueba consta de dos n ́umeros
que cumplen la precondici ́on descrita anteriormente.  Elprimer n ́umero
corresponde aby el segundo an.

Salida

Para cada caso de prueba se escribir ́a, en una l ́ınea diferente, el valorr
que cumple la postcondici ́on.

Entrada de ejemplo
6
3 10
5 25
5 124
5 125
2 2
2 18446744073709551615

Salida de ejemplo
3
2
3
3
1
64

Nota
El limite superior tanto para b y n es 2^64−1 por tanto usaunsigned long como
tipo de 64 bits para los enteros.
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
  int c; //casos a probar
  int b;
  int n;

  cin >> c;
  for (int i=0; i<c; i++){
    cin >> b;
    cin >> n;
    solve(b,n);
  }
  return 0;
}
