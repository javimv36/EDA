/*
Funci´on Log
Implementa una funci´on que cumpla la siguiente especificaci´on:
{b > 1 ∧ n > 0}
fun log(int b, int n) return int r
{b^r ≤ n < b^r+1}
Entrada
El primer n´umero de la entrada indica el n´umero de casos de prueba que aparecer´an a continuaci´on.
Cada caso de prueba consta de dos n´umeros que cumplen la precondici´on descrita anteriormente. El
primer n´umero corresponde a b y el segundo a n.
Salida
Para cada caso de prueba se escribir´a, en una l´ınea diferente, el valor r que cumple la postcondici´on.
Entrada de ejemplo
5
3 10
5 25
5 124
5 125
2 1
Salida de ejemplo
2
2
2
3
0
Nota
Este ejercicio debe verse en el contexto de la asignatura de Estructura de Datos y Algoritmos (EDA),
FDI-UCM 2016/2017 (prof. Antonio S´anchez Ruiz-Granados). Por tanto no vale cualquier soluci´on,
sino s´olo aquellas que utilicen los conceptos de EDA. Es muy posible que se den aclaraciones adicionales
en clase a este respecto.
*/

//Author Javi
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX 10000

unsigned long int solve(unsigned long int b, unsigned long int n){
  unsigned long int r;
  for (r=0; !((pow(b,r) <= n) && (n < pow(b,r+1))); r++);
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
