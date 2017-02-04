/*
Implementa una funcion que cumpla la siguiente especificacion:
{b >1^n >1}
fun log(int b,int n)
return int r
{b^r-1<n<=b^r}

Entrada

El primer numero de la entrada indica el numero de casos de prueba
que apareceran a continuacion.Cada caso de prueba consta de dos numeros
que cumplen la precondicion descrita anteriormente.  El primer numero
corresponde a b y el segundo a n.

Salida

Para cada caso de prueba se escribira, en una lınea diferente, el valor
que cumple la postcondicion.

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
#include <cmath>
using namespace std;
#define MAX 10000

unsigned long solve(unsigned long int b, unsigned long int n){
  unsigned long r;
  for (r=0; !((pow(b,r-1) < n) && (n <= pow(b,r))); r++);
  return r;
}

int main(int argc, char **argv)
{
  int c; //casos a probar
  unsigned long int b;
  unsigned long int n;
  cin >> c;
  for (int i=0; i<c; i++){
    cin >> b;
    cin >> n;
    cout << solve(b,n) << endl;
  }
  return 0;
}
