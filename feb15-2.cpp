/*
2. (3 puntos) La imagen especular de un número natural es el número que resulta
al invertir el orden de sus dígitos.
Por ejemplo, la imagen especular de 13492 es 29431 y la imagen especular del 1000 es el 1.

 Implementa dos algoritmos recursivos, uno final y otro no final, que calculen la
 imagen especular de un número natural representado como unsigned int.
 Indicar la llamada inicial a cada algoritmo con los valores iniciales de cada parámetro.
 Justica el coste de cada algoritmo.

 NOTA: Ten en cuenta que no se pide la especicación, ni la derivación / vericación formal de los algoritmos.

*/
//Author Javi
#include <iostream>
using namespace std;

// RECURSIVO FINAL
int solve(unsigned int n, unsigned int resultado){
  return (n<10)?(10*resultado + n):(solve(n/10, (10*resultado+n%10)));
}
/*
pseudo-code
fun solve(n, resultado){
  if n<10
    dev 10*resultado+n
  else
    dev solve(n/10, (10*resultado+n%10))
}
*/

int main(int argc, char **args){
  unsigned int n;
  cin >> n;
  cout << solve(n,0) << endl;
  return 0;
}
