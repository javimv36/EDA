/*
3. (3,5 puntos) Se dispone de una lista de n productos alimenticios entre los que se quiere escoger algunos para seguir una dieta adecuada.

 Para cada producto i (0 ≤ i < n) se conoce
 su precio pi ≥ 0,
 su contenido en proteinas qi ≥ 0 y
 su cantidad de calorías ci ≥ 0.

Se desea seleccionar algunos de estos productos (a lo sumo uno de cada) de forma
que el precio total no supere un presupuesto M, el contenido proteico total sea
al menos de Q y el valor calórico sea lo menor posible.

 Diseñar un algoritmo de vuelta atrás para encontrar la selección óptima,
 es decir, la que minimiza la cantidad de calorías. Se valorarán las podas realizadas
*/
//Author Javi
#include <iostream>
#define MAX 10000
using namespace std;
bool esValida(int S[], int k, int precio)
void vueltaAtrasDieta(int P[], int T[], int C[],int &precio, int &proteinas, int &calorias, int M, int Q, int &minCalorias, int k, int n, bool S[], bool Smejor[]){
    for (int i=0; i<n; i++){
      sol[k]=true;
      if (esValida(S, k)){
        calorias+=C[i];
        precio+=P[i];
        proteinas+=T[i];
        if (proteinas>=Q){
          if(calorias < minCalorias){
            minCalorias=calorias;
            copiarSolucion(S, Smejor);
          }
          tratarSolucion();
        }else
          vueltaAtrasDieta()
      }
    }
  }

int main(int argc, char **args){

  return 0;
}
