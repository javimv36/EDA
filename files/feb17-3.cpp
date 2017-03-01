/*
Ejercicio 3 - Escribe una función para generar vectores crecientes por los pelos d-divertidos
En concreto, la función recibirá el tamaño del vector 0<=n<=1000, el valor de d>0 y el valor
para el primer elemento del vector y generará la salida en orden lexiogáfico. Se admite el uso
de funciones auxiliares.

La entrada comienza con una linea que contiene el numero de casos de prueba.La entrada contendrá
los valores de n, d y e. El programa escribirá en lineas separadas cada uno de los vectores del
resultado, con los elementos separados por un espacio.

NOTA:
Un vector es CRECIENTE POR LOS PELOS cuando a demas de ser creciente, la
diferencia entre un elemento y el elemento siguiente es como mucho 1.

1 2 3 4 SI
1 2 2 3 SI
1 1 1 1 SI
1 2 1 3 NO

Un vector es aburrido si los elementos aparecen muchas veces. Y es D-DIVERTIDO si ningun
elemento se repite mas de D-veces
Ejemplos:
  1-divertido
    1 2 3 4
    4 3 7 0
  3-divertido
    6 7 6 6
  2-divertido
    7 3 7 3
    7 3 7 0
  4-divertido
    9 9 9 9

*/
void tratarSolucion(int S[], int n){
  for (int i = 0; i<n; i++) cout << S[i];
  cout << endl;
}
//inicializando marcas con todo ceros (ningun numero se ha cogido)
void solve(int n, int d, int e, int S[], int k, int marcas[]){
    for (int i=e;i<e+n; i++){
      if(marcas[i]<d){
        S[k]=i;
        if((S[k]==S[k-1]||S[k]==S[k-1]+1)&&){ //si el elemento es igual o solo 1 mayor
          if(k==n-1){
            tratarSolucion(S,n);
          }
          else {
            marcas[i]+=1;
            solve(n,d,e,S,k+1,marcas);
            marcas[i]-=1;
          }
        }
      }
    }
}

int main(){
  int S[MAX];
  int n;
  int d;
  int e;
  int marcas[MAX];//inicializado todo a cero (no hemos cogido elementos)
  cin << n;
  cin << d;
  cin << e;
  S[0]=e; //cogemos el primero
  marcas[0]+=1; //marcamos que ya lo hemos cogido una vez
  solve(n,d,e,S,1,marcas);
}
